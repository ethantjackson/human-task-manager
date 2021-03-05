#pragma once
#include "TaskList.h"

#include <fstream>
#include <cstring>
#include <utility>

using namespace std;

class SingletonUser
{
private:
	static SingletonUser* instance;
	TaskList* homeList;
	Component* curr;
	string username = "none";

	vector<pair<string,string>> users;
	void saveUsers();

	SingletonUser();
	~SingletonUser() {
		delete homeList;
	}
public:
	static SingletonUser* getInstance() {
		if (!instance)
			instance = new SingletonUser();
		return instance;
	}
	Component* getCurr() {return this->curr;}
	Component* setCurr(Component* newCurr) {this->curr = newCurr;}
	void navigate();
	void navigateBack() {curr = curr->getParent();}
	void save();
	void reset();
	void login();
};
