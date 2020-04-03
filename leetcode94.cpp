#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
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
    stack<TreeNode*> s;
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if(!root)
            return res;
        s.push(root);
        while(!s.empty() ){
            while(!s.empty() && s.top()->left){
                s.push(  s.top() ->left        );
            }
            cout<<s.top()->val <<endl;
            res.push_back( s.top()->val  );
            auto rem=s.top();
            s.pop();
            if(rem->right){
               
                s.push(rem->right);
            };

        Sleep(1000);
        //_sleep(1000);
        }



        return res;

    }
};

int main()
{
    TreeNode *a=new TreeNode(1);
        TreeNode *b=new TreeNode(2);
    a->right=b;

    TreeNode *c=new TreeNode(3);
    b->left=c;
        TreeNode *d=new TreeNode(4);

    Solution ee;
    ee.inorderTraversal(a);
    return 0;
}