// #include "binary_search.h"
#include <iostream>
#include <cstdlib>

template <typename T>
const T binarySearch(const T *A, const int length, const T value)
{
    int start = 0;
    int end = length - 1;
    while (start <= end)
    {
        int middle = start + ((end - start) / 2);
        if (A[middle] == value)
            return middle;
        else if (A[middle] < value)
            start = middle + 1;
        else // A[middle] > value
            end = middle - 1;
    }
    return -1;
}


int main()
{
	const int I[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23 };
	const int lenI = 9;
	const int intValues[] = { 9, 3, 19, 2, 24 };

	const double D[] = { 2.3, 4.1, 6.8, 9.0, 12.1, 15.68, 21.3 };
	const int lenD = 7;
	const double doubleValues[] = { 1.1, 4.1, 12.1, 32.4, 6.8, 42, 9.0 };

	std::cout << "Integers:\n";
	for (int i = 0; i < lenI; ++i)
		std::cout << "\t" << i << ": " << I[i] << "\n";
	std::cout << "\n";
	std::cout << "Suche:\n";
	for (int i : intValues)
		std::cout << "\t" << i << ": " << binarySearch(I, lenI, i) << "\n";
	std::cout << "\n\n";

	std::cout << "Doubles:\n";
	for (int i = 0; i < lenD; ++i)
		std::cout << "\t" << i << ": " << D[i] << "\n";
	std::cout << "\n";
	std::cout << "Suche:\n";
	for (double i : doubleValues)
		std::cout << "\t" << i << ": " << binarySearch(D, lenD, i) << "\n";
	std::cout << "\n\n";

	std::system("pause");
}
