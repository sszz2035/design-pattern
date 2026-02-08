cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("template")

set(SOURCE Client.cpp "Combo/ComboA.cpp" "Combo/ComboB.cpp")

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME}
PRIVATE
${CMAKE_SOURCE_DIR}/util
${CMAKE_SOURCE_DIR}/template
)

target_link_libraries(${PROJECT_NAME} 
						PRIVATE
						  util)