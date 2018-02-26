#include <iostream>
#include <string>
#include <sstream>
#include "util.h"

using namespace std;


bool is_prim(unsigned int n)
{
    if (n == 1)
        return false;
    for (unsigned int i = 2; i*i <= n; i++)
    {
        if (is_prim(i) && n%i == 0)
            return false;
    }
    return true;
}


int main(int argc, char** argv)
{
    if (!one_arg(argc))
        return 0;
    string arg = argv[1];
    istringstream ss(arg);
    return 0;
}
