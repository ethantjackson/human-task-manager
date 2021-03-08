#include "../header/Task.h"
#include <typeinfo>

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
            if (c->validCurrTarget()) return static_cast<TaskList*>(c);
            else {
              cout << "Cannot open a subtask...\n";
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

int TaskList::countSubTasks()
{
    int numSubs = 0;
    for (auto c : contents) {
        numSubs += c->countSubTasks();
    }
    return numSubs;
}

int TaskList::countSubTaskLists() {
    int numSubs = 0;
    ++numSubs;
    for (auto c : contents) {
      numSubs += c->countSubTaskLists();
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
    string sstring = "<tl>`" + title + "`" + dueDate + "`" + description + "`";
    if (done) sstring += "1`";
    else sstring += "0`";
    for (auto c : contents) {
        sstring += c->save();
    }
    sstring += "</tl>`";
    return sstring;
}

void TaskList::load(string data)
{
    stringstream ss(data);
    string info;
    string token;
    int endListCount;

    getline(ss, token, '`'); // ignore first <tl>

    getline(ss, token, '`');
    rename(token);
    getline(ss, token, '`');
    setDueDate(token);
    getline(ss, token, '`');
    setDescription(token);
    getline(ss, token, '`');
    if (token == "1") setDone(true);
    else setDone(false);

    while (getline(ss, token, '`')) {
        if (token == "<tl>") {
            //append new task list
            endListCount = 1;
            info = token + "`";
            while (endListCount != 0) {
                getline(ss, token, '`');
                info += (token + "`");
                if (token == "</tl>") --endListCount;
                else if (token == "<tl>") ++endListCount;
            }
            info += "</tl>`";
            appendTaskList(info);
        }
        if (token == "<t>") {
            info = token + "`";
            while (token != "</t>") {
                getline(ss, token, '`');
                info += (token + "`");
            }
            info += "</t>`";
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

    getline(ss, token, '`'); // ignore first <t>

    getline(ss, title, '`');
    getline(ss, dueDate, '`');
    getline(ss, description, '`');
    getline(ss, token, '`');
    if (token == "1") done = true;
    else done = false;

    contents.push_back(new Task(title, dueDate, description, done, this));
}

void TaskList::removeAll()
{
  contents.clear();
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
    cout << "Task/list Not Found..." << endl;
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

void TaskList::rename(string title)
{
    this->title = title;
}

void TaskList::info() {
    cout << "Title: " << title;
    cout << ", " << countSubTaskLists()-1 << " sublists";
    cout << ", " << countSubTasks() << " subtasks";
    if (done) cout << " (DONE)";
    cout << endl;
    cout << "Due: " << dueDate << endl;
    cout << "Description: " << endl;
    cout << "    " << description << endl;
}

Component* TaskList::getChild(string targetName) {
    for(auto c : contents) {
	if(c->getTitle() == targetName) {	
	    return c;
	}
    }
    return nullptr;
}

vector<string> TaskList::getRootPath() {
    if (parentList) {
        vector<string> path = parentList->getRootPath();
        path.push_back(title);
        return path;
    }
    else {
        vector<string> path(0);
        return path;
    }
}

