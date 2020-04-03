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

class Solution
{
public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        int level=0;
        
        while(!q.empty()){
            vector<int> temp;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *curr=q.front();
                temp.push_back(curr->val);
                q.pop();
                if(curr->right){
                    q.push(curr->right);
                }
                if(curr->left){
                    q.push(curr->left);
                }
            }
            if(level%2==0)
                reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};