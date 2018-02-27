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
            c++;
            previous_pos_is_space = false;
            continue;
        }
        if (*c == ' ')
            previous_pos_is_space = true;
        c++;
    }
    cout << "words: " << words << endl;

    //getting length of each word
    // int l[words];
    int* l = new int[words];
    int w = 0;
    int wlen = 0;
    bool word = false;
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
            word = true;
            wlen = 0;
            previous_pos_is_space = false;
        }
        if (*c == ' ')
        {
            previous_pos_is_space = true;
            word = false;
            c++;
            continue;
        }
        if (word)
            wlen++;
        c++;
    }
    if (wlen != 0 && w < words)
        l[w] = wlen;


    // const char* e = cstr;
    // while (e != cstr + length-1)
    // {
    //     if (*e == ' ')
    //     {
    //         if (new_word)
    //         {
	//             if (v >= words)
	//             {
	//                 cerr << "v >= words !!" << endl;
	//                 break;
	//             }
	//             l[v] = wlen;
	//             wlen = 0;
	//             v++;
    //             new_word = false;
    //         }
    //         e++;
    //         continue;
    //     }
    //     if (!new_word)
    //         new_word = true;
    //     wlen++;
    //     e++;
    // }
	// if (wlen != 0)
	// {
	//     l[v] = wlen;
	//     if (v >= words)
	//         cerr << "v >= words" << endl;
	// }
	//print length of each word
    for (int i = 0; i < words; i++)
        cout << "Länge Wort " << i+1 << ": " << l[i] << endl;


    // int l = 256;

    //extracting words
    //initializing array for words
	char** word_arr = new char* [words];
    for (int w = 0; w < words; w++)
        word_arr[w] = new char [l[w]];
        // word_arr[w] = new char [256];
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

    //     while (*d == ' ')
    //         d++;
    //     for (int i = 0; *d != ' '; i++, d++)
    //         word_arr[w][i] = *d;
    //     w++;
    // }

    //printing result
    for (int w = 0; w < words; w++)
        cout << "Wort Nummer " << w+1 << ": " << word_arr[w] << endl;

	delete[] l;
	cerr << "l deleted" << endl;
	delete[] word_arr;
}
