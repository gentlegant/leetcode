#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;






class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto fir=lower_bound( intervals.begin(),intervals.end(),newInterval[0],[](vector<int> p1,int p2)->bool{return p1[1]<p2;});
        auto sec=upper_bound( intervals.begin(),intervals.end(),newInterval[1],[](int p1,vector<int> p2)->bool{return p1<p2[0];});
        newInterval[0]=min(newInterval[0],fir!=intervals.end()?(*fir)[0]:INT_MAX);
        newInterval[1]=max(newInterval[1],sec==intervals.begin()? 0 : sec[-1][1]);
        auto rem=fir;
        intervals.erase(fir,sec);
        intervals.insert(rem,newInterval);

        return intervals;
        


    }
};

int main(){

    Solution a;
    vector<vector<int>> intervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
    

    vector<int> newinterval={4,8};
    auto b=a.insert(intervals,newinterval);
    for(auto i:b){
        for(auto ii:i)
            cout<<ii<<" ";
        cout<<endl;
    }
    

}