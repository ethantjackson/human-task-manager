#include <iostream>

#include "header/Component.h"
#include "header/Task.h"
#include "header/TaskList.h"
#include "header/InitFactory.h"
#include "header/UserControl.h"

#include "gtest/gtest.h"

TaskList* emptyList = new TaskList("EmptyList", nullptr);

TEST(taskTest, emptyList){
	EXPECT_EQ("<tl>`EmptyList```0`</tl>`", emptyList->save());
}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


