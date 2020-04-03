#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        map<int,int> m;
        for(auto i:nums){
            if(m.count(i)!=0)
                m[i]+=1;
            else m[i]=1;
        }
        vector<pair<int,int>> mm(m.begin(),m.end());
        vector<int> now;
        backtrace(res,mm,0,now);
        return res;


    }
private:
    void  backtrace(vector<vector<int>> &res,vector<pair<int,int>> &mm,int n,vector<int> now){
        
        if(n==mm.size())
            return ;    
        for(int i=0;i<mm[n].second;i++){
            
            res.push_back(now);
            backtrace(res,mm,n+1,now);
            now.push_back(mm[n].first);
        }


    }
};


int main(){


    Solution a;
    vector<int> c={1,2,2};
    auto bb=   a.subsetsWithDup(c);
   
    for(vector<int> & kk:bb){
        for(int & kkk:kk)
            cout<<kkk<<" ";
        cout<<endl;
    }
    return 0;
}