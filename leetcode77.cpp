#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        
        help(k,n,1);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> tmp;

    void help(int k,int n,int now)
    {
        if (tmp.size() == k)
        {
            res.push_back(tmp);
            return ;
        }
        for (int i=now; i <= n; i++)
        {
           tmp.push_back(i);
           help(k,n,i+1);
           tmp.pop_back();
        }
    }
};

int main()
{

    Solution a;
    auto b = a.combine(4, 2);
    for (auto ii : b)
    {
        for (auto iii : ii)
        {
            cout << iii << ' ';
        }
        cout << endl;
    }
    return 0;
}