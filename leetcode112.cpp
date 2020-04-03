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
    bool hasPathSum(TreeNode *root, int sum)
    {
        cout<<root->val<< ": "<<sum <<endl;
        if (!root)
            return false;
        if (root->left && hasPathSum(root->left, sum - root->val))
            return true;
        if (root->right && hasPathSum(root->right, sum - root->val))
            return true;
        if (!root->left  &&!root->right &&  root->val == sum)
            return true;
        return false;
    }
};
int main()
{
    Solution a;
    TreeNode *b=new TreeNode(5);
  
    TreeNode *c=new TreeNode(4);

    TreeNode *d=new TreeNode(8);

    TreeNode *e=new TreeNode(11);

    TreeNode *f=new TreeNode(13);

    TreeNode *g=new TreeNode(4);

    TreeNode *h=new TreeNode(7);

    TreeNode *i=new TreeNode(2);

    TreeNode *j=new TreeNode(1);
  b->left=c;
  b->right=d;
  c->left=e;
  d->left=f;
  d->right=g;
  e->left=h;
  e->right=i;
  g->right=j;
    a.hasPathSum(b, 5);
    return 0;

  
}               
    //             5
    //         4       8
    //     11        13   4
    //  7      2              1