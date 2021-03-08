#include "../header/Task.h"

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

string Task::getTitle()
{
    return title;
}

int Task::countSubTasks()
{
    return 1;
}
int Task::countSubTaskLists()
{
    return 0;
}

int Task::getLevel()
{
    if (!parentList) return 0;
    else { return parentList->getLevel() + 1; }
}

string Task::save()
{
    string data = "<t>`" + title + "`" + dueDate + "`" + description + "`";
    if (done) data += "1`";
    else data += "0`";
    data += "</t>`";
    return data;
}

void Task::setDone(bool status)
{
    done = status;
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

void Task::rename(string title)
{
    this->title = title;
}