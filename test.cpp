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

TEST(taskTest, emptyList){
	EXPECT_EQ("<tl>`EmptyList```0`</tl>`", emptyList->save());
}

TEST(taskTest, bobList){
	EXPECT_EQ("<tl>`Home List```0`<tl>`Wash the car`3/10/21`Urgent!`0`</tl>`</tl>`", bobList->save());
}

TEST(taskTest, homeList){
	EXPECT_EQ("<tl>`Home List```0`<tl>`clean the house```0`</tl>`</tl>`", homeList->save());
	delete emptyList; delete homeList; delete bobList;
}

int main(int argc, char** argv){

	homeList->appendTaskList("<tl>`clean the house```0`</tl>`");
	bobList->appendTaskList("<tl>`Wash the car`3/10/21`Urgent!`0`</tl>`");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


