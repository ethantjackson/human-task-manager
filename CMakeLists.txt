CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(task
	source/main.cpp
	source/InitFactory.cpp
	source/UserControl.cpp
	source/Task.cpp
	source/TaskList.cpp
)

ADD_EXECUTABLE(test
	test.cpp
	source/InitFactory.cpp
	source/UserControl.cpp
	source/Task.cpp
	source/TaskList.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
