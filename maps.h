#ifndef MAPS_H
#define MAPS_H

#include "testScanner.h"
#include <map>
#include <string>

std::map<int, tkID> fs = {                                      //fs is a map that links an integer value to a tkID type
                                 // this is to return the value corresponding the values in the FSA table in scanner.cpp
        {-1, eofTk},
        {1000, idTk},
        {1001, integerTk},
        {1002, equalsTk},
        {1003, lessThanTk},
        {1004, greaterThanTk},
        {1005, colonTk},
        {1006, plusTk},
        {1007, minusTk},
        {1008, multiplyTk},
        {1009, slashTk},
        {1010, moduloTk},
        {1011, periodTk},
        {1012, leftParTk},
        {1013, rightParTk},
        {1014, commaTk},
        {1015, leftBraceTk},
        {1016, rightBraceTk},
        {1017, semicolonTk},
        {1018, leftBracketTk},
        {1019, rightBracketTk}

};

std::map<std::string, tkID> kw = {              //kw is a map that links keyword values to their corresponding tkID type
                                                  //this is to search if the keyword provided is one that is acceptable,
                                                                  //meaning it exists in this list (used in scanner.cpp)
        {"iter", iterTk},
        {"void", voidTk},
        {"var", varTk},
        {"return", returnTk},
        {"scan", scanTk},
        {"print", printTk},
        {"program", programTk},
        {"cond", condTk},
        {"then", thenTk},
        {"let", letTk},
        {"int", intWordTk}

};

std::map<char, int> od = {          //od is a map that links acceptable operator and delimiter values to a corresponding
                                                                //integer, which relates to the FSA table in scanner.cpp
        {'=', 3},
        {'<', 4},
        {'>', 5},
        {':', 6},
        {'+', 7},
        {'-', 8},
        {'*', 9},
        {'/', 10},
        {'%', 11},
        {'.', 12},
        {'(', 13},
        {')', 14},
        {',', 15},
        {'{', 16},
        {'}', 17},
        {';', 18},
        {'[', 19},
        {']', 20}
};

#endif