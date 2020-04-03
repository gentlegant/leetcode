#include <vector>
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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> res;
             if (find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end())
            res.push_back(root);
        visit(root,res,to_delete);
        return res;
    }
private:
    void visit(TreeNode *&root, vector<TreeNode *> &res, vector<int> &to_delete)
    {
        if(!root)
            return ;
        visit(root->left, res, to_delete);
        visit(root->right, res, to_delete);

        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end())
        {
            if(root->left)
                res.push_back(root->left);
            if(root->right)
                res.push_back(root->right);
            root = NULL;
        }
    }
};