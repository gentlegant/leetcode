// 字符串1

// Description

// Given a string ‘str’ of digits, find length of the longest substring of ‘str’, 
//such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.

// Input

// 输入第一行是测试用例的个数，后面每一行表示一个数字组成的字符串，例如："123123"

// Output

// 输出找到的满足要求的最长子串的长度。例如，给定的例子长度应该是 6。每行对应一个用例的结果。

// Sample Input 1

// 1
// 1538023

// Sample Output 1

// 4
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solve(string str){
    vector<int> nums;
    for(auto i:str)
        nums.push_back(i-'0');
    //记录 start，start+len 的和
    vector<vector<int>> sums;
    int sum=0;
    for(int begin=0;begin<nums.size();begin++){
        vector<int> tmp;
    
        for(int len=0;begin+len<nums.size();len++){
            sum+=nums[begin+len];
            tmp.push_back(sum);
        }
        sums.push_back(tmp);
    }


    int res=0;
    for(int len=0;len<nums.size()/2;len++){
        for(int right_begin=len+1;right_begin+len<nums.size();right_begin++)
            if(sums[right_begin-len-1][len]==sums[right_begin][len]){
                res=2*len+2;
                break;
            }
    }
    
    return res;
    
}


int main(int argc, char const *argv[])
{

    int T;
    string tmp;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>tmp;
        cout<<solve(tmp)<<endl;
    }

    return 0;
}
