# CMake最小版本
cmake_minimum_required(VERSION 3.0)
# 定义一个项目
project(LI)

# 再make过程中显示详细命令
set(CMAKE_VERBOSE_MAKEFILE ON)
# 添加编译命令
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -g -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

include_directories(.)
include_directories(/usr/local/include)

link_directories(/usr/local/lib)

# 设置Lib目录
set(
    LIB_SRC
    src/Lox.cc
    src/Scanner.cc
    src/Token.cc
)

# 添加lib的共享库，生成.so文件
add_library(LI SHARED ${LIB_SRC})

# 构建可执行测试文件
add_executable(li_test test/main.cc)
# 添加测试文件依赖
add_dependencies(li_test LI)
# 链接
target_link_libraries(li_test LI)

# 设置可执行文件输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置库文件输出目录
SET(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)


