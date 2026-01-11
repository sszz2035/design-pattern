cmake_minimum_required (VERSION 3.8)

project("util")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES 
	ClassHelper.cpp
	Properties.cpp
	RandomUtil.cpp
	StringUtil.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# 定义 UTIL_EXPORTS 宏，用于导出 DLL 符号
target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		UTIL_EXPORTS
)

# 设置头文件包含路径，使用 PUBLIC 让链接此库的目标也能找到头文件
target_include_directories(${PROJECT_NAME}
	PUBLIC
		${CMAKE_SOURCE_DIR}  # 项目根目录，这样可以用 util/StringUtil.h 的方式引用
)


