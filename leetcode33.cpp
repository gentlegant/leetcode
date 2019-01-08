#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1



class Solution1 {
      //[l,r]
      int findpivot( vector<int>& nums,int left,int right){
          int l=0,r=nums.size()-1;
          while(true){
              //最右都大于最左，已经有序了
              if(l==r-1)
                return nums[l]<nums[r]?l:r;
              if(nums[l]<nums[r] || l==r) 
                return l;
              int mid=(l+r)/2;
              //左边有序了，说明右边无序
              //不用看左边了
              if(nums[mid]>nums[l])
                l=mid+1;
              else
                r=mid;
          }

    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int pivot=findpivot(nums,0,nums.size()-1);
        vector<int>::iterator res;
        if(target>nums.back())
            res=lower_bound(nums.begin(),nums.begin()+pivot,target);
        else
            res=lower_bound(nums.begin()+pivot,nums.end(),target);
        if(*res==target)
            return res-nums.begin();
        return -1;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
        
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            //flag1 左边是否you问题 0 for 没有  flag2  目标在mid哪边 0 for left  flag3 target 是否小于 left 0 for 小于
            bool flag1=nums[mid]<nums[l],flag2=nums[mid]<target,flag3=nums[l]<=target;
            if(flag1&&!flag2||flag1&&flag2&&flag3||!flag1&&!flag2&&flag3)
                r=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> b={1,2,3,4,5,0}; 
    Solution a;
    int c=a.search(b,5);
    cout<<c;
    
    return 0;
}
