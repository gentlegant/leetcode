#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return help(root,root);
    }
private:
    bool help(TreeNode *p,TreeNode *q){
        if(bool(p)^bool(q))
            return false;
        if(!(p||q))
            return true;

        if(p->val!=q->val)
            return false;

        return help(p->left,q->right) && help(p->right,q->left);
     




    }
};