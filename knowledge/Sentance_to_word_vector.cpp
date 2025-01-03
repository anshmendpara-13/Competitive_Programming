#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int isPrefixOfWord(string sentence, string searchWord)
{
    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word)
        words.push_back(word);

    int ct = 1;
    for (string word : words)
    {
        if (word.size() < searchWord.size())
        {
            ct++;
            continue;
        }
        if (word.substr(0, searchWord.size()) == searchWord)
            return ct;
        
        ct++;
    }
    return -1;
}

vector<string> sentenceToWordVector(const string &sentence)
{
    vector<string> words;
    stringstream ss(sentence);
    string word;

    while (ss >> word)
    {
        words.push_back(word);
    }

    return words;
}

int main()
{
    string sentence;
    getline(cin, sentence);

    vector<string> words = sentenceToWordVector(sentence);

    for (const string &word : words)
    {
        cout << word << endl;
    }

    string searchWord;
    cin >> searchWord;
    int ans = isPrefixOfWord(sentence, searchWord);
    cout << ans << endl;

    return 0;
}
