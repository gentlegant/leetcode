// # 子数组的取值范围

// # Description

// # 给定数组arr和整数num，求arr的连续子数组中满足：其最大值减去最小值的结果大于num的个数。请实现一个时间复杂度为O(length(arr))的算法。

// # Input

// # 输入的第一行为数组，每一个数用空格隔开，第二行为num。

// # Output

// # 输出一个值。1

// # Sample Input 1
/*77
    3 6 4 3 2
    2
    */
// # Sample Output 1

// # 6

#include <iostream>
#include <deque>
#include <sstream>

#include <vector>
using namespace std;
void readinput(vector<int> &vc, int &N)
{
    string str;
    getline(cin, str);
    int tmp;
    istringstream s(str);
    while (s >> tmp)
        vc.push_back(tmp);
    cin >> N;
}

// int solve(vector<int> &arr, int &N)
// {
//     //这两个队列用于 在常数时间上维护当前 子 数组得最大值和最小值
//     deque<int> qmax;
//     deque<int> qmin;
//     int res = 0;
//     int i = 0;
//     int j = 0;

//     while (i < arr.size())
//     {
//         while (j < arr.size())
//         {
//             while (!qmax.empty() && arr[qmax.back()] < arr[j]) //求子数组的最大值。
//             {
//                 qmax.pop_back();
//             }
//             qmax.push_back(j);

//             while (!qmin.empty() && arr[qmin.back()] > arr[j]) //子数组的最小值。
//             {
//                 qmin.pop_back();
//             }
//             qmin.push_back(j);

//             if (arr[qmax.front()] - arr[qmin.front()] > N)
//             {
//                 break;
//             }
//             j++;
//         }

//         res += j - i;
    

//         if (qmin.front() == i)
//         {
//             qmin.pop_front();
//         }
//         if (qmax.front() == i)
//         {
//             qmax.pop_front();
//         }

//         i++;
//     }

//     return res;
// }


int solve(vector<int>& nums,int& N){
    int res=0;
    for (int i=0;i<nums.size();i++){
        int max_=INT32_MIN,min_=INT32_MAX;
        for(int j=i;j<nums.size();j++){
            max_=max(max_,nums[j]);
            min_=min(min_,nums[j]);
            if(max_-min_>N)
                res+=1;
        }
    }
    return res;
}

int main()
{
    vector<int> nums;
    int N;
    readinput(nums, N);
    cout << solve(nums, N);

    return 0;
}
