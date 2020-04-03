#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int kkk;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> now;
        solve(now,0,n,res);
        return res;
    }


    void solve(vector<int>  now,int m,int n,vector<vector<string>> &res){
        for(auto i:now){
            cout<<i<<" ";
        }
        cout<<endl;

        if(m==n){
            vector<string> tmp;
            for(auto i=0;i<n;i++){
                string ss(n,'.');
                ss[now[i]]='Q';
                tmp.push_back(ss);
            }
            res.push_back(tmp);

            return ;
        }

        for(int i=0;i<n;i++){
            bool flag=true;
            for(int k=0;k<now.size();k++){
                if((i==now[k] )|| abs( i-now[k])==(now.size()-k)){
                    flag=false;
                    break;
                }
            }
            if(flag){
                auto cp=now;
                cp.push_back(i);
                solve(cp,m+1,n,res);
            }
            
        }
      
    }
};

int main(){
    Solution a;
    a.solveNQueens(4);
    return 0;
}


