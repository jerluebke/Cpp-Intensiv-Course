#include <iostream>
#include "../util.h"

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
    int a  = 0;

    if (!n_arg(argc, 1))
        return 0;

    try
    {
        a = arg_to_int(argv[1]);
    }
    catch (const invalid_argument& ex)
    {
        cerr << ex.what() << endl;
        return 0;
    }

    if (!int_is_pos(a))
        return 0;

    unsigned n = a;
    if (!is_prim(n))
    {
        cout << a << " is not prim..." << endl;
        return 0;
    }
    cout << a << " is prim!" << endl;

    return 0;
}
