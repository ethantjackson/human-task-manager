#pragma once
#include "TaskList.h"
#include "InitFactory.h"

#include <fstream>
#include <cstring>
#include <utility>
#include <stack>

using namespace std;

class UserControl
{
private:
	InitFactory* init;
	TaskList* homeList;
	TaskList* curr;
	stack<pair<string,vector<string>>> saves;
	string username = "none";

	vector<pair<string,string>> users;
	void saveUsers();

public:
	UserControl();
	~UserControl() {
		delete homeList;
	}
	TaskList* getCurr() {return this->curr;}
	TaskList* findPrevCurr(vector<string>);
	void setCurr(TaskList* newCurr) {this->curr = newCurr;}
	void navigate();
	void navigateBack() {curr = curr->getParent();}
	void save();
	void reset();
	void login();
	void log();
	void undo();
};

