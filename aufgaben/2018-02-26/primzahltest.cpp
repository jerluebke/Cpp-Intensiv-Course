#include <iostream>
#include "../util.h"
//#include "stdafx.h"

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
    if (!n_arg(argc, 2))
        return 0;

    //#ifdef DEBUG
    cout << "converting to int..." << endl;
    //#endif
    /*
    try
    {
        int a = arg_to_int(argv[1]);
    }
    catch (const invalid_argument& ex)
    {
        cout << ex.what() << endl;
        return 0;
    }
    */
    int a = arg_to_int(argv[1]);

    if (a == -1)
    {
        cout << "Not an Integer..." << endl;
        return 1;
    }

    //#ifdef DEBUG
    cout << "checking if " << a << " is positiv..." << endl;
    //#endif
    if (!int_is_pos(a))
        return 0;

    unsigned n = a;

    //#ifdef DEBUG
    cout << "checking if " << n << " is prim..." << endl;
    //#endif
    if (!is_prim(n))
    {
        cout << a << " is not prim..." << endl;
        return 0;
    }

    cout << a << " is prim!" << endl;
	cin.get();
    return 0;
}
