#ifndef __COMPONENT_HPP__
#define __COMPONENT_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Component {
public:
	virtual ~Component() = default;

	virtual string getTitle() = 0;
	virtual int countSubTasks() = 0;
  virtual int countSubTaskLists() = 0;
	virtual int getLevel() = 0;
	virtual string save() = 0;

	virtual void setDone(bool) = 0;
	virtual void display() = 0;
	virtual void setDescription(string) = 0;
	virtual void setDueDate(string) = 0;
	virtual void rename(string) = 0;
  virtual bool validCurrTarget() = 0;
	virtual void info() = 0;

};

#endif
