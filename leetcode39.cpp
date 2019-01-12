#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        dp[0]={{}};
        for(auto n:candidates) 
            for(int i=0;i+n<=target;i++) {
                auto& l=dp[i];
               
                auto& h=dp[n+i];
                for(auto& lis:l){
                
                    h.push_back(vector<int>(lis.begin(),lis.end()));
                    h.back().push_back(n);
                }
                
            }
        return dp.back();
    }
};
int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b={2,2,3,6,7};
    auto k=a.combinationSum(b,7);
    for(auto& i:k){
        for(auto &ii:i)
            cout<<ii<<" ";
        cout<<endl;

    }
    return 0;
}

