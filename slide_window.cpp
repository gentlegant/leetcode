// #借用 单调 队列

// # Description

// # 给定一个整型数组arr和一个大小为w的窗口，窗口从数组最左边滑动到最右边，每次向右滑动一个位置，求出每一次滑动时窗口内最大元素的和。

// # Input

// # 输入的第一行为数组，每一个元素使用空格隔开；第二行为窗口大小。

// # Output

// # 输出一个值。

// # Sample Input 1

// # 4 3 5 4 3 3 6 7
// # 3

// # Sample Output 1

// # 27

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

int get_window_max_sum(vector<int> &nums, int N)
{
    deque<int> q;
    int res = 0;
    for (int i=0;i<nums.size() ; i++)
    {
        //维护一个 队头 恒大的队列
        while (!q.empty() && nums[i] > q.back())
            q.pop_back();
        q.push_back(nums[i]);
        if(q.size()==N+1)
            q.pop_front();
        if(i>=N-1)
            res+=q.front();
    }
    return res;
}

int main()
{
    vector<int> nums;
    int N, res = 0;
    readinput(nums,N);

 
    cout << get_window_max_sum(nums, N);

    return 0;
}