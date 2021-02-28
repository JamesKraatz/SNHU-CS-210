/*
 * Tests.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1948462_snhu
 */

#include "tests.h"

void testAll() {
	testAnimal();
	testOviparous();
	testMammal();
	testCrocodile();
	testGoose();
	testPelican();
	testBat();
	testWhale();
	testSeaLion();
	return;
}

void testAnimal() {
	std::cout << "Testing Class Animal:" << std::endl;

	Animal *testAnimal = new Animal();

	std::string name;
	std::string info;

	info = testAnimal->getInfo();

	std::cout << "Animal info: " << info << std::endl;
	std::cout << "char length of Animal info: " << info.length() << std::endl;

	testAnimal->setName("Test");
	testAnimal->setTrackNum(1);

	info = testAnimal->getInfo();

	std::cout << "Animal info: " << info << std::endl;
	std::cout << "char length of Animal info: " << info.length() << std::endl;

	delete testAnimal;

	std::string inputString = "test2";
	int inputInteger = 2;

	testAnimal = new Animal(inputInteger, inputString);

	info = testAnimal->getInfo();

	std::cout << "Animal info: " << info << std::endl;
	std::cout << "char length of Animal info: " << info.length() << std::endl;

	std::cout << "Finished testing Class Animal." << std::endl << std::endl;
}

void testOviparous() {
	std::cout << "Testing Class Oviparous: " << std::endl;
	Oviparous* testSubject;

	testSubject = new Oviparous();
	std::cout << testSubject->getInfo() << std::endl;
	std::cout << "char length Oviparous info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNumberOfEggs(5);

	std::cout << testSubject->getInfo() << std::endl;
	std::cout << "char length Oviparous info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new Oviparous(2, "useConst2", 9);

	std::cout << testSubject->getInfo() << std::endl;
	std::cout << "char length Oviparous info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class Oviparous" << std::endl << std::endl;
}

void testMammal() {
	std::cout << "Testing Class Mammal: " << std::endl;
	Mammal* testSubject;

	testSubject = new Mammal();
	std::cout << testSubject->getInfo() << std::endl;
	std::cout << "char length Mammal info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNurse(1);

	std::cout << testSubject->getInfo() << std::endl;
	std::cout << "char length Mammal info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new Mammal(2, "useConst2", 1);

	std::cout << testSubject->getInfo() << std::endl;
	std::cout << "char length Mammal info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class Mammal" << std::endl << std::endl;
}

void testCrocodile() {
	std::cout << "Testing Class Crocodile: " << std::endl;
	Crocodile* testSubject;

	testSubject = new Crocodile();
	std::cout << "Crocodile::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Crocodile info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNumberOfEggs(5);

	std::cout << "Crocodile::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Crocodile info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new Crocodile(2, "useConst2", 9);

	std::cout << "Crocodile::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Crocodile info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class Crocodile" << std::endl << std::endl;
}

void testGoose() {
	std::cout << "Testing Class Goose: " << std::endl;
	Goose* testSubject;

	testSubject = new Goose();
	std::cout << "Goose::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Goose info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNumberOfEggs(5);

	std::cout << "Goose::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Goose info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new Goose(2, "useConst2", 9);

	std::cout << "Goose::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Goose info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class Goose" << std::endl << std::endl;
}

void testPelican() {
	std::cout << "Testing Class Pelican: " << std::endl;
	Pelican* testSubject;

	testSubject = new Pelican();
	std::cout << "Pelican::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Pelican info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNumberOfEggs(5);

	std::cout << "Pelican::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Pelican info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new Pelican(2, "useConst2", 9);

	std::cout << "Pelican::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Pelican info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class Pelican" << std::endl << std::endl;
}

void testBat() {
	std::cout << "Testing Class Bat: " << std::endl;
	Bat* testSubject;

	testSubject = new Bat();
	std::cout << "Bat::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Bat info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNurse(1);

	std::cout << "Bat::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Bat info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new Bat(2, "useConst2", 1);

	std::cout << "Bat::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Bat info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class Bat" << std::endl << std::endl;
}

void testWhale() {
	std::cout << "Testing Class Whale: " << std::endl;
	Whale* testSubject;

	testSubject = new Whale();
	std::cout << "Whale::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Whale info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNurse(1);

	std::cout << "Whale::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Whale info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new Whale(2, "useConst2", 1);

	std::cout << "Whale::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length Whale info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class Whale" << std::endl << std::endl;
}

void testSeaLion() {
	std::cout << "Testing Class SeaLion: " << std::endl;
	SeaLion* testSubject;

	testSubject = new SeaLion();
	std::cout << "SeaLion::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length SeaLion info: " << testSubject->getInfo().length() << std::endl;

	testSubject->setTrackNum(1);
	testSubject->setName("test");
	testSubject->setNurse(1);

	std::cout << "SeaLion::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length SeaLion info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;
	testSubject = new SeaLion(2, "useConst2", 1);

	std::cout << "SeaLion::Info: " << std::endl << testSubject->getInfo() << std::endl;
	std::cout << "char length SeaLion info: " << testSubject->getInfo().length() << std::endl;

	delete testSubject;

	std::cout << "Finished testing Class SeaLion" << std::endl << std::endl;
}


