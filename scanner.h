#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>



static int line = 1;
int getColumnFSA(char temp);
Token getToken(int state, std::string word);
Token scanner(std::ifstream &read);

#endif