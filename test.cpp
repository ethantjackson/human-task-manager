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
TaskList* complexList = new TaskList("Home List", nullptr);

//JimmyNoBob Tests
TaskList* nullGetChildList = new TaskList("Home List", nullptr);
TaskList* getChildList = new TaskList("Home List", nullptr);
TaskList* numSubTask = new TaskList("Home List", nullptr);

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

TEST(taskTest, complexList){
	EXPECT_EQ("<tl>`Home List```0`<tl>`wash car```0`<t>`water rinse```0`</t>`<t>`apply soap```0`</t>`<t>`clean windows```0`</t>`<t>`clean wheels```0`</t>`<t>`clay bar```0`</t>`<t>`apply wax```0`</t>`<t>`buff dry```0`</t>`</tl>`</tl>`", complexList->save());
}

//JimmyNoBob tests
TEST(taskTest, nullGetChildList) {
	string pleaseReturnNullptr = "I said please?";
	EXPECT_EQ(nullptr, getChildList->getChild(pleaseReturnNullptr));
}

TEST(taskTest, getChildList) {
	string targetName = "make test cases";
	getChildList->getChild(targetName);
	EXPECT_EQ("<tl>`Home List```0`<t>`make test cases`due today`push nullptr cases`0`</t>`</tl>`", getChildList->save());
}

TEST(taskTest, countSubTasksTest) {
	EXPECT_EQ(1, numSubTask->countSubTasks());
}

TEST(taskTest, countSubTasksEmptyTest) {
	EXPECT_EQ(0, emptyList->countSubTasks());
}

TEST(taskTest, countSubTasksChrisListTest) {
	EXPECT_EQ(4, chrisList->countSubTasks());
}

TEST(taskTest, countSubTasksSubList) {
	EXPECT_EQ(0, subList->countSubTasks());
}

TEST(taskTest, countSubTaskListsTest) {
	EXPECT_EQ(2, numSubTask->countSubTaskLists());
}

TEST(taskTest, countSubTaskListsEmptyTest) {
	EXPECT_EQ(1, emptyList->countSubTaskLists());
}

TEST(taskTest, countSubTaskListsChrisListTest) {
	EXPECT_EQ(1, chrisList->countSubTaskLists());
}

TEST(taskTest, countSubTaskListSubList) {
	EXPECT_EQ(4, subList->countSubTaskLists());
}

//Delete class instances
TEST(taskTest, singleTask){
	EXPECT_EQ("<tl>`Home List```0`<tl>`clean the house```0`</tl>`</tl>`", homeList->save());
	delete emptyList; delete homeList; delete bobList; delete chrisList; delete subList; delete delList; delete delWholeList; delete delMiddleList;
	delete complexList;
   delete getChildList; delete nullGetChildList; delete numSubTask;

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
		
	complexList->appendTaskList("<tl>`wash car```0`</tl>`");
	TaskList* example = static_cast<TaskList*>(complexList->getChild("wash car"));
	
	example->appendTask("<t>`water rinse```0`</t>`");
	example->appendTask("<t>`apply soap```0`</t>`");
	example->appendTask("<t>`clean windows```0`</t>`");
	example->appendTask("<t>`clean wheels```0`</t>`");
	example->appendTask("<t>`clay bar```0`</t>`");
	example->appendTask("<t>`apply wax```0`</t>`");
	example->appendTask("<t>`buff dry```0`</t>`");

	//jumbo test actions
	getChildList->appendTask("<t>`make test cases`due today`push nullptr cases`0`</t1>`");
	
	numSubTask->appendTaskList("<tl>`This is a Task List```0`</tl>`");
	numSubTask->appendTask("<t>`This is a Task```0`</tl>`");

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


