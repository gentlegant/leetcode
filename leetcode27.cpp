#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        auto k=remove(nums.begin(),nums.end(),val);
        cout<<k-nums.begin()<<endl;
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a={1,2,3,4,5,3,4};
    Solution b;
    auto c=b.removeElement(a,4);
    cout<<c<<endl<<endl;
    for(auto i:a)
        cout<<i<<endl;
    cout<<endl<<a.size();
    return 0;
}
