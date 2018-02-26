#include <iostream>
#include <cmath>
#include "../util.h"

using namespace std;


//check if given input satisfies requierements
//converts input to int and returns it
//in case of failure returns -1
int check_input(int argc, char** argv)
{
    int a  = 0;

    if (!n_arg(argc, 1))
        return -1;

    try
    {
        a = arg_to_int(argv[1]);
    }
    catch (const invalid_argument& ex)
    {
        cerr << ex.what() << endl;
        return -1;
    }

    if (!int_is_pos(a))
        return -1;

    return a;
}


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


void print_without_power(unsigned int i)
{
    cout << i << " ";
}

void print_with_power(unsigned int i, unsigned int power)
{
    cout << i << "^" << power;
}

void print_prim_factors(unsigned int n, bool power)
{
    bool start = true;
    int cnt = 0;
    cout << n << " = ";
    for (unsigned int i = n; i >=2; i--)
    {
        bool prim = false;
        if (power)
            cnt = 0;
        while (is_prim(i) && n%i == 0)
        {
            if (!start)
                cout << "* ";
            if (start)
                start = false;
            if (power)
                cnt++;
            else
                print_without_power(i);
            n = n/i;
            prim = true;
        } 
        if (prim && power)
        {
            print_with_power(i, cnt);
            prim = false;
        }
    }
}
