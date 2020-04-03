#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * root;

        help(root, preorder.begin(),preorder.end(),inorder.begin(),inorder.end());

        return root;




    }
private: 
    void help(TreeNode *&root,
    vector<int>::iterator m1,vector<int>::iterator n1,
    vector<int>::iterator m2,vector<int>::iterator n2){
        if(m1==n1)
            return;

        root=new TreeNode( *m1);
        
        auto mid=find(m2,n2,*m1);

        help(root->left,m1+1,mid-m2+m1+1,m2,mid );
        help(root->right,mid-m2+m1+1,n1,mid+1,n2);
    }
};