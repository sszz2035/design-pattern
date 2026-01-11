cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("observe")

set(SOURCE 
GameCore.cpp "target/RoleSkill.h" "observer/Role.h" "target/CureSkill.h" "target/HurtSkill.h" "target/HurtSkill.cpp" "target/CureSkill.cpp" "target/RoleSkill.cpp" "observer/RoleObserver.h" "observer/RoleObserver.cpp" "main.cpp")

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} 
						PRIVATE
						  util)


