cmake_minimum_required(VERSION 4.0)
project(course_assigntment C)

set(CMAKE_C_STANDARD 11)

add_executable(course_assigntment src/main.c
        header/EventLog.h
        src/EventLog.c
        header/EventQueue.h
        src/EventQueue.c
        header/EventLoop.h
        src/EventLoop.c
        src/Event.c
        header/Event.h
        header/ProgramManager.h
        src/ProgramManager.c
        header/sortAlgo.h
        src/sortAlgo.c)
