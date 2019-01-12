#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        for(auto &i:nums)
            if(i<0||i>=n)
                i=0;
        //记录i出现过（精髓）
        for(auto i:nums)
            nums[i%n]+=n;

        auto b=find_if(nums.begin()+1,nums.end(),[n](int x){return x<n;});
        return b-nums.begin();
    }
};
//基于交换，也很快
class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(auto &i:nums)
            while(i>0 && i<=n && i!=nums[i-1])
                    swap(i,nums[i-1]);
        for (int i = 0; i < nums.size(); i++) 
            if (nums[i] != i+1)
                return i+1;
        return nums.size()+1;
    }
};


int main(int argc, char const *argv[])
{
    
    vector<int> b={3,4,2,1,6};
  
    Solution2 a;
    cout<<a.firstMissingPositive(b);    
    return 0;
}
