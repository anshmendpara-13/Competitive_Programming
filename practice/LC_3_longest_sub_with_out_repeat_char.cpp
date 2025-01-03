#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string ans = "";
        int maxi = 0;
        for (int i = 0; i < s.length(); i++)
        {
            size_t found = ans.find(s[i]);
            if (found != string::npos)
            {
                ans.erase(0, found + 1); // Remove characters before the found position including the found character
            }
            ans += s[i];
            maxi = max(maxi, (int)ans.length());
        }
        return maxi;
    }
};

int main()
{
    Solution sol;
    string s;
    cin >> s;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
