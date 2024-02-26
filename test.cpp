#include <iostream>
#include <fstream>

int main(int argc, char **argv){


    std:: ifstream sourceFileStream (argv[1]);
    std:: string food;
    sourceFileStream >> food;

    std:: cout << "You ate: " << food;
    sourceFileStream.close();

    return 0;
}