

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

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> res(A.size());
        auto p1 = lower_bound(A.begin(), A.end(), 0);
        auto p2 = reverse_iterator<vector<int>::iterator>(p1 );
        for (int i = 0; i < A.size(); i++)
        {
            if (p2 == A.rend() || (p1!=A.end()&&(*p1 * *p1) < (*p2 * *p2)))
            {
                res[i] = *p1 * *p1;
                p1++;
            }
            else
            {
                res[i] = *p2 * *p2;
                p2++;
            }
        }

     
        return res;
    }
};

int main(){

    Solution a;
    vector<int> b={-4};
   auto k= a.sortedSquares(b);
    for(auto i:k)
        cout<<i<<" ";
}