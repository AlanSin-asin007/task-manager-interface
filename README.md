[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10962089&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Task Manager Interface
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Arnav Swami](https://github.com/arnavswami), [Rylan Cruz](https://github.com/rcruz053), [Alan Sin](https://github.com/AlanSin-asin007), [Adithya Iyer](https://github.com/Adithya-Iyer1)
 > 
 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you? This is important to us because it is vital to have a good user friendly interface where individuals can create certain assignments for themselves to keep themselves up to date with the tasks they have. As students, it comes in handy to organize tasks that we need to do, so students can remain productive and prepare themselves for a world outside of college. 
 > * What languages/tools/technologies do you plan to use? C++ is the main backend language that will be used for development of this project. We will use Github for version control. Kanban will be used for assigning tasks and workload amongst the peers for this project. 
 > * What will be the input/output of your project? Input will be general user information such as passowrds and username/email. The output will be access to a unique developement environment. 
 > * What are the features that the project provides? The option for an individual password or a random password generator to create a password for the user. A forgot password and or user information feature. A user friendly pre made calendar to help the user organize future tasks. The ability for the user to implement tasks for him or herself. As for the UI of the program, we are using a text-based interface that the user is able to input information to. When navigating the various menus, the user will also be able to indicate what part of the menu they want to interact with as well.
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board using GitHub projects (board view). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added.
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
![Navigation_Diagram](https://user-images.githubusercontent.com/129815281/236971001-e4a455f4-ce8f-45d6-abfd-c29fcd17c976.png)

Description: The diagram represents each of the individual screens of the task planner and how the user will be able to navigate between each of the screens. At first, the user will be given the option to either log in or sign up. After logging in, the user will be sent to the Dashboard, where they will be shown their schedule and given the options of viewing a particular task, adding a new task, configuring their settings, viewing their friends page, deleting a task, or switching over to a calendar view, which each option giving the user additional information and options. 

> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
![image](https://user-images.githubusercontent.com/117235128/236956488-59bffb89-aac4-4b39-8a9b-b33a8fd29083.png)

Description: The user will be prompted with 2 options: logging in or signing up. 
- Login: The user will be asked to input their username and password. Once a valid username and password is given, the user will be sent to the dashboard screen.
- Sign Up: In the case that the user does not have an already existing account, the user can choose the "Sign Up" option, where they will be asked for their display name, username, and password to create a new account.
- Dashboard: After logging in, the user will be presented with their schedule, listing all of their tasks for the current week. In this current screen, the user has the option of changing their view to a calendar view, deleting an existing task, selecting and viewing a particular task, adding a new task, configuring their settings, viewing their friends page, and logging out.
- Settings: This is the settings page where the user will be given the options to change their display name, username, and password.
- Friends: This screen will list all of the user's current friends. This screen will give the user the option to either delete a current friend from their friends list, add a new friend, or select a particular friend to message them.
- Chats: The user can enter text that will be sent to a friend of their choosing.
- Enter New Friend: This will be a screen where the user will be prompted to enter the user's friend's identification in order to send a friend request to the other user's account.
- New Task: After choosing the option of adding a task from the Dashboard, or choosing the option of editing a task after viewing it in the "View Task" screen, the user will be sent to a screen where they can add/change details onto a new (or already existing) task.
- View Task: After choosing the option to select and view a particular task in their schedule, they will be sent to a screen showcasing all the details of the task in question. These details will include the name of the task, a description, label, and deadline. The user will have the option of either deleting the task in question (which will send the user back to the dashboard interface), or editing the task in question (which will change their screen to the "New Task" screen).

> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
![Task Manager UML Diagram drawio (1)](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/129815281/135d04cd-8283-4333-b6f0-84c339f3be1b)

## Description of class diagram

In the UML diagram depicted, there are 6 classes. Within the Person, Task, Label, TaskSorter, Importance Sorter, and DateSorter classes, we have their respective private variables/public member functions. We also have the respective getter/setter functions that both receive inputs from the user and return their respective data members. Certain classes such as the Task class are dependent on the Label class and the TaskSorter interface is an abstract class that both the ImportanceSorter and DateSorter classes are derived from.
- Single Responsibility Principle (SRP): This SOLID principle is fulfilled by the Task and Label classes. The Task class could have additional attributes satisfy the requirements of a label, but this would violate the SRP. Instead, by creating another class 'Label' to fulfill this requirement, we end up with smaller classes that each focus on their individual attributes and functionality, leading to cleaner and more understandable code.
- Inferface Segregation Principle (ISP): This SOLID principle is fulfilled by the ImportanceSorter and DateSorter classes, which inherit from the TaskSorter interface. While, the TaskSorter class could have had different functions to sort Tasks based on different criteria, seperating them into different classes allows for easy readability and further expansion in the future.

 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
