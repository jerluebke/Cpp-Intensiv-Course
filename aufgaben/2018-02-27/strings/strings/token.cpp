#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str;
    cout << "Enter String: ";
    getline(cin, str);
    const char* cstr = str.c_str();
    cout << "Input: " << cstr << endl;
    cout << str.length() << endl;
    // for (int i = 0; i < (int) str.length(); i++)
    // {
    //     if
    // }

    // while (cstr != &str.at(str.length()+1))
    // {
    //     cstr++;
    // }

    // for (char* c = cstr; c != cstr+str.length(); c++)
    // {
    //
    // }

    //ignore leading and trailing whitespace
    int length = (int)str.length();
    int start = 0;
    int end = length-1;
    while (str.at(start) == ' ')
        start++;
    while (str.at(end) == ' ')
        end--;

    //counting words
    int i = start;
    int words = 0;
    while (i <= end)
    {
        if (str.at(i) == ' ')
        {
            words++;
            while (str.at(i+1) == ' ')
                i++;
        }
        i++;
    }
    words++;
    cout << "words: " << words << endl;

    //extracting words
    string word_arr[words];
}
