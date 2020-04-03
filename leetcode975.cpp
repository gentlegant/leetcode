
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <string >
#include <windows.h>
#include <set>

using namespace std;

//23114

//index 23014
class Solution
{
    void jump(int from, set<pair<int, int>> &s1, set<pair<int, int>> &s2, vector<int> &A, vector<bool> &dp1, vector<bool> &dp2)
    {
        auto kk = s1.find(pair<int, int>(A[from], from));
        kk++;
        if (kk == s1.end())
        {
            dp1[from] = false;
        }
        else
            dp1[from] = dp2[kk->second];
        kk = s2.find(pair<int, int>(-A[from], from));
        kk++;
        if (kk == s2.end())
        {
            dp2[from] = false;
        }
        else
            dp2[from] = dp1[kk->second];
    }

public:
    int oddEvenJumps(vector<int> &A)
    {

        set<pair<int, int>> s1, s2;
        s1.insert(pair<int, int>(A.back(), A.size() - 1));
        s2.insert(pair<int, int>(-A.back(), A.size() - 1));
        vector<bool> dp1(A.size(), false), dp2(A.size(), false);
        dp1.back() = true, dp2.back() = true;
        for (int i = A.size() - 2; i >= 0; i--)
        {
            s1.insert(pair<int, int>(A[i], i));
            s2.insert(pair<int, int>(-A[i], i));
            jump(i, s1, s2, A, dp1, dp2);
        }
        for (auto i : dp1)
            cout << i << ":";
        return accumulate(dp1.begin(), dp1.end(), 0);
    }
};

class Solution1
{
public:
    int oddEvenJumps(vector<int> &A)
    {
        vector<int> sta, sta1;

        vector<int> next(A.size()), next1(A.size());
        cout << "!!";
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << endl;
            while (!sta.empty() && A[i] < A[sta.back()])
                sta.pop_back();
            if (!sta.empty())
                next[sta.back()] = i;
            sta.push_back(i);
            cout << "sta:";
            for (auto i : sta)
                cout << i << " ";
            cout << endl;
            while (!sta1.empty() && A[i] > A[sta1.back()])
                sta1.pop_back();
            if (!sta1.empty())
                next1[sta1.back()] = i;
            sta1.push_back(i);
            cout << "sta1:";
            for (auto i : sta)
                cout << i << " ";
            cout << endl;
        }
        for (int i = 0; i < sta.size() - 1; i++)
            next[sta[i]] = sta[i + 1];
        for (int i = 0; i < sta1.size() - 1; i++)
            next1[sta1[i]] = sta1[i + 1];
        next[sta.back()]=A.size();
        next1[sta1.back()]=A.size();
        for (auto i : next)
            cout << i << " ";


        cout << endl;
        for (auto i : next1)
            cout << i << " ";
        return 0;
    }
};

int main()
{
    // Solution1 a;
    // vector<int> b = {1, 2, 3, 2, 1, 4, 4, 5};
    // //vector<int> b={10,13,12,14,15};
    // cout << endl
    //      << endl
    //      << a.oddEvenJumps(b);
    int i=2;
    auto k=[i](int p)->int{return p+i;};
    cout<<k(5);

    return 0;
}