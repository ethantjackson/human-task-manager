#pragma once

#include "TaskList.h"

using namespace std;

class Task : public Component
{
private:
	TaskList* parentList;
public:
	Task(string, TaskList*);
	Task(string title, string dueDate, string description, bool done, TaskList* parentList);
	~Task() = default;

	virtual int countSubTasks();
  virtual int countSubTaskLists();
	virtual int getLevel();
	virtual string save();

	virtual void setDone(bool);
	virtual void display();
  virtual bool validCurrTarget() {return false;}
  virtual void info();

	TaskList* getParent();
};

