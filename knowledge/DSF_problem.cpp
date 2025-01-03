#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Problem
{
public:
    Problem() {}

    bool isValid(const vector<string> &curstate)
    {
        int flag = 0;
        for (int i = 0; i < curstate.size(); ++i)
        {
            if (curstate[i] == "RE1" || curstate[i] == "RE2" || curstate[i] == "RE3")
            {
                if (i <= 4)
                {
                    if (curstate[i + 1] == "_" || curstate[i + 2] == "_")
                    {
                        flag = 1;
                    }
                }
            }
            else if (i == 5)
            {
                if (curstate[i + 1] == "_")
                {
                    flag = 1;
                }
            }

            if (curstate[i] == "RW1" || curstate[i] == "RW2" || curstate[i] == "RW3")
            {
                if (i >= 2)
                {
                    if (curstate[i - 1] == "_" || curstate[i - 2] == "_")
                    {
                        flag = 1;
                    }
                }
            }
            else if (i == 1)
            {
                if (curstate[i - 1] == "_")
                {
                    flag = 1;
                }
            }
        }
        return flag == 1;
    }

    bool isfinal(const vector<string> &curstate)
    {
        return curstate == vector<string>{"RW1", "RW2", "RW3", "_", "RE1", "RE2", "RE3"};
    }

    void print(const vector<string> &path, const string &type)
    {
        if (path.empty())
        {
            cout << "No " << type << " solution found." << endl;
            return;
        }

        vector<string> reversedPath = path;
        std::reverse(reversedPath.begin(), reversedPath.end());

        cout << type << " Solution:" << endl;
        for (int x = 0; x < reversedPath.size(); ++x)
        {
            string z = (x < 10) ? "0" : "";
            cout << "Step " << z << x << ": " << reversedPath[x] << endl;
        }
        cout << endl;
    }
};

class DFS
{
private:
    unordered_set<string> visited;
    vector<vector<string>> q;
    vector<string> start;
    Problem check;
    unordered_map<string, string> parent;

public:
    DFS() : start{"RE1", "RE2", "RE3", "_", "RW1", "RW2", "RW3"}
    {
        q.push_back(start);
    }

    vector<string> dfs(const vector<string> &node = {"RE1", "RE2", "RE3", "_", "RW1", "RW2", "RW3"})
    {
        visited.insert(str(node));

        if (check.isfinal(node))
        {
            vector<string> ans;
            string temp = str(node);
            while (temp != str(start))
            {
                ans.push_back(temp);
                temp = parent[temp];
            }
            ans.push_back(str(start));
            return ans;
        }

        vector<vector<string>> children = generate(node);
        for (const auto &child : children)
        {
            if (visited.find(str(child)) == visited.end())
            {
                vector<string> x = dfs(child);
                if (!x.empty())
                {
                    return x;
                }
            }
        }

        return {};
    }

    vector<vector<string>> generate(const vector<string> &node)
    {
        vector<vector<string>> valid;
        string par = str(node);

        for (int i = 0; i < 7; ++i)
        {
            if (node[i] == "RE1" || node[i] == "RE2" || node[i] == "RE3")
            {
                if (i <= 4)
                {
                    if (node[i + 2] == "_")
                    {
                        vector<string> nextstate = node;
                        swap(nextstate[i], nextstate[i + 2]);
                        if (visited.find(str(nextstate)) == visited.end())
                        {
                            parent[str(nextstate)] = par;
                            valid.push_back(nextstate);
                        }
                    }
                    if (i <= 5)
                    {
                        if (node[i + 1] == "_")
                        {
                            vector<string> nextstate = node;
                            swap(nextstate[i], nextstate[i + 1]);
                            if (visited.find(str(nextstate)) == visited.end())
                            {
                                parent[str(nextstate)] = par;
                                valid.push_back(nextstate);
                            }
                        }
                    }
                }
            }
            else if (node[i] == "RW1" || node[i] == "RW2" || node[i] == "RW3")
            {
                if (i >= 2)
                {
                    if (node[i - 2] == "_")
                    {
                        vector<string> nextstate = node;
                        swap(nextstate[i], nextstate[i - 2]);
                        if (visited.find(str(nextstate)) == visited.end())
                        {
                            parent[str(nextstate)] = par;
                            valid.push_back(nextstate);
                        }
                    }
                }
                if (i >= 1)
                {
                    if (node[i - 1] == "_")
                    {
                        vector<string> nextstate = node;
                        swap(nextstate[i], nextstate[i - 1]);
                        if (visited.find(str(nextstate)) == visited.end())
                        {
                            parent[str(nextstate)] = par;
                            valid.push_back(nextstate);
                        }
                    }
                }
            }
        }
        return valid;
    }

    string str(const vector<string> &state)
    {
        string result = "[";
        for (const auto &s : state)
        {
            result += "\"" + s + "\", ";
        }
        result.pop_back(); // Remove the trailing comma
        result.pop_back(); // Remove the space
        result += "]";
        return result;
    }
};

int main()
{
    Problem show;
    DFS ans_dfs;
    vector<string> path_dfs = ans_dfs.dfs();
    show.print(path_dfs, "DFS");

    return 0;
}
