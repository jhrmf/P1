#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum tkID {

    iterTk, voidTk, varTk, returnTk, scanTk, printTk, programTk, condTk, thenTk, letTk,
    intWordTk, equalsTk, lessThanTk, greaterThanTk, colonTk, plusTk, minusTk, multiplyTk, slashTk,
    moduloTk, periodTk, leftParTk, rightParTk, commaTk, leftBraceTk, rightBraceTk,
    semicolonTk, leftBracketTk, rightBracketTk, idTk, integerTk, eofTk, errorTk

};

struct Token {
    tkID tokenID;
    std::string tokenInstance;
    int lineNumber;

    Token(){
        this->tokenID = errorTk;
        this->tokenInstance = "ERROR";
        this->lineNumber = -1;
    }
    Token(tkID tokenID, std::string tokenInstance, int lineNumber){
        this->tokenID = tokenID;
        this->tokenInstance = tokenInstance;
        this->lineNumber = lineNumber;
    }
};

#endif