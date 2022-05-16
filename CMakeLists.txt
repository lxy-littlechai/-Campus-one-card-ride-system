cmake_minimum_required(VERSION 3.21)
project(OneCardSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(OneCardSystem main.cpp CardManager/CardManager.cpp CardManager/CardManager.h TimeManager/TimeManager.cpp TimeManager/TimeManager.h RandDataGenerate/RandDataGenerate.cpp RandDataGenerate/RandDataGenerate.h CarManager/CarManager.cpp CarManager/CarManager.h)
