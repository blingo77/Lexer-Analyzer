#include <iostream>
#include <fstream>
#include <sstream>

/*

PUT ANY SOURCE FILES TO BE READ IN THE OUTPUT FOLDER

*/

int main(int argc, char **argv){

    if(argc < 2){
        std::cout << "Enter source file";
        exit(1);
    }
    
    std::cout << "Reading from the file name: " << argv[1] << std::endl;

    // Gets file name from the comand line
    std:: ifstream sourceFileStream (argv[1]);

    // checks if the file can be opened
   if (!sourceFileStream.is_open()) {
        std::cerr << "Unable to open file: " << argv[1] << std::endl;
        return 1;
    }

    // Will store all the text
    std::stringstream buffer;

    char temp;

    while(sourceFileStream.get(temp)){
        
        // adds each character from the source file into buffer
        buffer << temp;
    }

    // stores buffer into a string
    std::string sourceCode = buffer.str();

    std:: cout << "This is the source code: " << std:: endl << sourceCode;

    return 0;
}