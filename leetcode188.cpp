#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

#include <windows.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> sell(k,0),buy(k,INT_MIN);
        for(auto i:prices){
            for(int i=k-1;i>0;i--){
                buy[k]=max(buy[k],sell[k-1]-i);
                sell[k]=max(sell[k],buy[k]+i);
            }
          
        }
        return sell[k-1];
    }
};