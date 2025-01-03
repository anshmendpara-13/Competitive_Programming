#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        this->val = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode *createBST(vector<int> &values, int start, int end)
{
    sort(values.begin(), values.end());
    if (start > end)
    {
        return nullptr;
    }
    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(values[mid]);

    root->left = createBST(values, start, mid - 1);
    root->right = createBST(values, mid + 1, end);

    return root;
}

TreeNode *createbinarytree(vector<int> &values)
{
    if (values.empty())
        return nullptr;

    TreeNode *root = new TreeNode(values[0]);

    queue<TreeNode *> q;
    q.push(root);

    int index = 1;

    while (index < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (index < values.size())
        {
            current->left = new TreeNode(values[index]);
            q.push(current->left);
            index++;
        }
        if (index < values.size())
        {
            current->right = new TreeNode(values[index]);
            q.push(current->right);
            index++;
        }
    }
    return root;
}

int calculatediameter(TreeNode *root, int &diameter)
{
    if (root == nullptr)
        return 0;

    int leftheight = calculatediameter(root->left, diameter);
    int rightheight = calculatediameter(root->right, diameter);

    diameter = max(diameter, leftheight + rightheight);
    return 1 + max(leftheight, rightheight);
}

int main()
{

    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    // TreeNode *root = createbinarytree(values);
    TreeNode *root = createBST(values, 0, n - 1);

    int diameter = 0;
    calculatediameter(root, diameter);

    cout << diameter + 1 << endl;

    return 0;
}