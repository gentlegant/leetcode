#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& nums) {
        int res=0;
        
        stack<int> st;

        for(int i=0;i<nums.size();i++){
            //单调栈 ，栈顶小
            while(!st.empty() && nums[st.top()]<nums[i]){
                int bot=st.top();
                st.pop();
                //前面第一个比 st.back()大的。精髓 在这
                if(st.empty())
                    continue;
                auto left=st.top();
                auto right=i;
                //左边是最后一个比 bot大的，右边是第一个比bot大的
                res+=(
                    min(nums[right],nums[left])
                -nums[bot]
                )
                *(right-left-1);
            }
            st.push(i);
        }
        

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> hei={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution a;
    auto res=a.trap(hei);
    cout<<res;

    return 0;
}
