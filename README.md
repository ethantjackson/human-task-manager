# HUMAN TASK MANAGER

 
 > Authors: [Christopher Chen](https://github.com/36tofu),
            [Christopher Kim](https://github.com/JimmyNoBob),
            [Ethan Jackson](https://github.com/ethantjackson)

## Project Description
  * Time management is a significant determinant of productivity. Human Task Manager helps visualize and manage your schedule, creating and displaying hierarchies of tasks and tasks list through the command line. Each task and task list has assignable features, including a title, due date, description, and done indicator. Human Task Manager will also utilize save features and user management to allow multiple users to quickly access, modify, and save their schedules for later use. Each user will have their own password and user data.
  * Human Task Manager will utilize c++, and will be able to utilize file input and output to enable reading and writing of save files.
  * Human Task Manager will receive input from text files and write to text files to implement load and save features. It will also utilize command line input and output to interface with the user. User interactions will include: adding/removing/changing users, adding/removing tasks and changing task/task list parameters, saving task lists, undoing/redoing to user actions, outputting the task list to the terminal, and visually navigating user task hierarchies.
  * Human Task Manager will utilize the Composite and Factory Design Patterns. 
  * The Composite design pattern will be used to implement each user's task lists. The Composite design pattern consists of leafs and composite objects. Respectfully, these components are represented as tasks and task lists. By introducing the Composite design pattern, the hierarchal nature of task lists can be best implemented, and the potential difficulty of recursive object hierarchies is addressed. Furthermore, shared behavior for tasks and task lists can be implemented through the Composite Pattern, and users can treat their tasks and tasklists identically. 
  * The Factory design pattern will be used by the user control class to reconstruct saved user task/task list hierarchies. Upon logging into a user, the factory will parse user save data and build the user's saved task/task list hierarchy. Constructing the user's task/task list hierarchy involves creating new Tasks and TaskLists (with parameters defined by save data). When finished, the Factory passes the root of the constructed task/task list tree back to the user control class to be used in the main application. The factory design pattern contains the logic for this user initialization, allowing for reuse throughout the program as different users login. 

## Class Diagrams
 * Composite Design Pattern: The composite design pattern is used to implement a hierarchy of tasks and task lists. The leaf Tasks and composite TaskLists inherit from a Component interface which defines shared functionality.
 
![Composite Diagram (4)](https://user-images.githubusercontent.com/71403787/110417177-ea7d9a00-8049-11eb-9da1-6a7f58428cb4.jpg)

 * Factory Design Pattern: The factory design pattern is implemented through the InitFactory class. Upon starting the application or logging into a new user, UserControl calls on the InitFactory to parse the appropriate user's save file and build the user's task/task list hierarchy.

![FactoryPattern](https://user-images.githubusercontent.com/71403787/110417459-84dddd80-804a-11eb-87a9-c6be2380d027.jpg)
 
 ## Screenshot
  * Logging into the application (preexisting users can also login using their account credentials):
  
  ![image](https://user-images.githubusercontent.com/71403787/110260130-d5c4d780-7f5f-11eb-84f5-bcc4fcd950dd.png)
 
 * "h" displays application usage options:

 ![image](https://user-images.githubusercontent.com/71403787/110260269-42d86d00-7f60-11eb-86e1-46edd2eaf682.png)

* "a" allows users to add Tasks or TaskLists:

![image](https://user-images.githubusercontent.com/71403787/110260348-a2cf1380-7f60-11eb-96b5-6b8f6dfc1df6.png)

* "d" displays the users current list:

 ![image](https://user-images.githubusercontent.com/71403787/110260920-f9d5e800-7f62-11eb-8a80-b0f61ea7923c.png)


* "n" allows users to navigate their task hierarchy:

 ![image](https://user-images.githubusercontent.com/71403787/110260455-2e48a480-7f61-11eb-8115-f411253ed6d7.png)

* "r" allows users to remove Tasks or TaskLists from the current list:

 ![image](https://user-images.githubusercontent.com/71403787/110260508-6f40b900-7f61-11eb-8560-3e7ff29256f3.png)

* "u" and "z" can be used to undo and redo actions, respectively:

 ![image](https://user-images.githubusercontent.com/71403787/110260540-8d0e1e00-7f61-11eb-8b1f-0bc7f8b5dd01.png) ![image](https://user-images.githubusercontent.com/71403787/110260551-98614980-7f61-11eb-96b2-933843721b1e.png)

 (The above images follow the remove action in the previos step)

* "l" allows new users to login. As shown, user data is saved for future logins:

 ![image](https://user-images.githubusercontent.com/71403787/110260693-1de4f980-7f62-11eb-880f-52b03f0bd461.png)

* press "q" to quit the application (user data is saved automatically for future use, and can be saved anytime with "s"):

 ![image](https://user-images.githubusercontent.com/71403787/110260726-3e14b880-7f62-11eb-83a3-7c9b8d9ccf9e.png)


 ## Installation/Usage
 * Human Task Manager is run completely through the command line. You can use cmake to compile the program. The application can then be run using the "task" executable, with "$./task". 
 
 ## Testing
  * Human Task Manager was tested throughly using googletest unit testing. We created several mock Task/TaskList trees, and compared function return values to expected results for each of these mock trees.
  * Valgrind was utilized to verify that no memory leaks existed in the main and test funcitons. 
