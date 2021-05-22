#include <iostream>
#include <fstream>
#include "headers/hasher.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    //Make a new hasher and a new fstream for our file.
    Hasher hasher;
    fstream file;

    //Open the file that was specified in the first argument
    file.open(argv[1], ios::in);

    //Check if we were able to open the file
    if (file.is_open())
    {
        //Go to the end of the file
        file.seekg(0, file.end);
        //Read where the end of the file is to get the size of the file
        int length = file.tellg();
        //Go back to the beginning of the file
        file.seekg(0, file.beg);

        //Make a buffer to store the entire file
        char *buffer = new char[length];

        //Read the entire file, then store it in the buffer
        file.read(buffer, length);

        //Hash the buffer
        hasher.hash(buffer);
    }
    else
    {
        //If we weren't able to open the file, send an error to the user.
        cout << "Failed to open file: \"" << argv[1] << "\"" << endl;
    }
}