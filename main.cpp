#include <iostream>
#include <fstream>
#include "headers/hasher.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Hasher hasher;

    fstream file;

    file.open(argv[1], ios::in);

    string fakeLine;

    int lines = 0;

    if (file.is_open())
    {
        while (getline(file, fakeLine))
        {
            lines++;
        }
        string line[lines];
        lines = 0;
        while (getline(file, fakeLine))
        {
            line[lines] = fakeLine;
            lines++;
        }
        file.close();

        const char *s1 = line->c_str();

        //This hash is incorrect
        hasher.hash(s1);
    }
}