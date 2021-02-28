#include "thezoo.h"

using namespace std;

std::vector<Animal*> animals;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

/**
 * Adds new animal to animals vector
 */
void AddAnimal()
{
	/**
	 * Build menu usinsg R strings
	 */
	std::string addAnimalMenu = R"(
+----------------------------------------+
|      Wildlife Zoo Add Animal Menu      |
+----------------------------------------+
|    1. Add Croodile                     |
|    2. Add Goose                        |
|    3. Add Pelican                      |
|    4. Add Bat                          |
|    5. Add Whale                        |
|    6. Add SeaLion                      |
|    X. Exit: Return to Main Menu        |
+----------------------------------------+
Please select your choice and press Enter: )";


	/**
	 * Declare map to associate user input to specific data needed per animal
	 */
	std::map<std::string, std::map<std::string, std::string>> animalMap {
		{"1",{{"type","Oviparous"},{"subType","Crocodile"}}},
		{"2",{{"type","Oviparous"},{"subType","Goose"}}},
		{"3",{{"type","Oviparous"},{"subType","Pelican"}}},
		{"4",{{"type","Mammal"},{"subType","Bat"}}},
		{"5",{{"type","Mammal"},{"subType","Whale"}}},
		{"6",{{"type","Mammal"},{"subType","SeaLion"}}}
	};

	std::string menuChoice;						// variable to capture user input
	std::stringstream ss;						// stringstream used for format string and int data
	int trackNum;								// variable to hold working tracking number
	std::string name;							// variable to hold working animal name
	int eggs = 0;								// variable to hold number of eggs animal has
	int nurse = 0;								// variable to tell if animal is nersing {yes = 1, no = 0}
	Animal* newAnimal;							// variable to hold animal object to add to "global" animals vector
	bool invalidMenuChoice;						// variable to control while loop

	invalidMenuChoice = true;					// set loop control variable so while loop will run
	while(invalidMenuChoice){					// run while loop to display menu and get user data
		invalidMenuChoice = false;				// clear loop control variable to exit loop next run unless set again

		std::cout << addAnimalMenu;				// output menu to console
		std::cin >> menuChoice;					// get userChoice

		if(menuChoice.length() == 0)  { menuChoice.append(" "); }	// make sure menuChoice string is at least 1 char long
		menuChoice = menuChoice.substr(0,1);	// get first character from user input

		if ((menuChoice == "x") || (menuChoice == "X")){			// check to see if user wants to exit
			return;													// if so; return back to caller
		}

		if (animalMap.find(menuChoice) == animalMap.end()) {		// check to see if user choice is not in map
			std::cout << "INVALID Selection: Please choose again!" << std::endl;	// it isn't so cout message to user
			invalidMenuChoice = true;								// set loop control variable so that loop will repeat
		}
	}

	trackNum = GetAnimalTrackNum();				// set working tracking number variable. Function handles user interaction.
	name = GetAnimalName();						// set working name variable. Function handles user interaction.

	(animalMap[menuChoice]["type"] == "Oviparous") ?				// eggs and nurse set to 0 by default.
			eggs = GetAnimalEggsOrNursingInfo(animalMap[menuChoice]["type"]):	// Animal is oviparous so ask user how many eggs
			nurse = GetAnimalEggsOrNursingInfo(animalMap[menuChoice]["type"]);	// Animal is no oviparous so ask user if nursing

	newAnimal = MakeNewAnimal(trackNum, name, animalMap[menuChoice]["type"],	// Get new animal of user chosen type
							  animalMap[menuChoice]["subType"], eggs, nurse);

	PrintAnimalDisplayTitle();					// cout animal display title
	PrintAnimalDisplayLine(newAnimal);			// cout new animal information

	std::cout << "Enter 'S' to save, anything else to abort: ";		// cout user message to make choice
	std::string userResponse;					// declare string variable to get user response
	getline(std::cin, userResponse);			// get response from user
	if(userResponse.length() == 0) { userResponse.append(" "); }	// make sure user response is at least one char long
	if ((userResponse.at(0) != 'S') && (userResponse.at(0) != 's')) {			// did user not input upper or lower case 's'
		delete newAnimal;						// user enter something other than upper or lower case s, so delete animal
		std::cout << "Add Animal aborted by user." << std::endl;	// send status message to user
		return;									// exit method
	}

	animals.push_back(newAnimal);				// user wants to add this record to memory, so add it to back of vector
	std::cout << "Add Animal successful." << std::endl;				// send status message to user

}

/**
 * Creates new animal object
 */
Animal* MakeNewAnimal(int t_trackNum, std::string t_name, std::string t_type,
				std::string t_subType, int t_eggs, int t_nurse) {
	/**
	 * Declare map to use switch to create appropriate animal subtype
	 */
	std::map<std::string, int> animalObjectMap {
		{"Crocodile",0},
		{"Goose",1},
		{"Pelican",2},
		{"Bat",3},
		{"Whale",4},
		{"SeaLion",5}
	};

    Animal* newAnimal;							// Variable pointer to point to an Animal

    switch(animalObjectMap[t_subType]) {		// use t_subType as map key to select which animal to create
	case 0:
		newAnimal = new Crocodile(t_trackNum, t_name, t_eggs);
		break;
	case 1:
		newAnimal = new Goose(t_trackNum, t_name, t_eggs);
		break;
	case 2:
		newAnimal = new Pelican(t_trackNum, t_name, t_eggs);
		break;
	case 3:
		newAnimal = new Bat(t_trackNum, t_name, t_nurse);
		break;
	case 4:
		newAnimal = new Whale(t_trackNum, t_name, t_nurse);
		break;
	case 5:
		newAnimal = new SeaLion(t_trackNum, t_name, t_nurse);
		break;
	}
    return newAnimal;							// return pointer to newly created animal
}

/**
 * Prints a formatted report title to console
 */
void PrintAnimalDisplayTitle() {
	/**
	 * Create Report Title using R strings
	 */
	std::string animalDisplayTitle = R"(
+--------+-----------------+-----------------+-----------------+-------+-------+
| Track# | Name            | Type            | SubType         | Eggs  | Nurse |
+--------+-----------------+-----------------+-----------------+-------+-------+
)";

	std::cout << animalDisplayTitle;			// cout report title

}

/**
 * Prints a formatted data item line and bottom border to console
 */
void PrintAnimalDisplayLine(Animal* t_Animal) {
	std::stringstream ss;						// stringstream to format data
	std::string infoString = t_Animal->getInfo();	// store animal info to working variable
	int infoInteger;							// working integer for integer conversion

	ss << infoString.substr(51,infoString.length() - 51);	// read integer portion of data into stringstram
	ss >> infoInteger;							// output stringstream to integer for Eggs/Nurse data

	std::cout << std::setfill(' ');				// set fill char to space for formatted output string

	std::cout << "| " << infoString.substr(0,6);	// output left border and tracking number
	std::cout << " | " << infoString.substr(6,15);	// output left divider and animal name
	std::cout << " | " << infoString.substr(21,15);	// output left divider and animal type
	std::cout << " | " << infoString.substr(36,15);	// output left divider and animal subType

	infoString = infoString.substr(21,15);			// reduce data string to animal type section
	ss.clear();										// clear any stream flags
	ss.flush();										// flush stream
	ss.sync();										// sync stream
	ss << infoString;								// put reduced data string into stringstream
	std::getline(ss, infoString, ' ');				// get first word from stream
	ss.clear();										// clear any stream flags
	ss.flush();										// flush stream
	ss.sync();										// sync stream

	if (infoString == "Oviparous") {				// if animal type is oviparous, integer is #eggs and nurse = 0
		std::cout << " | " << setw(5) << infoInteger;				// output left divider and nuber of eggs
		std::cout << " | " << setw(5) << 0 << " |" << std::endl;	// output left divider, 0, and right border
	}
	if (infoString == "Mammal") {					// if animal type is mammal, integer is for nursing and #eggs = 0
		std::cout << " | " << setw(5) << 0;			// cout left divider and 0
		std::cout << " | " << setw(5) << infoInteger << " |" << std::endl;	// cout left divider, integer, and right border
	}
	std::string animalDisplayLine =					// R string for linettme seperation line
R"(+--------+-----------------+-----------------+-----------------+-------+-------+
)";
	std::cout << animalDisplayLine;					// cout lineitem seperation line
}

/**
 * Asks user for a tracking number
 */
int GetAnimalTrackNum() {
	bool continueToLoop;						// loop control variable
	std::string userResponse;					// string to capture user response
	stringstream ss;							// stringstream to manipulate string data
	int trackNum;								// integer to hold tracking number

	continueToLoop = true;						// set loop control variable so while loop code will run
	while (continueToLoop) {					// loop until continueToLoop is false
		try {									// try block
			ss.clear();							// clear any stream flags
			ss.flush();							// flush stream
			ss.sync();							// sync stream

			std::cin.clear();					// clear any cin flags
			std::cin.sync();					// sync cin

			std::cout << "Enter tracking number: ";	// ask user to enter tracking number
			getline(std::cin, userResponse);	// capture user input into userResponse

			ss.str(userResponse);				// assign user response string to string stream
			ss >> trackNum;						// out stream to trackNum integer

			if(trackNum > TRACKING_NUMBER_MAX) {	// see if number to lareg
				throw std::runtime_error("Number too Hi");	// number too large, throw error
			}
			if(trackNum < TRACKING_NUMBER_MIN) {	// see if number to low
				throw std::runtime_error("Number too Lo");	// nuber too low, throw error
			}


			continueToLoop = false;				// if getting here no error was thrown set loop control variable false
		} catch (const exception& e) {			// catch any error thrown

			std::cout << "GetAnimalTrackNum::" << e.what() << std::endl;			// output error info to user

			std::cout << "Please Enter a different Tracking Number: " << std::endl;	// send continue message to user
		}
	}
	return trackNum;							// return tracknum
}

/**
 * Ask user for animal name
 */
std::string GetAnimalName() {
	std::string animalName;						// variable to hold animal name
	bool continueLooping ;						// looping control variable

	continueLooping = true;						// set looping control variable so loop will run
	while(continueLooping) {					// loop to get animal name from user
		std::cout << "Please Enter the new animal's name: ";	// ask user for input
		getline(std::cin, animalName);			// get user input

		try {
			if (animalName.length() > NAME_LENGTH_MAX) {	// throw error if name is too long
				throw ANIMAL_ERROR::NAME_TOO_LONG;
			}
			if (animalName.length() < NAME_LENGTH_MIN) {	// thow error if name is to short
				throw ANIMAL_ERROR::NAME_TOO_SHORT;
			}
			continueLooping = false;				// no error trhown so clear looping control variable to exit loop
		} catch (int thrownError){
			continueLooping = true;
			switch(thrownError){
			case ANIMAL_ERROR::NAME_TOO_LONG:	// catch and explain error
				std::cerr << "Name is too long." << std::endl;
				std::cerr << "Maximum name length is " << NAME_LENGTH_MAX << " characters." << std::endl;
				break;
			case ANIMAL_ERROR::NAME_TOO_SHORT:	// catch and explain error
				std::cerr << "Name is too short." << std::endl;
				std::cerr << "Minimum name length is " << NAME_LENGTH_MIN << " characters." << std::endl;
				break;
			default:							// unknow error
				std::cerr << "Unknown Error in Animal::setName" << std::endl;
				break;
			}

			std::cout << "Please Enter a different Animal Name: " << std::endl;		// ask user for new input
		}
	}
	return animalName;
}

/**
 * convert input string to lower case letters
 */
std::string ToLowerCase(std::string t_inputString){
	std::string lowerCaseString;				// working variable

	lowerCaseString = t_inputString;			// save inptu string to working variable
	transform(lowerCaseString.begin(), lowerCaseString.end(),
			lowerCaseString.begin(), ::tolower);	// convert each char in string to lower case

	return lowerCaseString;						// return lower case string
}

/**
 * Gets integer value for eggs or nurse depending on animal type
 */
int GetAnimalEggsOrNursingInfo (std::string t_animalType) {
	int eggsOrNursingInfo;						// working variable and return value
	bool isMammal = (t_animalType == "Mammal");	// decision variable set if animal is mammal
	bool validEggsOrNursingInfo = false;		// loop control variable
	std::stringstream ss;						// stringstream to format user input
	std::string userResponse;					// string to capture user input

	while(!validEggsOrNursingInfo) {			// reun loop until vailidEggsOrNursingInfo is set
		if(isMammal) {							// if this is a mammal, output mammal string
			std::cout << "Enter 1 for nursing or 0 for not nursing: " << std::endl;
		}
		if(!isMammal) {							// if this is not a mammal output oviparous string
			std::cout << "Enter the number of eggs the oviparous has: " << std::endl;
		}
		getline(std::cin, userResponse);		// get response from user
		ss << userResponse;						// put users response in stringstream
		ss >> eggsOrNursingInfo;				// assing return variable the integer in ss
		try {									// error checkingng for propper range of values
			if(isMammal && ((0 > eggsOrNursingInfo) || (eggsOrNursingInfo > 1))) {
				throw std::runtime_error("Mammal nursing must be either 1 or 0.");
			}
			if(!isMammal && (0 > eggsOrNursingInfo)) {
				throw std::runtime_error("Oviparous number of eggs cannot be less than 0.");
			}
			ss.clear();
			ss.flush();
			ss.sync();
			ss << std::endl;
			std::getline(ss, userResponse);		// clear ss stream
			ss.clear();
			ss.flush();
			ss.sync();
			if (userResponse.length() > 0) {	// if something was still in ss, then error
				throw std::runtime_error("INVALID INPUT!");
			}
			validEggsOrNursingInfo = true;		// only get here i no error thrown, set loop exit control
		} catch (const std::exception& e) {
			std::cout << "ERROR: " << e.what() << std::endl;	// if error print erro message
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Please Enter your number again.";		// mesage user
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}

	return eggsOrNursingInfo;					// return integer value
}

/**
 * Removes animal form animals vector in memory
 */
void RemoveAnimal()
{
	/**
	 * R string for menu
	 */
	std::string displayMenu = R"(
+----------------------------------------+
|      Wildlife Remove Record Menu       |
+----------------------------------------+
|    1. Remove record by Tracking #      |
|    2. Remove record by name.           |
|    X. Exit: Return to Main Menu        |
+----------------------------------------+
Please select your choice and press Enter: )";

	/**
	 * map for valid user menu choice
	 */
	std::map<std::string, int> menuMap {
		{"1",1},
		{"2",2},
		{"X",0},
		{"x",0}
	};

	/**
	 * map to use in casting animal switch/case structure
	 */
	std::map<std::string, int> animalSubTypeMap {
		{"Crocodile",1},
		{"Goose",2},
		{"Pelican",3},
		{"Bat",4},
		{"Whale",5},
		{"SeaLion",6},
	};
	std::stringstream ss;						// stringsteam for formatting user input
	bool invalidMenuChoice;						// loop control variable
	std::string userInput;						// working variable to capture user raw input
	int recordTrackNum = 0;						// int for record tracking number
	int searchTrackNum = 0;						// int for search tracking number
	std::string recordName = "";				// string for record name
	std::string searchName = "";				// string fro search name
	Animal* record;

	while(true){								// Always run, exits is done by break or return is exit is chosse

		invalidMenuChoice = true;				// initialize loop control variable to run loop
		while(invalidMenuChoice) {
			std::cout << displayMenu << std:: endl;	// display menu to user
			getline(cin,userInput);				// get user response

			if(userInput.length() == 0) { userInput.append(" "); }	// ensure input is at least one char long
			userInput = userInput.substr(0,1);	// reduce user input to first char

			if(menuMap.find(userInput) != menuMap.end()) {	// if valid user choice was found
				invalidMenuChoice = false; 		// clear loop contorl variable to exit loop
			}
			if(invalidMenuChoice) {				// if invalid choic message user, clear input, loop again
				std::cout << "INVALID Selection: Please choose again!" << std::endl;
				userInput = "";
			}
		}

		switch(menuMap[userInput]){				// switch on integer chosen by menu map
		case 0:									// Exit "X" or "x" exits the program
			return;
			break;
		case 1:									// "1" Choose animal to remove by trackin number
			searchTrackNum = GetAnimalTrackNum();	// get tracking number of animal to remove
			break;
		case 2:									// "2" Choose animal to remove by name
			searchName = GetAnimalName();		// get name of animal to remove
			searchName = ToLowerCase(searchName);	// convert name to lower case for comparison
			break;
		}

		std::string animalSubType;				// working variable to hold animal subtype
		std::string animalInfoString;			// working variable to hold animal info string
		Crocodile* crocodile;					// animal subtype objects to cast to from record
		Goose* goose;
		Pelican* pelican;
		Bat* bat;
		Whale* whale;
		SeaLion* sealion;

		PrintAnimalDisplayTitle();				// print report header
		for(std::size_t i = 0; i <  animals.size();) {	// loop through animals vector
			bool found = false;					// initialize control bool
			bool remove = false;				// initialize control bool

			record = animals.at(i);				// assign current animal in vector to record

			switch(menuMap[userInput]){			// process menuChoice TrackNum or Name
			case 1:								// Remove record by tracking number
				recordTrackNum = record->getTrackNum();	// get tracking number from record
				if(recordTrackNum == searchTrackNum) { found = true; }	// if same set found
				break;
			case 2:								// Remove record by name
				recordName = record->getName();	// get name from record
				recordName = ToLowerCase(recordName);	// convert to lowercase for comparison
				recordName = recordName.substr(0,searchName.length());	//reduce record string size of search string
				found = (recordName == searchName) ? true : false;	// if same set found
				break;
			}

			if(found) {							// if matching record found
				PrintAnimalDisplayLine(record);	// display the found record
				std::cout << "ENTER \"Y\" to Delete this record: " << std::endl; // message user
				std::string answer;				// make  working variable for user's answer
				std::getline(std::cin, answer);	// get user's answer
				answer = (answer.length() > 0) ? answer.substr(0,1) : " ";	// make sure answer is at least one char long
				if ((answer == "Y") || (answer == "y")) {	// check for either y
					remove = true;				// set remove confirmation variable

					animalInfoString = record->getInfo();				// get record info string
					animalInfoString = animalInfoString.substr(36,15);	// get animal sub type section of substring
					ss << animalSubType << std::endl;					// put sub type into ss stram
					animalSubType = "";
					std::getline(ss, animalSubType,' ');				// put first word in ss into animalSubType string

					switch(animalSubTypeMap[animalSubType]) {
					// using find correct subytpe animal and cast current animal to it, then delete the animal from the heap
					case 1:
						crocodile = static_cast<Crocodile*>(animals[i]);
						delete crocodile;
						break;
					case 2:
						goose = static_cast<Goose*>(animals[i]);
						delete goose;
						break;
					case 3:
						pelican = static_cast<Pelican*>(animals[i]);
						delete pelican;
						break;
					case 4:
						bat = static_cast<Bat*>(animals[i]);
						delete bat;
						break;
					case 5:
						whale = static_cast<Whale*>(animals[i]);
						delete whale;
						break;
					case 6:
						sealion = static_cast<SeaLion*>(animals[i]);
						delete sealion;
						break;
					}

					std::getline(ss,animalSubType);						// clear ss stream
					animalSubType = "";
					ss.clear();
					ss.flush();
					ss.sync();

					animals.erase(animals.begin() + i);					// remove the aniamal from the vector

					std::cout << std::endl << std::endl;
					std::cout << "Record Removed from memory.";			// send user message
					std::cout << std::endl << std::endl;
				}
				if (!remove) {											// if choice was to not remove
					std::cout << std::endl << std::endl;
					std::cout << "Record not Removed.";					// send user message
					std::cout << std::endl << std::endl;
				}
			}
			if (!remove) { ++i; }										// only increment i when a record is not removed
		}
	}
}

/**
 * Loads data from file zoodata.txt in same director
 */
void LoadDataFromFile()
{
	/**
	 * make map of data location in info string keyed on field name
	 */
	std::map<std::string,std::map<std::string,int>> Data {
		{"trackNum",{{"start",0},{"size",6}}},
		{"name",{{"start",6},{"size",15}}},
		{"type",{{"start",21},{"size",15}}},
		{"subType",{{"start",36},{"size",15}}},
		{"eggs",{{"start",51},{"size",0}}}
	};

	/**
	 * make map to match animal subtype to an integer to use in switch/case structure
	 */
	std::map<std::string, int> AnimalObjectMap {
		{"Crocodile",0},
		{"Goose",1},
		{"Pelican",2},
		{"Bat",3},
		{"Whale",4},
		{"SeaLion",5}
	};

	Animal* animal;								// declare Animal object pointer

	std::ifstream inFS;							// declare input file stream
	std::stringstream ss;						// declare string stream
	std::string fileName;						// working variable for fileName
	std::string animalDataString;				// working variable for anima data string
	std::string field;							// working variable for field string
	int trackNum;								// working variable for tracking number
	std::string name;							// working variable for animal name
	std::string type;							// working variable for animal type
	std::string subType;						// working variable for aimal subtype
	int eggs;									// working variable for animal eggs
	int nurse;									// working variable for nursing info

	if (animals.size() > 0) {					// see if animals vector already has data
		std::cout << std::endl << std::endl;
		std::cout << "Record Data already loaded, cannot load data again.";  // if so send message
		std::cout << std::endl << std::endl;

		return;									// exit function because vector already has data
	}

	fileName = "zoodata.txt";					// assign filename
	inFS.open(fileName);						// open file with filestream
	while(!inFS.eof()){							// run loop as long as not at end of file
		std::getline(inFS, animalDataString);	// get line of data from file
		if (animalDataString.length() < 51) {	// if the line is not at least this long, then not valid
			break;								// we have reached the end of the record in file so exit loop
		}

		field = "trackNum";						// load field data from string position into string stream
		ss << animalDataString.substr(Data[field]["start"],Data[field]["size"]) << std::endl;
		field = "name";							// load field data from string position into string stream
		ss << animalDataString.substr(Data[field]["start"],Data[field]["size"]) << std::endl;
		field = "type";							// load field data from string position into string stream
		ss << animalDataString.substr(Data[field]["start"],Data[field]["size"]) << std::endl;
		field = "subType";						// load field data from string position into string stream
		ss << animalDataString.substr(Data[field]["start"],Data[field]["size"]) << std::endl;
		ss >> trackNum >> name >> type >> subType;	// assign data in ss to working variables
		field = "eggs";							// load field data from string position into string stream
		Data[field]["size"] = animalDataString.length() - Data[field]["start"];	// rduce string to end with 2 ints
		animalDataString = animalDataString.substr(Data[field]["start"],Data[field]["size"]);
		ss.str(animalDataString);				// make the string the ss input
		ss >> eggs >> nurse;					// output from ss the two integer values

		animal = MakeNewAnimal(trackNum, name, type, subType, eggs, nurse);	// get new animal
		animals.push_back(animal);				// put animal in animals vector

		ss.str("/n");							// clean string and ss
		std::getline(ss, animalDataString);
		ss.clear();
		ss.flush();
		ss.sync();

	}

	inFS.close();								// close file
												// send user message
	std::cout << "Successfully loaded " << animals.size() << " animals from data file." << std::endl;

}

/**
 * Saves records currently in vector to file zoofata.txt by overwriting file
 */
void SaveDataToFile()
{
	std::ofstream OUTfs ("zoodata.txt", std::ofstream::out);	// open output file

	for(const auto& record: animals) {			// loop through each reacord in animals vector
		OUTfs << record->getInfo() << std::endl;// write each animal info into file
	}

	std::cout << std::endl << std::endl;
	std::cout << "Data Saved to file.";			// output user message
	std::cout << std::endl << std::endl;
}

void DisplayAnimalData()
{
	std::string displayMenu = R"(
+----------------------------------------+
|         Wildlife Display Menu          |
+----------------------------------------+
|    1. Display all animal data          |
|    2. Display animal data by track #   |
|    3. Display animal data by name      |
|    X. Exit: Return to Main Menu        |
+----------------------------------------+
Please select your choice and press Enter: )";

	std::map<std::string, int> menuMap {
		{"1",1},
		{"2",2},
		{"3",3},
		{"X",0},
		{"x",0}
	};
	bool invalidMenuChoice;
	std::string userInput;
	int recordTrackNum = 0;
	int searchTrackNum = 0;
	std::string recordName = "";
	std::string searchName = "";

	while(true){

		invalidMenuChoice = true;
		while(invalidMenuChoice) {
			std::cout << displayMenu << std:: endl;
			getline(cin,userInput);

			userInput.append(" ");
			userInput = userInput.substr(0,1);

			if(menuMap.find(userInput) != menuMap.end()) {
				break;
			}
			std::cout << "INVALID Selection: Please choose again!" << std::endl;
			userInput = "";
		}

		switch(menuMap[userInput]){
		case 0:
			return;
			break;
		case 1:
			break;
		case 2:
			searchTrackNum = GetAnimalTrackNum();
			break;
		case 3:
			searchName = GetAnimalName();
			searchName = ToLowerCase(searchName);
			break;
		}

		PrintAnimalDisplayTitle();

		for(const auto& record: animals) {
			bool print = false;
			switch(menuMap[userInput]){
			case 1:
				print = true;
				break;
			case 2:
				print = (recordTrackNum == searchTrackNum) ? true : false;
				break;
			case 3:
				recordName = record->getName();
				recordName = ToLowerCase(recordName);
				recordName = recordName.substr(0,searchName.length());
				print = (recordName == searchName) ? true : false;
				break;
			}

			if(print) { PrintAnimalDisplayLine(record); }
		}
	}
}

/**
 * displays main menu
 */
void DisplayMenu()
{
	/**
	 * map menu useing R strings
	 */
	std::string wildlifeZooMenu = R"(
+----------------------------------------+
|        Wildlife Zoo Command Menu       |
+----------------------------------------+
|    1. Load Animal Data                 |
|    2. Generate Data                    |
|    3. Display Animal Data              |
|    4. Add Record                       |
|    5. Delete Record                    |
|    6. Save Animal Data                 |
|    X. Exit Wildlife Zoo Application    |
+----------------------------------------+
Please select your choice and press Enter: )";

	std::cout << wildlifeZooMenu << std::endl;	// output menu
}

/**
 * Main function
 */
int main()
{
	bool continueLooping = true;				// looping control varialbe
	std::string inputBuffer;					// string variable for user input
	char inputChar;								// char for switch menu

	while (continueLooping) {					// continue loop set to true by default
		inputChar = ' ';						// assign some data to inputChar
		inputBuffer = "";						// put empty string in buffer

		std::cin.clear();						// clear cin flags
		std::cin.sync();						// sync cin

		DisplayMenu();							// diaplsy main user menu
		std::getline(std::cin, inputBuffer);	// get user response
		if (inputBuffer.length() == 0){			// make sure response is at least one char long
			inputBuffer.append(" ");
		}

		inputChar = inputBuffer.at(0);			// get first char of user response

		switch(inputChar) {						// call next function based on first char of user response
		case '1':
			LoadDataFromFile();
			break;
		case '2':
			GenerateData();
			break;
		case '3':
			DisplayAnimalData();
			break;
		case '4':
			AddAnimal();
			break;
		case '5':
			RemoveAnimal();
			break;
		case '6':
			SaveDataToFile();
			break;
		case 'X':
		case 'x':
			continueLooping = false;			// user wants to exit, so clear loop control variable
			std::cout << "Exiting Wildlife Zoo Application." << std::endl;	// sen user message
			break;
		default:									// if here then the first char was not a valed menu choice
			std::cout << "Invalid option chosen. Please select from menu." << std::endl;
			break;
		}
	}

	return 1;
}
