#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        int res=0;
        sort(pairs.begin(),pairs.end(), [](vector<int> &p1,vector<int> &p2)->bool{return  (p1[1]<p2[1])||(p1[1]==p2[1] && p1[0]<p2[0]);});
        int tmp=INT_MIN;
        for(auto pair:pairs){
            if(pair[0]>tmp){
                tmp=pair[1];
                res++;
            }
        }
        return res;
    }
};