#include <iostream>
#include <string>

using namespace std;


int main()
{
    // string str = "Ein Test String";
    string str;
    cout << "Enter String: ";
    getline(cin, str);
    int length = (int)str.length();
    const char* cstr = str.c_str();
    // const char input[] = "Das ist ein Teststring.";
    cout << "Input: " << cstr << endl;

    // counting words
	bool previous_pos_is_space = true;
    int words = 0;
    const char* c = cstr;
    while (c != cstr + length)
    {
        // bool state_changed = (previous_pos_is_space && *c != ' ')
        //     || (!previous_pos_is_space && *c == ' ');
        if (previous_pos_is_space && *c != ' ')
        {
            words++;
            previous_pos_is_space = false;
        }
        else if (*c == ' ')
            previous_pos_is_space = true;
        c++;
    }
    cout << "words: " << words << endl;

    //getting length of each word
    int* l = new int[words];
    int w = 0;
    int wlen = 0;
    c = cstr;
    previous_pos_is_space = true;
    while (c != cstr + length)
    {
        if (previous_pos_is_space && *c != ' ')
        {
            if (wlen != 0)
            {
                l[w] = wlen;
                w++;
            }
            wlen = 0;
            previous_pos_is_space = false;
        }
        else if (*c == ' ')
            previous_pos_is_space = true;
        if (!previous_pos_is_space)     // over_word == not previous_pos_is_space
            wlen++;
        c++;
    }
    if (wlen != 0 && w < words)
        l[w] = wlen;

	//print length of each word
    for (int i = 0; i < words; i++)
        cout << "Länge Wort " << i+1 << ": " << l[i] << endl;

    //extracting words
    //initializing array for words
	char** word_arr = new char* [words];
    for (int w = 0; w < words; w++)
        word_arr[w] = new char [l[w]];
    c = cstr;
    w = 0;
    previous_pos_is_space = true;
    while (w < words)
    {
        if (previous_pos_is_space && *c != ' ')
        {
            for (int i = 0; i < l[w]; i++, c++)
                word_arr[w][i] = *c;
			w++;
            previous_pos_is_space = false;
        }
        if (*c == ' ')
            previous_pos_is_space = true;
        c++;
    }

    //printing result
    for (int w = 0; w < words; w++)
        cout << "Wort Nummer " << w+1 << ": " << word_arr[w] << endl;

	delete[] l;
    //deleting the elemtens of word_arr
    for (int w = 0; w < words; w++)
        delete[] word_arr[w];
	delete[] word_arr;
}
