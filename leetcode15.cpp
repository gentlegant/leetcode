#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,vector<int>> m;
        vector<vector<int>> res;
        for(int  i=0;i<nums.size() ;i++){
       
                m[nums[i]].push_back(i);
        }
        int size=nums.size();
        for(int i=0;i<size-2;i++){
            for(int j=i+1;j<size-1;j++){
                auto find=m.find(-nums[i]-nums[j]);
                if(find!=m.end()){
                    auto& v=find->second;
                    auto upper= upper_bound(v.begin(),v.end(),j);
                    if(upper!=v.end())
                    res.push_back(vector<int>{nums[i],nums[j],-nums[i]-nums[j]});
                }
            }
        }
        
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> vc{-1, 0, 1, 2, -1, -4};
    auto res = a.threeSum(vc);
    for (auto &v : res)
    {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
