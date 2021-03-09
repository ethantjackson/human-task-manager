#pragma once
#include "Component.h"

#include <algorithm>

class TaskList : public Component
{
private:
	vector<Component*> contents;
	TaskList* parentList;
public:
	TaskList(string, TaskList*);
	TaskList(string, string, string, bool, TaskList*);
	~TaskList();

	TaskList* navigate(string);

	virtual int countSubTasks();
  virtual int countSubTaskLists();
	virtual int getLevel();
	virtual string save();
	
	void load(string);
	void appendTaskList(string saveInfo);
	void appendTask(string saveInfo);

	virtual void setDone(bool);
	virtual void display();
	void removeAll();
	void remove(string);
  virtual bool validCurrTarget() {return true;}
	virtual void info();

	vector<string> getRootPath();
	Component* getChild(string targetName);
	TaskList* getParent();

};

