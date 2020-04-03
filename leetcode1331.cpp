#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> res(arr.size());
        if(arr.empty())
        return res;
        vector<pair<int, int>> tmp;
        for (int i = 0; i < arr.size(); i++)
        {
            tmp.push_back(pair<int, int>(arr[i], i ));
        }
        sort(tmp.begin(), tmp.end(), [](pair<int, int> &p1, pair<int, int> &p2) -> bool { return p1.first < p2.first; });
        
        res[tmp[0].second] = 1;
        int indx = 1;
        for (int i = 1; i < res.size(); i++)
        {
            res[tmp[i].second] = tmp[i].first == tmp[i - 1].first ? indx : ++indx;
        }
        return res;
    }
};

struct leetcode1331
{
    /* data */
    char a;
    double b;

};








int main()
{

    Solution a;
    vector<int> vec = {100, 100, 100};
    auto b = a.arrayRankTransform(vec);
    for (auto i : b)
    {
        cout << i << " ";
    }

    return 0;
}