#pragma once

#include "TaskList.h"

using namespace std;

class Task : public Component
{
private:
	TaskList* parentList;
	string title;
	string dueDate;
	string description;
	bool done;

public:
	Task(string, TaskList*);
	Task(string title, string dueDate, string description, bool done, TaskList* parentList);
	~Task() = default;


	virtual string getTitle();
	virtual int countSubTasks();
  virtual int countSubTaskLists();
	virtual int getLevel();
	virtual string save();

	virtual void setDone(bool);
	virtual void display();
	virtual void setDescription(string);
	virtual void setDueDate(string);
	virtual void rename(string);
  virtual bool validCurrTarget() {return false;}
  virtual void info();

	TaskList* getParent();
};

