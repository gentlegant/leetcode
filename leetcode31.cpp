#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int k=nums.size()-2;
        while(k!=-1 && nums[k]>=nums[k+1])
                k--;
        int l=nums.size()-1;
        while(nums[l]<=nums[k])
            l--;
        swap(nums[k],nums[l]);
        reverse(nums.begin()+k+1,nums.end());
    }
};

int main(int argc, char const *argv[])
{
    vector<int> b={1,2,3,4};
    Solution a;
 
    for(int i=0;i<10;i++){
        a.nextPermutation(b);
        for(auto ii:b)
            cout<<ii<<" ";
        cout<<endl;
    }
    return 0;
}
