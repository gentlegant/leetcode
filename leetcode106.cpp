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


class Solution {
public:
    vector<int>::iterator test;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * root=NULL;
        test=inorder.begin();
        help(root,inorder.begin(),inorder.end(),postorder.begin(),postorder.end());

        return root;




    }
private: 
    void help(TreeNode *&root,
    vector<int>::iterator m1,vector<int>::iterator n1,
    vector<int>::iterator m2,vector<int>::iterator n2){
        if(m1==n1)
            return;

        root=new TreeNode( *(n2-1));
  
        auto mid=find(m1,n1,*(n2-1));
     
        help(root->left,m1,mid,m2,  mid-m1+  m2   );
        help(root->right,mid+1,n1,  mid-m1+  m2 ,n2-1);

        // help(root->left,m1+1,mid-m2+m1+1,m2,mid );
        // help(root->right,mid-m2+m1+1,n1,mid+1,n2);
    }
};


int main(){

    vector<int> a={9,3,15,20,7};
    vector<int> b= {9,15,7,20,3};
    Solution c;
    c.buildTree(a,b);

    return 0;


}