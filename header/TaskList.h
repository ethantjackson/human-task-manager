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
	void help();
	void info();


public:
	TaskList(string, TaskList*);
	TaskList(string, string, string, bool, TaskList*);
	~TaskList();

	TaskList* navigate(string);

	virtual string getTitle();
	virtual int numSubTasks();
	virtual int getLevel();
	virtual string save();
	
	void load(string);
	void appendTaskList(string saveInfo);
	void appendTask(string saveInfo);

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

	virtual int num_children() { return contents.size(); }

	TaskList* getParent();
	virtual Component* get_child(int index) { return contents.at(index); }
};

