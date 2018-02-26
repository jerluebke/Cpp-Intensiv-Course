#include <iostream>
#include "../util.h"

using namespace std;


//check if given input satisfies requierements
//converts input to int and returns it
//in case of failure returns -1
int check_input(int argc, char** argv)
{
    int a  = 0;

    //check if the requiered amount of cmd line args is present
    if (!n_arg(argc, 1))
        return -1;

    try
    {
        //convert char* to int
        a = arg_to_int(argv[1]);
    }
    //`something& st` sets a reference
    catch (const invalid_argument& ex)
    {
        cerr << ex.what() << endl;
        return -1;
    }

    if (!int_is_pos(a))
        return -1;

    return a;
}


//checking recursivly if some integer is prim
//algorithm was given in the lecture
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


void print_without_power(unsigned int i, bool start)
{
    if (!start)
        cout << "* ";
    cout << i << " ";
}

void print_with_power(unsigned int i, unsigned int power, bool start)
{
    if (!start)
        cout << "* ";
    cout << i << "^" << power;
}

void print_prim_factors(unsigned int n, bool power)
{
    //start, start2 are used for proper printing
    bool start = true;
    bool start2 = true;
    //cnt is used for getting the power of the factor
    int cnt = 0;
    cout << n << " = ";
    for (unsigned int i = n; i >=2; i--)
    {
        //prim is used to ivoke `print_with_power`
        bool prim = false;
        if (power)
            cnt = 0;
        //this condition describes a prime-factor of n
        while (is_prim(i) && n%i == 0)
        {
            if (power)
                cnt++;
            else
                print_without_power(i, start);
            //factorize n
            n = n/i;
            //after this run, print factor with power
            prim = true;
            if (start)
                start = false;
        }
        if (prim && power)
        {
            print_with_power(i, cnt, start2);
            //reset bools
            start2 = false;
            prim = false;
        }
    }
}
