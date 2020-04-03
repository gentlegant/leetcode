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
    bool isValidBST(TreeNode* root) {
       
        return help(root,INT64_MIN,INT64_MAX);
    }
private:
    bool help(TreeNode *root,int64_t l,int64_t r){
        if(!root)
            return true;

        if(root->val<=l ||root->val>=r)
            return false;
        return help( root->left,l ,root->val)  &&help(root->right,root->val,r);


    }
};


int main(){
    Solution a;
    
    TreeNode* b=new TreeNode(2);
    b->left=new TreeNode(1);
    b->right=new TreeNode(3);

    cout<<a.isValidBST(b);

    return 0;
}