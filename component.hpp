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

	virtual Component* getParent() = 0;
	virtual Component* navigate(string) = 0;
	virtual string getTitle() = 0;
	virtual int numSubTasks() = 0;
	virtual int getLevel() = 0;
	virtual string save() = 0;

	virtual void setDone(bool) = 0;
	virtual void display() = 0;
	virtual void setDescription(string) = 0;
	virtual void setDueDate(string) = 0;
	virtual char run() = 0;
	virtual void add(string) = 0;
	virtual void remove() = 0;
	virtual void rename(string) = 0;
};

#endif
