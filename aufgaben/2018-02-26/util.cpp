//a collection of some functions that might come in handy during these
//assignemnts
#include <string>
#include <sstream>

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
    {


//check if exactly one argument was provided in the command line
bool one_arg(int argc)
{
    //if no args are given: argc == 1 (filename)
    if (argc != 2)
        return false;
    return true;
}
