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
	void help();
	void info();
public:
	Task(string, TaskList*);
	Task(string title, string dueDate, string description, bool done, TaskList* parentList);
	~Task() = default;

	//virtual Component* navigate(string);
	virtual string getTitle();
	virtual int numSubTasks();
	virtual int getLevel();
	virtual string save();

	virtual void setDone(bool);
	virtual void display();
	//virtual void getDescription();
	virtual void setDescription(string);
	//virtual void getDueDate();
	virtual void setDueDate(string);
	virtual char run();
	virtual void add(string);
	virtual void remove();
	virtual void rename(string);

	virtual int num_children() { return 0; }
	TaskList* getParent();
	virtual Component* get_child(int index) { return nullptr; }
};

