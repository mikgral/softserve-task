cmake_minimum_required(VERSION 3.10)

project(hellosoftserve)

set(TARGET_PROJECT_NAME softserve_task)

find_package(Threads REQUIRED)

find_package(Boost 1.83 REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${TARGET_PROJECT_NAME} 
  src/handler.hpp
  src/handler.cpp
  src/main.cpp
  )

target_link_libraries(${TARGET_PROJECT_NAME} ${Boost_LIBRARIES})

target_link_libraries(${TARGET_PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

install( TARGETS ${TARGET_PROJECT_NAME}
    DESTINATION bin
  )
