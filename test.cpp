#include <iostream>

#include "header/Component.h"
#include "header/Task.h"
#include "header/TaskList.h"
#include "header/InitFactory.h"
#include "header/UserControl.h"

#include "gtest/gtest.h"
//tofu tests
TaskList* emptyList = new TaskList("EmptyList", nullptr);
TaskList* homeList = new TaskList("Home List", nullptr);
TaskList* bobList = new TaskList("Home List", nullptr);
TaskList* chrisList = new TaskList("Home List", nullptr);
TaskList* subList = new TaskList("Home List", nullptr);
TaskList* delList = new TaskList("Home List", nullptr);
TaskList* delWholeList = new TaskList("Home List", nullptr);
TaskList* delMiddleList = new TaskList("Home List", nullptr);

//Jumbo Tests
TaskList* nullGetChildList = new TaskList("Home List", nullptr);
TaskList* getChildList = new TaskList("Home List", nullptr);

//Tofu tests 
TEST(taskTest, emptyList){
	EXPECT_EQ("<tl>`EmptyList```0`</tl>`", emptyList->save());
}

TEST(taskTest, descriptionTest){
	EXPECT_EQ("<tl>`Home List```0`<tl>`Wash the car`3/10/21`Urgent!`0`</tl>`</tl>`", bobList->save());
}

TEST(taskTest, longerList){
	EXPECT_EQ("<tl>`Home List```0`<t>`sweep```0`</t>`<t>`mop```0`</t>`<t>`take out trash```0`</t>`<t>`clean windows```0`</t>`</tl>`", chrisList->save());
}

TEST(taskTest, subTasksLists){
	EXPECT_EQ("<tl>`Home List```0`<tl>`subTaskList```0`</tl>`<tl>`subSubTaskList```0`</tl>`<tl>`subSubSubTaskList```0`</tl>`</tl>`", subList->save());
}

TEST(taskTest, deleteSubLists){
	EXPECT_EQ("<tl>`Home List```0`<tl>`subTaskList```0`</tl>`<tl>`subSubTaskList```0`</tl>`</tl>`", delList->save());
}

TEST(taskTest, deleteWholeList){
	EXPECT_EQ("<tl>`Home List```0`</tl>`", delWholeList->save());
}

TEST(taskTest, deleteMiddleList){
	EXPECT_EQ("<tl>`Home List```0`<tl>`subTaskList```0`</tl>`<tl>`subSubSubTaskList```0`</tl>`</tl>`", delMiddleList->save());
}
//Jumbo tests
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
//Delete class instances
TEST(taskTest, singleTask){
	EXPECT_EQ("<tl>`Home List```0`<tl>`clean the house```0`</tl>`</tl>`", homeList->save());
	delete emptyList; delete homeList; delete bobList; delete chrisList; delete subList; delete delList; delete delWholeList; delete delMiddleList; 
   delete getChildList; delete nullGetChildList;

}

int main(int argc, char** argv){
	//tofu test actions
	homeList->appendTaskList("<tl>`clean the house```0`</tl>`");
	bobList->appendTaskList("<tl>`Wash the car`3/10/21`Urgent!`0`</tl>`");

	chrisList->appendTask("<t>`sweep```0`</t>`");
	chrisList->appendTask("<t>`mop```0`</t>`");
	chrisList->appendTask("<t>`take out trash```0`</t>`");
	chrisList->appendTask("<t>`clean windows```0`</t>`");
	
	subList->appendTaskList("<tl>`subTaskList```0`</tl>`");
	subList->appendTaskList("<tl>`subSubTaskList```0`</tl>`");
	subList->appendTaskList("<tl>`subSubSubTaskList```0`</tl>`");
	
	delList->appendTaskList("<tl>`subTaskList```0`</tl>`");
	delList->appendTaskList("<tl>`subSubTaskList```0`</tl>`");
	delList->appendTaskList("<tl>`subSubSubTaskList```0`</tl>`");
	delList->remove("subSubSubTaskList");
	
	delWholeList->appendTaskList("<tl>`subTaskList```0`</tl>`");
	delWholeList->appendTaskList("<tl>`subSubTaskList```0`</tl>`");
	delWholeList->appendTaskList("<tl>`subSubSubTaskList```0`</tl>`");
	delWholeList->removeAll();

	delMiddleList->appendTaskList("<tl>`subTaskList```0`</tl>`");
	delMiddleList->appendTaskList("<tl>`subSubTaskList```0`</tl>`");
	delMiddleList->appendTaskList("<tl>`subSubSubTaskList```0`</tl>`");
	delMiddleList->remove("subSubTaskList");
	
	//jumbo test actions
	getChildList->appendTask("<t>`make test cases`due today`push nullptr cases`0`</t1>`");

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


