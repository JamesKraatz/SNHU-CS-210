# SNHU-CS-210

1)	Summarize the project and what problem it was solving.

The Zoo is primarily about introducing interfacing to Java from C++. In addition to introducing cross language interfacing, the application also exercises creating a collection of derived objects, adding new objects, storing them, displaying them, finding them, loading them from a file, saving them from a file, removing them from a collection, and removing them from memory.

2)	What did you do particularly well?

I like my use of maps in this code. I realize that a map can be used for program info that could be stored in files and loaded at runtime. This would prevent some recompiling the application for data value changes or some data  additions to the program.

3)	Where could you enhance your code? How would these improvements make your code more efficient, secure, and so?

I could have modularized this code better, it is also lacking in decoupling which would also be aided by modularizing. Decoupling and modularizing my code would make it easier to maintain and possibly easier to verify for memory leaks and other security risks. 

4)	Did you find writing any piece of this code challenging, and how did you overcome this? What tools and/or resources are you adding to your support network?

As what seems always, the most difficult things to find seem to be my typo errors. There were some implementations issues the map types, especially when I switched to nested maps, but searching for help and examples on the internet provided sufficient help that I was able to successfully overcome any roadblocks there. 

5)	What skills from this project will be particularly transferable to other projects and/or course work?

The language in general. This is a great exposure to C++ and a great tease to learn more of the standard library. The practice in building the parent objects and derived objects and determining which, if any, methods should be virtual will also move forward with me. It is hard to say that I have worked on a skill that I will leave behind after the course is complete.

6)	How did you make this program maintainable, readable, and adaptable?

Truly, this program is not very adaptable. If any new animal types are added to the zoo, the program will have to be modified. The application’s readability and maintainability is aided by converting long chunks of code into separate functions descriptively named explaining what is being done, using code comments, limiting statements to performing one activity, and writing the code in a readable manner.
