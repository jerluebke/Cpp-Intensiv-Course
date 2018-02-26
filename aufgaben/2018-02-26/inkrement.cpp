#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "This programm takes exactly one argument..." << endl;
        return 0;
    }
    int a;
    string arg = argv[1];
    istringstream ss(arg);
    ss >> a;
    if (ss.fail())
    {
        cout << "Input is not an Integer..." << endl;
        return 0;
    }
    cout << ++a << endl;
    return 0;
}
