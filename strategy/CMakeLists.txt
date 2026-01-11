cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("strategy")

set(SOURCE 
"Client.cpp" "Behaviour/NormalBehaviour.h" "Behaviour/AggressiveBehaviour.h" "Behaviour/DefensiveBehaviour.h" "IBehaviour.h" "Adventurer.h")
add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME}
PRIVATE
${CMAKE_SOURCE_DIR}/strategy
${CMAKE_SOURCE_DIR}/util
)

target_link_libraries(${PROJECT_NAME} 
						PRIVATE
						  util)