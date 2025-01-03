#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removeSpacesAndNonAlpha(string s)
{
    string result;
    for (char c : s)
    {
        if (c != ' ' && isalpha(c))
        {
            if(toupper(c))
                c = tolower(c);
            result += c;
        }
    }
    return result;
}

int main()
{
    string input;
    getline(cin, input);

    string result = removeSpacesAndNonAlpha(input);

    cout <<  result << endl;

    return 0;
}
