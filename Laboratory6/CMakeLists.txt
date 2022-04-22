cmake_minimum_required(VERSION 3.21)
project(Laboratory6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laboratory6
        DynamicArray.cpp
        DynamicArray.h
        DynamicArrayTest.cpp
        DynamicArrayTest.h
        FilteringCriteria.cpp
        FilteringCriteria.h
        FilteringTest.cpp
        FilteringTest.h
        main.cpp
        Offer.cpp
        Offer.h
        OfferTest.cpp
        OfferTest.h)
