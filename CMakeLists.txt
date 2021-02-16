CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(task
	main.cpp Task.cpp TaskList.cpp SingletonUser.cpp)

