#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        for (auto i = nums.begin(); i < nums.end() - 2; i++)
        {
            auto rem = i + 2, j = rem;
            
            while (j != nums.end() && *j == *i){
            j=nums.erase(j);
            }

                
          
        }
        return nums.size();
    }
};

int main()
{
    Solution a;
    vector<int> c ={0,0,1,1,1,1,2,3,3};
    auto b = a.removeDuplicates(c);
    for (auto i : c)

        cout << i << " ";

    return 0;
}