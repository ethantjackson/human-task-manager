#pragma once
#include "Component.h"

#include <algorithm>

class TaskList : public Component
{
private:
	vector<Component*> contents;
	TaskList* parentList;
	string title;
	string dueDate;
	string description;
	bool done;



public:
	TaskList(string, TaskList*);
	TaskList(string, string, string, bool, TaskList*);
	~TaskList();

	TaskList* navigate(string);

	virtual string getTitle();
	virtual int countSubTasks();
  virtual int countSubTaskLists();
	virtual int getLevel();
	virtual string save();
	
	void load(string);
	void appendTaskList(string saveInfo);
	void appendTask(string saveInfo);

	virtual void setDone(bool);
	virtual void display();
	virtual void setDescription(string);
	virtual void setDueDate(string);
	void removeAll();
	void remove(string);
	virtual void rename(string);
  virtual bool validCurrTarget() {return true;}
	virtual void info();

	

	vector<string> getRootPath();
	Component* getChild(string targetName);
	TaskList* getParent();

};

