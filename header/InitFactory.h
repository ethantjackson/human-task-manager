#pragma once
#include "Component.h"
#include "Task.h"
#include "TaskList.h"

using namespace std;

class InitFactory
{
private: 
	TaskList* root;

public:
	InitFactory();
	TaskList* load(string data);
};

