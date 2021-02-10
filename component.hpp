#include <iostream>

using namespace std;

class Component {
    private:
	string title;
	string dueDate;
	string description;
	bool done;
    public:
	virtual ~Component() = default;

	virtual bool isDone() = 0;
	virtual bool setDone() = 0;
	virtual void display() = 0;
	virtual void getDescription() = 0;
	virtual void edit(char) = 0;
	virtual void add(string) = 0;
	virtual void remove() = 0;
	virtual void rename(string) = 0;
};
