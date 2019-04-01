#include "scanner.h"
#include "testScanner.h"
using namespace std;

int main(int argc, char* argv[]) {

    std::string filename, ifnoname, word;                                            // string for the name of the file,
                                                        // and a string to store keyboard entry if no string is provided

    char characters;

    if (argc == 2) {                                   //if the user enters a filename, assign it to the string filename
        filename = argv[1];
    }
    if (argc < 2) {                      //if the user doesn't enter a filename, read from keyboard into string ifnoname
        ofstream tempfile;
        getline(cin, ifnoname);                                                     //reads keyboard input into ifnoname
        tempfile.open("temp.sp19");                       //creates a temporary file for keyboard inputs to be stored in
        tempfile << ifnoname;
        tempfile.close();
        filename = "temp";                                                        // sets filename to the temporary file
    }
    if (filename.find(".sp19") != string::npos){               //checks if file someone entered has .sp19 and removes it
        filename.erase(0, filename.find(".sp19"));
    }

    ifstream file((filename + ".sp19").c_str());

    if(!file){                                                                  //if the file does not exit, throw error
        cout << "ERROR: File does not exist." << endl;
        return 0;
    }
    else if(file.peek() == std::ifstream::traits_type::eof()){                            //throw error if file is empty
        cout << "ERROR: File is empty." << endl;
        return 0;
    }
    file.close();
    filename = filename+".sp19";                                                       //append .sp19 to filename passed

    ifstream read;
    read.open((filename).c_str());                                                                           //open file
    testScanner(read);                                               //pass the file to testScanner() in testScanner.cpp
    read.close();                                                                                       //close the file

}