#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Component {
protected:
  string title;
  string dueDate;
  string description;
  bool done;
public:
	virtual ~Component() = default;

	virtual string getTitle() {return title;}
	virtual int countSubTasks() = 0;
  virtual int countSubTaskLists() = 0;
	virtual int getLevel() = 0;
	virtual string save() = 0;

	virtual void setDone(bool) = 0;
	virtual void display() = 0;
	virtual void setDescription(string newDescription) {description = newDescription;}
	virtual void setDueDate(string newDate) {dueDate = newDate;}
	virtual void rename(string newTitle) {title = newTitle;}
  virtual bool validCurrTarget() = 0;
	virtual void info() = 0;

};

#endif
