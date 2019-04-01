#include "testScanner.h"

std::string tokenList[] = {                               //token list which defines acceptable tokens for the type tkID

        "iterTk", "voidTk", "varTk", "returnTk", "scanTk", "printTk", "programTk", "condTk", "thenTk", "letTk",
        "intWordTk", "equalsTk", "lessThanTk", "greaterThanTk", "colonTk", "plusTk", "minusTk",
        "multiplyTk", "slashTk", "moduloTk", "periodTk", "leftParTk", "rightParTk", "commaTk", "leftBraceTk",
        "rightBraceTk", "semicolonTk", "leftBracketTk", "rightBracketTk", "idTk", "integerTk", "eofTk", "errorTk"

};

void printToken(Token tk){                                         //function which prints elements of object type Token
    std::cout << "\n";
    std::cout << "Token Type: " << tokenList[tk.tokenID] << "\n";
    std::cout << "Token Instance: " << tk.tokenInstance << "\n";
    std::cout << "Line Number: " << tk.lineNumber << "\n";
    std::cout << "\n";
}

void testScanner(std::ifstream &read){                                 //function that drives the scanner in scanner.cpp

    Token tk = Token();                                                                //create new object of type Token

    while(read){                                                                 //while the file is reading (until EOF)
        tk = scanner(read);                           //stores the returned token from function scanner() in scanner.cpp
        printToken(tk);                             //passed the returned token to the printToken() function (see above)
    }

}