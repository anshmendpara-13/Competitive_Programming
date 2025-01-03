#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int collectLeaves(TreeNode *root, vector<vector<int>> &result)
{
    if (!root)
        return -1;
    int leftDepth = collectLeaves(root->left, result);
    int rightDepth = collectLeaves(root->right, result);
    int currentDepth = max(leftDepth, rightDepth) + 1;
    if (currentDepth == result.size())
    {
        result.push_back({});
    }
    result[currentDepth].push_back(root->val);
    return currentDepth;
}

vector<vector<int>> findLeaves(TreeNode *root)
{
    vector<vector<int>> result;
    collectLeaves(root, result);
    return result;
}

TreeNode *buildTree(const vector<int> &values)
{
    if (values.empty())
        return nullptr;

    TreeNode *root = new TreeNode(values[0]);

    queue<TreeNode *> q;

    q.push(root);

    int index = 1;

    while (!q.empty() && index < values.size())
    {
        TreeNode *current = q.front();
        q.pop();
        if (values[index] != -1)
        {
            current->left = new TreeNode(values[index]);
            q.push(current->left);
        }
        index++;
        if (index < values.size() && values[index] != -1)
        {
            current->right = new TreeNode(values[index]);
            q.push(current->right);
        }
        index++;
    }
    return root;
}

void printResult(const vector<vector<int>> &result)
{
    for (const auto &level : result)
    {
        cout << "[";
        for (int i = 0; i < level.size(); ++i)
        {
            cout << level[i];
            if (i < level.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;
}

int main()
{
    vector<int> treeValues = {1, 2, 3, 4, 5};
    TreeNode *root = buildTree(treeValues);
    vector<vector<int>> leaves = findLeaves(root);
    cout << "Leaves of the tree from bottom to top: ";
    printResult(leaves);
    return 0;
}
