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
 
>![Composite Diagram (5)](https://user-images.githubusercontent.com/71403787/110257723-f25b1280-7f53-11eb-9ba9-d9bae1f42860.jpg)

 * Factory Design Pattern: The factory design pattern is implemented through the InitFactory class. Upon starting the application or logging into a new user, UserControl calls on the InitFactory to parse the appropriate user's save file and build the user's task/task list hierarchy.

>![FactoryPattern](https://user-images.githubusercontent.com/71403787/110258695-bfffe400-7f58-11eb-8013-ba92295c00d3.jpg)

 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 > Logging into the application:
 > ![image](https://user-images.githubusercontent.com/71403787/110260130-d5c4d780-7f5f-11eb-84f5-bcc4fcd950dd.png)

 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
