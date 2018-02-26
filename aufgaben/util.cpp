//a collection of some functions that might come in handy during these
//assignemnts
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;


//convert char pointer (as taken from the command line) and convert it to an
//int
//throw exception, if no int was given
//(I know, exceptions weren't taught yet, but I would like to avoid writing the
//same piece of code multiple times...)
int arg_to_int(char* cptr)
{
    int a;
    string arg = cptr;
    istringstream ss(arg);
    ss >> a;
    if (ss.fail())
        throw invalid_argument("This programm requieres a positive Integer as input...");
        //return -1;
    return a;
}


//check if exactly n arguments were provided in the command line
bool n_arg(int argc, int n) {
    //if no args are given: argc == 1 (filename)
    if (argc != n+1)
    {
        cerr << "This programm takes exactly " << n << " arguments..." << endl;
        return false;
    }
    return true;
}


//check if given integer is positiv
bool int_is_pos(int a)
{
    if (a > 0)
        return true;
    cerr << "Input has to be positiv..." << endl;
    return false;
}
