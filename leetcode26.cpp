#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size()){
            while(nums[j+1]==nums[j])
                j++;
            nums[i++]=nums[j++];
        }
        return i;
    }
};
class Solution1
{
	public:
		int removeDuplicates(vector<int>& nums)
		{

			return  unique(nums.begin() ,nums.end())-nums.begin();
		}
};