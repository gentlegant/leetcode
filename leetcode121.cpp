#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>

#include <windows.h>
using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//         vector<int> record_max;
//         int max_=0,res=0 ,n=prices.size() ;
//         for(auto i=prices.rbegin();i!=prices.rend();i++){
//             max_=max(max_,*i);
//             record_max.push_back(max_);
//         }
//         for(int i=0;i<n;i++){
//             res=max(res,record_max[n-1-i]-prices[i] );


//         }

//         return res;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0,buy=INT_MIN;
        for(auto i:prices){
            sell=max(sell,i+buy);
            buy=max(buy,-i);
        }
        return sell;
    }
};




int main(){





}