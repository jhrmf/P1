#include "scanner.h"
#include "testScanner.h"
#include "maps.h"


using namespace std;

int fsa[21][23] = {
        //see fsaGraph.png file for corresponding table
        {     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,  16, 17,  18,   19,  20,  -1,  -2},
        {   1000,   1,   1, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,   1},
        {   1001, 1001,   2, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001, 1001},
        {   1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002},
        {   1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003},
        {   1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004},
        {   1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005, 1005},
        {   1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006},
        {   1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007, 1007},
        {   1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008, 1008},
        {   1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009},
        {   1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010},
        {   1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011, 1011},
        {   1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012},
        {   1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013},
        {   1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014},
        {   1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015},
        {   1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016},
        {   1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017},
        {   1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018},
        {   1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019},

};


int getColumnFSA(char temp){        //function to retrieve the corresponding column for the character passed (see above)

    if(isalpha(temp)){                                                   //check if character is an alphabetic character
        if(isupper(temp)){                      //check if the character, which is an alphabetic character, is uppercase
            return 22;                                                            //if it is uppercase, return column 22
        }
        return 1;                                                                           //otherwise, return column 1
    }
    else if(isdigit(temp)){                                      //if character isn't alphabetic, check if it is a digit
        return 2;                                                                               //if so, return column 2
    }
    else if(isspace(temp)){                     //if the character is neither of the above, check if it is a white space
        return 0;                                                                                      //if so, return 0
    }
    else if(od.find(temp) != od.end()){                  //if none of the above, check if it is an operator or delimiter
                                                                      //check if the character exists in od (see maps.h)
            return od[temp];                                       //return the column specific to the special character
    }
    return -2;                                                               //if none of these things, return column -2

}

Token getToken(int state, std::string word, int line){  //function for returning a token, comprised of the passed values
                                              //state is the token state, word is the value, and line is the line number
    Token tk = Token();                                                                             //create a new token
    if(fs.find(state) != fs.end()){                         //see if the value is a final state value in fs (see maps.h)
        tk.tokenID = fs[state];                                                //if it is, store the ID from fs at state
        tk.tokenInstance = word;                                         //store the word passed as the token's instance
        tk.lineNumber = line;                                        //store the line number passed into the line number
    }
    if(kw.find(word) != kw.end()){                                       //check if the value word is in kw (see maps.h)
        tk.tokenID = kw[word];                                       //store the word as the token ID if it is a keyword
    }

    return tk;                                                                            //return the new token created

}

Token scanner(std::ifstream &read){                    //In scanner, we evaluate states as we traverse through the file,
                                                                                               // character by character

    int state = 0, tempState = 0;                                    //Integer "state" is for logging the current state,
                                                         // and Integer "tempstate" is for updating state as we traverse
    char character;                    // char "character" is for holding the current character during traversal of file
    std::string word;                                            //std::string word is for building a final string word,
                                                                            //seperated by white spaces or \n characters

    while (state < 99 && state > -1){         //while the current state is not a final state, loop through the following

        read.get(character);                                                           //get the character from the file

        if(character == '&'){                  //if statement which ignores comments, which state with & and end with nl
            while(character != '\n'){
                read.get(character);
            }
            line++;                                                                     //line can be found in scanner.h
            read.get(character);
        }

        int column = getColumnFSA(character);  //get the column on the corresponding FSA table for the current character
                                                                                                   //(see fsaGraph file)
        if (read.eof()) {                   //if the end of file is reached during traversal, set the column accordingly
            column = 21;                                                                           //(see fsaGraph file)
        }

        tempState = fsa[state][column];     //get the updated state based on the current state, and the retrieved column
                                                                                                   //(see fsaGraph file)
        if(tempState >=  1000 || tempState < 0 ) {            //if the next state is not a final state, do the following

            if (tempState == -2) {                             //if the updated state is an error, return an error token
                while(!isspace(character)){
                    word+=character;
                    read.get(character);
                }
                return Token(errorTk, word, line);
            }
            if (tempState == -1) {                               //if the updated state is end of file, return eof token
                if (read.eof()) {
                    return Token(eofTk, "EOF", line);
                }
                else {                                           //otherwise, there is an invalid character in the word,
                    while (!isspace(character)) {                                            //thus, return error token!
                        word+=character;
                        read.get(character);
                    }
                    return Token(errorTk, word, line);
                }
            }


            read.unget();                                                 //get rid of the character retrieved from file

            return getToken(tempState, word, line);                //return the token (retrieved from function getToken,
                                                                                // using the word that is created below,
                                                                        // and the updated state, as well as line number
        }
        else{                                              //if the updated state is not a final state, do the following
            if(!isspace(character)){                       //as long as the character is not a space, add it to the word
                word += character;
            }
            if(character == '\n'){                             //if the character is a new line, increase the line count
                line++;                                                                 //line can be found in scanner.h
            }

            state = tempState;                                          //update the original state to the updated state
        }
    }

    return Token(errorTk, "No Tokens Returned", line);          //if no tokens were found, return a specific error token

}
