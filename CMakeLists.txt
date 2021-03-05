CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(task
	source/main.cpp
	source/InitFactory.cpp
	source/UserControl.cpp
	source/Task.cpp
	source/TaskList.cpp
)

