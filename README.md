[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10962089&assignment_repo_type=AssignmentRepo)
 
### Navigation Diagram
![alt text](./images/navigationDiagram.png)

Description: The diagram represents each of the individual screens of the task planner and how the user will be able to navigate between each of the screens. At first, the user will be given the option to either log in, sign up, or quit. After logging in, the user will be sent to the Dashboard, where they will be shown their schedule and given the options of viewing a particular task, adding a new task, viewing their messages, switching over to a calendar view, or back to list view, which each option giving the user additional information and options. 

### Screen Layouts
 ![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/130192487/e1f61768-9bd7-49f4-84db-1e517e32a513)
 
![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/aedaff49-1a52-45df-b2f7-5f6a16d08e0e)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/fdd59a6a-e9d6-4c90-8b02-87013775f2b1)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/612caf70-bdd2-46e6-a49b-7073c80c83db)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/f627b40e-a9a9-4fd7-8b57-9062f35476fc)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/b288c398-c2d8-4573-b731-79dcff77e177)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/8cbe2b7e-6d72-4ab6-9aba-658e0cb3f4d8)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/41d83501-021d-4486-9edd-968e81296084)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/4494c84d-6414-4053-9591-1f50a13b112c)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/d6303e18-79f8-412e-a86b-fca5ddae8533)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/2660d19d-f5d4-47c3-9634-10c99272605a)

![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/68790299/dbce7803-747e-44ce-8e71-84d99d4b916f)

Description: The user will be prompted with 2 options: logging in or signing up. 
- Login: The user will be asked to input their username and password. Once a valid username and password is given, the user will be sent to the dashboard screen.
- Sign Up: In the case that the user does not have an already existing account, the user can choose the "Sign Up" option, where they will be asked for their display name, username, and password to create a new account.
- Dashboard: After logging in, the user will be presented with their schedule, listing all of their tasks for the current week. In this current screen, the user has the option of changing their view to a calendar view, deleting an existing task, selecting and viewing a particular task, adding a new task, configuring their settings, viewing their friends page, and logging out.
- Settings: This is the settings page where the user will be given the options to change their display name, username, and password.
- New Task: After choosing the option of adding a task from the Dashboard, or choosing the option of editing a task after viewing it in the "View Task" screen, the user will be sent to a screen where they can add/change details onto a new (or already existing) task.
- View Task: After choosing the option to select and view a particular task in their schedule, they will be sent to a screen showcasing all the details of the task in question. These details will include the name of the task, a description, label, and deadline. The user will also have the option of deleting the task in question (which will send the user back to the dashboard interface).

## Class Diagram
![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/130192487/37c122ea-d0b2-489b-bc8f-7f3aea9d8ea9)

## Description of class diagram

In the UML diagram depicted, there are 8 classes. Within the Person, Task, Label, TaskSorter, Importance Sorter, DateSorter, DBManager, and UserInterface classes, we have their respective private variables/public member functions. We also have the respective getter/setter functions that both receive inputs from the user and return their respective data members. Certain classes such as the Task class are dependent on the Label class and the TaskSorter interface is an abstract class that both the ImportanceSorter and DateSorter classes are derived from. The DBManager class controls the json file for loading and storing a Person object's account information, such as their username, email, password, list of tasks, list of friends, and messages. Additionally, there is a json file for loading and storing a list of Task objects and their individual names, descriptions, labels, deadline dates, and ratings. The UserInterface class controls all of the cin and cout statements to the user, how the user will be able to navigate through the different screens, and the format of each screen.
- Single Responsibility Principle (SRP): This SOLID principle is fulfilled by the Task and Label classes. The Task class could have additional attributes satisfy the requirements of a label, but this would violate the SRP. Instead, by creating another class 'Label' to fulfill this requirement, we end up with smaller classes that each focus on their individual attributes and functionality, leading to cleaner and more understandable code.
- Inferface Segregation Principle (ISP): This SOLID principle is fulfilled by the ImportanceSorter and DateSorter classes, which inherit from the TaskSorter interface. While, the TaskSorter class could have had different functions to sort Tasks based on different criteria, seperating them into different classes allows for easy readability and further expansion in the future.
 
 ## Screenshots
![image](https://github.com/cs100/final-project-asin007-rcruz053-aiyer026-aswam005/assets/130192487/80d980d7-362a-42bd-b769-5182b4239e0b)
This is a screenshot of our tests passing. All other screenshots of the program have been displayed in the Screen Layouts portion of this README.
