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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {

        vector<vector<int>> res;
        vector<int> tmp;
        help(res, root, sum, tmp);
        return res;
    }

private:
    void help(vector<vector<int>> &res, TreeNode *root, int sum, vector<int> &tmp)
    {

        if (!root)
            return;
        if (root->left)
        {
            auto cp = tmp;
            cp.push_back(root->val);
            help(res, root->left, sum - root->val, cp);
        }
        if (root->right)
        {
            auto cp = tmp;
            cp.push_back(root->val);
            help(res, root->right, sum - root->val, cp);
        }

        if (!root->left && !root->right && root->val == sum)
        {
            tmp.push_back(root->val);
            res.push_back(tmp);
        }
    }
};
int main()
{
    Solution a;
    TreeNode *b = new TreeNode(5);

    TreeNode *c = new TreeNode(4);

    TreeNode *d = new TreeNode(8);

    TreeNode *e = new TreeNode(11);

    TreeNode *f = new TreeNode(13);

    TreeNode *g = new TreeNode(4);

    TreeNode *h = new TreeNode(7);

    TreeNode *i = new TreeNode(2);

    TreeNode *j = new TreeNode(1);
    b->left = c;
    b->right = d;
    c->left = e;
    d->left = f;
    d->right = g;
    e->left = h;
    e->right = i;
    g->right = j;
   auto kk= a.pathSum(b, 22);
   for(auto i:kk){
       for(auto ii:i)
        cout<<ii<<" ";
    cout<<endl;
   }
    return 0;
}
//             5
//         4       8
//     11        13   4
//  7      2              1