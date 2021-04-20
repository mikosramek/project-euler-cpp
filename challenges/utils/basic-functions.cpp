#ifndef BASIC_FUNCTIONS
#define BASIC_FUNCTIONS

#include <iostream>

void log(int integerNumber) {
    std::cout << integerNumber << "\n";
}
void logF(float floatNumber) {
    std::cout << floatNumber << "\n";
}
void log(std::string message) {
    std::cout << message << "\n";
}
void log(long longNumber) {
    std::cout << longNumber << "\n";
}

#endif
