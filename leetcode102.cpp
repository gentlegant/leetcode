#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode* >> q;
        vector<vector<int>> res;
        int level=0;
        q.push(pair<int,TreeNode*>({1,root}));
        vector<int> tmp;
        while (!q.empty())
        {
        
       
            auto t=q.front();
            q.pop();
            if(!t.second)
                continue;
            if(level<t.first){
                
                level=t.first;
                res.push_back(tmp);
                tmp.clear();

            }
            tmp.push_back(t.second->val);

            q.push(pair<int,TreeNode*>(t.first+1,t.second->left)   );
            q.push(pair<int,TreeNode*>(t.first+1,t.second->right)   );

            /* code */
        }
        
        return res;
    }
};