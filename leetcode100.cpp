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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p&&!q)
            return true;

        if(bool(p)^bool(q))
            return false;

        if(p->val!=q->val)
            return false;

        
        return isSameTree(p->left,p->left) && isSameTree(p->right,p->right); 

    }
};