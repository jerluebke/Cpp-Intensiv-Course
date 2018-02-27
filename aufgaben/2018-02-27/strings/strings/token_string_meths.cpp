#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string str;
    // string str = "string  s";
    cout << "Enter String: ";
    getline(cin, str);
    cout << endl;

    vector<string> words;
	size_t marker = 0;
    while (str != "")
    {
        marker = str.find(' ');
        if (marker == string::npos)
            marker = str.length();
		if (marker == 0)
			str.erase(0, 1);
		else
        {
			words.push_back(str.substr(0, marker));
			str.erase(0, marker);
			marker = 0;
		}
    }

    for (size_t i = 0; i < words.size(); i++)
        cout << "Wort " << i+1 << ": " << words[i] << endl;
    cout << "Der Input wurde in " << words.size() << " Token zerlegt" << endl;
}
