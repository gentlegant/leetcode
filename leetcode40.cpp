#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<vector<int>>> dp(target+1);
        dp[0]={{}};
    
        for(auto n:candidates) 
            for(int i=0;i+n<=target;i++) {
                auto& l=dp[i];
                auto& h=dp[n+i];
                for(auto lis:l){
                    //lis里用了多少了
                    int c1=count(lis.begin(),lis.end(),n);
                    //本身有多少
                    int c2=count(candidates.begin(),candidates.end(),n);
                    if(c1==c2)
                        continue;
                    lis.push_back(n);
                    if(find(h.begin(),h.end(),lis)!=h.end())
                        continue;
                  
                    h.push_back(lis);
                 
                }
                //给dp去重
               
            }
            
        return dp.back();
    }
};
int main(int argc, char const *argv[])
{
  

    Solution a;

    vector<int> b={1,1,2,2,2,3,4,4,4};
    auto k=a.combinationSum2(b,6);
    for(auto& i:k){
        for(auto &ii:i)
            cout<<ii<<" ";
        cout<<endl;

    }
    return 0;
}



