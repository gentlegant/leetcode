#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <windows.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> q1, q2;
        q1.push(root);
        int res = 0;
        while (true)
        {
            while (!q1.empty())
            {
                auto p = q1.front();
                q1.pop();
                if (!p)
                    continue;
                if (!p->left && !p->right)
                    return res;
                q2.push(p->left);
                q2.push(p->right);
            }
            res++;
            while (!q2.empty())
            {
                auto p = q2.front();
                q2.pop();
                if (!p)
                    continue;
                if (!p->left && !p->right)
                    return res;
                q1.push(p->left);
                q1.push(p->right);
            }
            res++;
        }
        return -1;
    }
};