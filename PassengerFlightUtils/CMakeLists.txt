cmake_minimum_required(VERSION 3.26)
project(PassengerFlightUtils)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /experimental:module")

add_library(${PROJECT_NAME}
        src/PersonInterface.ixx
        src/PersonImpl.ixx
        src/Person.ixx
        src/Entities/CPassport.ixx
        src/Entities/CPassenger.ixx
        src/Entities/CDestination.ixx
        src/Entities/CAirlineTicket.ixx
        src/TicketPassengerCollection.ixx
        src/RandomHeader.h
)