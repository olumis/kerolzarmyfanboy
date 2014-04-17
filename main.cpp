#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream file("input.txt", ios::in);

    if (!file.is_open())
    {
        cout << "File missing" << endl;

        return 0;
    }

    string raw;

    while (getline(file, raw))
    {
        stringstream rawstream(raw);

        string token, line;

        while (rawstream >> token)
        {
            line += token + " "; // reconstruct the line and make sure they are separated with one space only
        }

        line.erase( line.length() - 1 ); // delete the last space character

        string::iterator it; int count = 0;

        for (it = line.end(); it != line.begin(); --it) // scan from the end of the string (right to left)
        {
            if (*it == ' ') // identify space as the token
            {
                if (count < 3) // we know the 3 columns from the right is not the student name
                {
                    cout << line.substr(  distance(line.begin(), it) + 1 ) << endl;

                    line.erase( distance(line.begin(), it) + 1 ); // erase everything on the right side

                    count++;
                }
                else
                {
                    cout << line << endl; // this is the last column which is the name

                    break;
                }
            }
        }

        cout << endl;
    }

    file.close();

    return 0;
}
