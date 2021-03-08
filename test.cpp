#include <iostream>

#include "header/Component.h"
#include "header/InitFactory.h"
#include "header/Task.h"
#include "header/TaskList.h"
#include "header/UserControl.h"

#include "gtest/gtest.h"

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

