#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

#include <windows.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oldsell=0,oldbuy=INT_MIN,buy,sell;
        for(auto i:prices){
            buy=max(oldbuy,oldsell-i);
            sell=max(oldsell,oldbuy+i);
            oldbuy=buy;
            oldsell=sell;
        }
        return oldsell;
    }
};