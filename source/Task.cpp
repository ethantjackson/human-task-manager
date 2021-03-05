#include "Task.h"

Task::Task(string title, TaskList* parentList)
{
    this->title = title;
    this->parentList = parentList;
    this->dueDate = "";
    this->description = "";
    this->done = false;
}
Task::Task(string title, string dueDate,
    string description, bool done, TaskList* parentList)
{
    this->title = title;
    this->dueDate = dueDate;
    this->description = description;
    this->done = done;
    this->parentList = parentList;
}

TaskList* Task::getParent()
{
    return parentList;
}

//Component* Task::navigate(string)
//{
//    cout << "This task has no subtasks..." << endl;
//    return this;
//}

string Task::getTitle()
{
    return title;
}

int Task::numSubTasks()
{
    return 1;
}

int Task::getLevel()
{
    if (!parentList) return 0;
    else { return parentList->getLevel() + 1; }
}

string Task::save()
{
    string data = "<t>," + title + "," + dueDate + "," + description + ",";
    if (done) data += "1,";
    else data += "0,";
    data += "</t>,";
    return data;
}

void Task::setDone(bool status)
{
    done = status;
}

void Task::help()
{
    cout << "    i: info" << endl;
    cout << "    sd: set to done" << endl;
    cout << "    d: display" << endl;
    cout << "    cd: change description" << endl;
    cout << "    due: set due date" << endl;
    cout << "    a: add task" << endl;
    cout << "    r: remove task" << endl;
    cout << "    re: rename task" << endl;
    cout << "    n: navigate" << endl;
    cout << "    q: quit" << endl;
    cout << "    s: save" << endl;
    cout << "    u: undo to last save" << endl;
    cout << "    l: login to new user" << endl;
}

void Task::info()
{
    cout << "Title: " << title;
    if (done) cout << " (DONE)";
    cout << endl;
    cout << "Due: " << dueDate << endl;
    cout << "Description: " << endl;
    cout << "    " << description << endl;
}

void Task::display()
{
    cout << title;
    if (done) cout << "(DONE)";
    cout << endl;
}

void Task::setDescription(string newDescription)
{
    description = newDescription;
}

void Task::setDueDate(string newDueDate)
{
    dueDate = newDueDate;
}

char Task::run()
{
    string answer;
    cout << "Enter action: (enter h for help)" << endl;
    cin >> answer;

    if (answer == "h") {
        help();
    }

    else if (answer == "i") {
        info();
    }

    else if (answer == "sd") {
        char choice;
        cout << "Is this task done?(y/n) ";
        cin >> choice;
        cout << endl;
        if (choice == 'y') {
            setDone(true);
        }
        else if (choice == 'n') {
            setDone(false);
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }

    else if (answer == "d") {
        display();
    }

    else if (answer == "cd") {
        string newDescription;
        cout << "Enter new description: " << endl;
        cin.ignore();
        getline(cin, newDescription);
        setDescription(newDescription);
    }

    else if (answer == "due") {
        string newDueDate;
        cout << "Enter new due date " << endl;
        cin.ignore();
        getline(cin, newDueDate);
        setDueDate(newDueDate);
    }

    else if (answer == "a") {
        string task;
        cout << "Specify a task to add" << endl;
        cin.ignore();
        getline(cin, task);
        add(task);
    }

    else if (answer == "r") {
        remove();
    }

    else if (answer == "re") {
        string newName;
        cout << "Enter new title: " << endl;
        cin.ignore();
        getline(cin, newName);
        rename(newName);
    }

    else if (answer != "q" && answer != "n" && answer != "s" && answer != "u" && answer != "l") {
        cout << "Invalid Action" << endl;
    }

    cout << endl;

    return answer[0];
}

void Task::add(string newTask)
{
    /*cout << "cannot add to task...\n";
    return;*/
    if (newTask.find("<") != string::npos || newTask.find(">") != string::npos) {
        cout << "Invalid Task Name" << endl;
        return;
    }
    parentList->TaskListify(new TaskList(title, dueDate, description, done, parentList),
        newTask);
    //self destruct and navigate to parentlist
}

void Task::remove()
{
    /*SingletonUser* user = user->getInstance();
    if (this == user->getCurr())
        user->navigateBack();
    parentList->remove(title);*/
}

void Task::rename(string title)
{
    this->title = title;
}