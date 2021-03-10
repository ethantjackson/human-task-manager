#include <iostream>

#include "header/Component.h"
#include "header/Task.h"
#include "header/TaskList.h"
#include "header/InitFactory.h"
#include "header/UserControl.h"

#include "gtest/gtest.h"

TaskList* emptyList = new TaskList("EmptyList", nullptr);
TaskList* homeList = new TaskList("Home List", nullptr);
TaskList* bobList = new TaskList("Home List", nullptr);
TaskList* chrisList = new TaskList("Home List", nullptr);
TaskList* subList = new TaskList("Home List", nullptr);
TaskList* nullGetChildList = new TaskList("Home List", nullptr);
TaskList* getChildList = new TaskList("Home List", nullptr);

TEST(taskTest, emptyList){
	EXPECT_EQ("<tl>`EmptyList```0`</tl>`", emptyList->save());
}

TEST(taskTest, bobList){
	EXPECT_EQ("<tl>`Home List```0`<tl>`Wash the car`3/10/21`Urgent!`0`</tl>`</tl>`", bobList->save());
}

TEST(taskTest, chrisList){
	EXPECT_EQ("<tl>`Home List```0`<t>`sweep```0`</t>`<t>`mop```0`</t>`<t>`take out trash```0`</t>`<t>`clean windows```0`</t>`</tl>`", chrisList->save());
}

TEST(taskTest, subList){
	EXPECT_EQ("<tl>`Home List```0`<tl>`subTaskList```0`</tl>`<tl>`subSubTaskList```0`</tl>`<tl>`subSubSubTaskList```0`</tl>`</tl>`", subList->save());
}

TEST(taskTest, nullGetChildList) {
	string pleaseReturnNullptr = "I said please?";
	nullGetChildList->getChild(pleaseReturnNullptr);
	EXPECT_EQ(nullptr, getChildList->getChild(pleaseReturnNullptr));
}

TEST(taskTest, getChildList) {
	string targetName = "make test cases";
	getChildList->getChild(targetName);
	EXPECT_EQ("<tl>`Home List```0`<t>`make test cases`due today`push nullptr cases`0`</t>`</tl>`", getChildList->save());
}

TEST(taskTest, homeList){
	EXPECT_EQ("<tl>`Home List```0`<tl>`clean the house```0`</tl>`</tl>`", homeList->save());
	delete emptyList; delete homeList; delete bobList; delete chrisList; delete subList; delete getChildList;
}



int main(int argc, char** argv){

	homeList->appendTaskList("<tl>`clean the house```0`</tl>`");

	bobList->appendTaskList("<tl>`Wash the car`3/10/21`Urgent!`0`</tl>`");

	chrisList->appendTask("<t>`sweep```0`</t>`");
	chrisList->appendTask("<t>`mop```0`</t>`");
	chrisList->appendTask("<t>`take out trash```0`</t>`");
	chrisList->appendTask("<t>`clean windows```0`</t>`");
	
	subList->appendTaskList("<tl>`subTaskList```0`</tl>`");
	subList->appendTaskList("<tl>`subSubTaskList```0`</tl>`");
	subList->appendTaskList("<tl>`subSubSubTaskList```0`</tl>`");

	getChildList->appendTask("<t>`make test cases`due today`push nullptr cases`0`</t1>`");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


