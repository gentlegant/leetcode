#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) -> bool { return a[0] < b[0]; });
        vector<vector<int>> res;

        auto tmp = intervals[0];
        for (auto p : intervals)
        {
           
            if (p[0] <= tmp[1])
            {
                tmp[1] = max(tmp[1],p[1]);
            }
            else
            {
                
                res.push_back(tmp);
                tmp = p;
            }
        }
        res.push_back(tmp);
        return res;
    }
};


int main()
{

    Solution a;
    vector<vector<int>> b={{1,3},{2,6},{8,10},{15,18}};
    auto bb=a.merge(  b);   
    for(auto kk:bb){
        cout<<kk[0]<<" "<<kk[1]<<endl;

    }
}