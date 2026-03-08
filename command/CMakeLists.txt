cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project("command")

set(SOURCE "Command.h" "Client.cpp"  "Application.h" "Application.cpp" "UI/Button.h" "UI/Shortcut.h" "UI/Button.cpp" "UI/Shortcut.cpp" "UI/Editor.h" "UI/Editor.cpp" "Cmd/PasteCommand.h" "Cmd/PasteCommand.cpp" "Cmd/CopyCommand.h" "Cmd/CopyCommand.cpp" "Cmd/CutCommand.h" "Cmd/CutCommand.cpp"   "CommandHistory.h" "CommandHistory.cpp" "Cmd/InsertCommand.h" "Cmd/InsertCommand.cpp")

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME}
PRIVATE
${CMAKE_SOURCE_DIR}/command
)

target_link_libraries(${PROJECT_NAME} 
						PRIVATE
						  util)