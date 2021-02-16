#pragma once
#include "Component.h"

class TaskList : public Component
{
private:
	vector<Component*> contents;
	TaskList* parentList;
	string title;
	string dueDate;
	string description;
	bool done;
	void help();
	void info();
public:
	TaskList(string, TaskList*);
	TaskList(string, string, string, bool, TaskList*);
	~TaskList();

	virtual Component* getParent();
	virtual Component* navigate(string);
	virtual string getTitle();
	virtual int numSubTasks();
	virtual int getLevel();
	virtual string save();
	void load(string); 

	virtual void setDone(bool);
	virtual void display();
	//virtual void getDescription();
	virtual void setDescription(string);
	//virtual void getDueDate();
	virtual void setDueDate(string);
	virtual char run();
	virtual void add(string);
	virtual void remove();
	void remove(string);
	virtual void rename(string);
	
	void TaskListify(TaskList*, string);
};

