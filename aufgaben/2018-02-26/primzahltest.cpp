#include <iostream>
#include "prim_stuff.h"

using namespace std;


int main(int argc, char** argv)
{
    int m = check_input(argc, argv);
    if (m == -1)
        return 1;
    unsigned n = m;
    if (!is_prim(n))
    {
        cout << n << " is not prim..." << endl;
        return 0;
    }
    cout << n << " is prim!" << endl;

    return 0;
}
