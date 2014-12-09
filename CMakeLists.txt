cmake_minimum_required(VERSION 2.8.3)
project(code_profiler)

find_package(catkin REQUIRED COMPONENTS roscpp message_generation)
find_package(Boost REQUIRED COMPONENTS thread system)

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

add_message_files(FILES
	Statistics.msg
)

generate_messages(DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
)

catkin_package(
	INCLUDE_DIRS include
	LIBRARIES codeprofiler
	CATKIN_DEPENDS roscpp message_runtime
	DEPENDS Boost
)

include_directories(include ${Boost_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})

# set(INC_PROFILING
#     include/profiling/Timer.h
#     include/profiling/Profiler.h
#     include/profiling/ProfileLog.h
#     include/profiling/StatsPublisher.h
#     include/tue/profiling/profiler.h
#     include/tue/profiling/timer.h
#     include/tue/profiling/scoped_timer.h
#     include/tue/profiling/ros/profile_publisher.h
# )

set(SRC_PROFILING
    src/profiling/Timer.cpp
    src/profiling/ProfileLog.cpp
    src/profiling/StatsPublisher.cpp
    src/profiler.cpp
    src/timer.cpp
    src/scoped_timer.cpp
    src/ros/profile_publisher.cpp
)

add_library(codeprofiler ${SRC_PROFILING})
target_link_libraries(codeprofiler ${catkin_LIBRARIES} ${Boost_LIBRARIES})
set_property(TARGET codeprofiler PROPERTY COMPILE_DEFINITIONS "PROFILEAPP")

add_executable(profiler_test src/main.cpp)
target_link_libraries(profiler_test codeprofiler)

add_executable(test_profiler test/test_profiler.cpp)
target_link_libraries(test_profiler codeprofiler)

add_dependencies(codeprofiler ${PROJECT_NAME}_gencpp)
