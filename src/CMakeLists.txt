cmake_minimum_required(VERSION 3.16...3.27.5)

project(super_mario)

SET(CMAKE_CXX_FLAGS "-finput-charset=utf-8 -fexec-charset=utf-8")

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

if(GAME_TYPE STREQUAL "WindowsConsole")
	target_compile_definitions(${PROJECT_NAME} PRIVATE WINDOWS_CONSOLE)
elseif(GAME_TYPE STREQUAL "LinuxConsole")
	target_link_libraries(${PROJECT_NAME} PRIVATE ncurses pthread)
	target_compile_definitions(${PROJECT_NAME} PRIVATE LINUX_CONSOLE)
elseif(GAME_TYPE STREQUAL "Qt")
	set(CMAKE_AUTOMOC ON)
	set(CMAKE_AUTOUIC ON)
	set(CMAKE_AUTORCC ON)

	find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
	target_link_libraries(${PROJECT_NAME} PRIVATE 
		Qt6::Core
		Qt6::Widgets
	)
	target_compile_definitions(${PROJECT_NAME} PRIVATE QT)
endif()

add_subdirectory(os_controls)
add_subdirectory(controller)
add_subdirectory(levels)
add_subdirectory(model)
add_subdirectory(objects)
add_subdirectory(ui)
add_subdirectory(util)

