#include "Task.h"

TaskList::TaskList(string title, TaskList* parentList)
{
    this->title = title;
    this->parentList = parentList;
    this->description = "";
    this->dueDate = "";
    this->done = false;
}

TaskList::TaskList(string title, string dueDate,
    string description, bool done, TaskList* parentList)
{
    this->title = title;
    this->dueDate = dueDate;
    this->description = description;
    this->done = done;
    this->parentList = parentList;
}

TaskList::~TaskList() {
    for (auto c : contents) {
        delete c;
    }
}

TaskList* TaskList::getParent()
{
    return parentList;
}

TaskList* TaskList::navigate(string task)
{
    for (auto c : contents) {
        if (c->getTitle() == task) {
            try {
                return dynamic_cast<TaskList*>(c);
            }
            catch (const std::bad_cast& e)
            {
                std::cout << "Cannot open task..." << e.what() << "\n";
                return this;
            }
        }
    }
    cout << "Task Not Found" << endl;
    return this;
}

string TaskList::getTitle()
{
    return title;
}

int TaskList::numSubTasks()
{
    int numSubs = 0;
    for (auto c : contents) {
        numSubs += c->numSubTasks();
    }
    return numSubs;
}

int TaskList::getLevel()
{
    if (!parentList) return 0;
    else { return parentList->getLevel() + 1; }
}

string TaskList::save()
{
    string sstring = "<tl>," + title + "," + dueDate + "," + description + ",";
    if (done) sstring += "1,";
    else sstring += "0,";
    for (auto c : contents) {
        sstring += c->save();
    }
    sstring += "</tl>,";
    return sstring;
}

void TaskList::load(string data)
{
    stringstream ss(data);
    string info;
    string token;
    int endListCount;

    getline(ss, token, ','); // ignore first <tl>

    getline(ss, token, ',');
    rename(token);
    getline(ss, token, ',');
    setDueDate(token);
    getline(ss, token, ',');
    setDescription(token);
    getline(ss, token, ',');
    if (token == "1") setDone(true);
    else setDone(false);

    while (getline(ss, token, ',')) {
        if (token == "<tl>") {
            //append new task list
            endListCount = 1;
            info = token + ",";
            while (endListCount != 0) {
                getline(ss, token, ',');
                info += (token + ",");
                if (token == "</tl>") --endListCount;
                else if (token == "<tl>") ++endListCount;
                //cout << "tl(r) token: \"" << token << "\"\n";
            }
            info += "</tl>,";
            //cout << "tl(r) info: \"" << info << "\"\n";
            appendTaskList(info);
        }
        if (token == "<t>") {
            info = token + ",";
            while (token != "</t>") {
                getline(ss, token, ',');
                info += (token + ",");
                //cout << "t(r) token: \"" << token << "\"\n";
            }
            info += "</t>,";
            //cout << "t(r) info: \"" << info << "\"\n";
            appendTask(info);
        }
    }
}
void TaskList::appendTaskList(string saveInfo)
{
    contents.push_back(new TaskList("tmp", this));
    static_cast<TaskList*>(contents.at(contents.size() - 1))->load(saveInfo);
}
void TaskList::appendTask(string saveInfo) {
    stringstream ss(saveInfo);
    string title, dueDate, description, token;
    bool done;

    getline(ss, token, ','); // ignore first <t>

    getline(ss, title, ',');
    getline(ss, dueDate, ',');
    getline(ss, description, ',');
    getline(ss, token, ',');
    if (token == "1") done = true;
    else done = false;

    contents.push_back(new Task(title, dueDate, description, done, this));
}

void TaskList::remove()
{
    char choice;
    cout << "Would you like to (1) Remove this task list or (2) Remove a subtask? ";
    cin >> choice;
    cout << endl;
    if (choice == '1') {
        if (!parentList) {
            for (auto c : contents) {
                remove(c->getTitle());
            }
        }
        else {
            /*if (this == user->getCurr())
                user->navigateBack();
            parentList->remove(title);*/
            cout << "cannot remove self\n";
        }
    }
    else if (choice == '2') {
        string task;
        cout << "Specify task to remove: " << endl;
        cin.ignore();
        getline(cin, task);
        for (auto c : contents) {
            if (c->getTitle() == task) {
                c->remove();
                return;
            }
        }
        cout << "Task Not Found" << endl;
    }
    else {
        cout << "Invalid Choice" << endl;
    }
}

void TaskList::remove(string task)
{
    for (unsigned int i = 0; i < contents.size(); ++i) {
        if (contents.at(i)->getTitle() == task) {
            delete contents.at(i);
            contents.erase(contents.begin() + i);
            return;
        }
    }
    cout << "Task Not Found" << endl;
}

void TaskList::setDone(bool status)
{
    if (status) {
        done = true;
        for (auto c : contents)
            c->setDone(true);
    }
    else {
        done = false;
        for (auto c : contents)
            c->setDone(false);
    }
}

void TaskList::display()
{
    cout << title;
    if (done) cout << "(DONE)";
    cout << endl;
    for (auto c : contents) {
        for (int i = getLevel(); i >= 0; --i) {
            cout << "    ";
        }
        c->display();
    }
}

void TaskList::setDescription(string description)
{
    this->description = description;
}

void TaskList::setDueDate(string dueDate)
{
    this->dueDate = dueDate;
}

char TaskList::run()
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
        cout << "Is this task list done?(y/n) ";
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
        cout << "Specify a task to add or which task you would like to add to: " << endl;
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

void TaskList::add(string task)
{
    if (task.find("<") != string::npos || task.find(">") != string::npos) {
        cout << "Invalid Task List Name" << endl;
        return;
    }
    for (auto c : contents) {
        if (c->getTitle() == task) {
            cout << "Specify a task to add or which task you would like to add to: " << endl;
            getline(cin, task);
            c->add(task);
            return;
        }
    }
    contents.push_back(new Task(task, this));
}

void TaskList::rename(string title)
{
    this->title = title;
}

void TaskList::help() {
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

void TaskList::info() {
    cout << "Title: " << title;
    cout << ", " << numSubTasks() << " subtasks";
    if (done) cout << " (DONE)";
    cout << endl;
    cout << "Due: " << dueDate << endl;
    cout << "Description: " << endl;
    cout << "    " << description << endl;
}

void TaskList::TaskListify(TaskList* task, string newTask)
{
    remove(task->getTitle());
    contents.push_back(task);
    contents.at(contents.size() - 1)->add(newTask);
}