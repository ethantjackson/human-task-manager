 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# HUMAN TASK MANAGER

 
 > Authors: [Christopher Chen](https://github.com/36tofu),
            [Christopher Kim](https://github.com/JimmyNoBob),
            [Ethan Jackson](https://github.com/ethantjackson)
 
 > You will be forming a group of **THREE** students and working on an interesting project. A list of proposed project ideas that have been successful in previous quarters is given in the project specifications link on iLearn. You can select an idea from the list and decide which design patterns you will use to implement it. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal. Your project needs to implement two design patterns.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features.
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory, Visitor, or Decorator
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group.

## Project Description
  * Time management is a significant determinant of productivity. Human Task Manager helps visualize and manage your schedule, creating and displaying hierarchies of tasks and tasks list through the command line. Each task and task list has assignable features, including a title, due date, description, and done indicator. Human Task Manager will also utilize save features and user management to allow multiple users to quickly access, modify, and save their schedules for later use. Each user will have their own password and user data.
  * Human Task Manager will utilize c++, and will be able to utilize file input and output to enable reading and writing of save files.
  * Human Task Manager will receive input from text files and write to text files to implement load and save features. It will also utilize command line input and output to interface with the user. User interactions will include: adding/removing/changing users, adding/removing tasks and changing task/task list parameters, saving task lists, undoing to a previous save, outputting the task list to the terminal, and visually navigating user task hierarchies.
  * Human Task Manager will utilize the Composite and Singleton Design Patterns. 
  * The Composite design pattern will be used to implement each user's task lists. The Composite design pattern consists of leafs and composite objects. Respectfully, these components are represented as tasks and task lists. By introducing the Composite design pattern, the hierarchal nature of task lists can be best implemented, and the potential difficulty of recursive object hierarchies is addressed. Furthermore, shared behavior for tasks and task lists can be implemented through the Composite Pattern, and users can treat their tasks and tasklists identically. 
  * The Singleton design pattern will be used to implement the user management class. This design pattern is useful for user management as the program will only utilize one list of users, and will only allow one current user at a time. The program would also benefit from a global method for controlling this user list. The Singleton design pattern avoids the instantiation of multiple user lists and avoids ambiguity in how this single user list can be managed.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 * Composite Design Pattern: The composite design pattern is used to implement a hierarchy of tasks and task lists. The leaf Tasks and composite TaskLists inherit from a Component interface which defines shared functionality. When add() is called on a Task, the Task is replaced with a TaskList. 
 
>![Composite Diagram (4)](https://user-images.githubusercontent.com/71403787/110257630-955f5c80-7f53-11eb-81e5-cd1b8ba57537.jpg)

 * Singleton: The Singleton design pattern is used to implement the UserControl class. UserControl manages the Users of Human Task Manager, and signIn() conducts the login process when the application is running. Regarding the User class, the homeList holds the User’s entire list of tasks, while currList is used in conjunction with the navigate function to explore and manipulate the User’s different sub-tasks.

>![Singleton Diagram (3)](https://user-images.githubusercontent.com/57571449/108030581-5721ed80-6fe4-11eb-83df-3bb20ad241d0.png)

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
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
