#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<string> strmax(vector<string> &a,vector<string> &b){
    int s=a[0].size()-b[0].size();
    if(s>0)
        return a;
    else if(s<0)
        return b;
        
    a.insert(a.end(),b.begin(),b.end());
    auto t=unique(a.begin(),a.end());
    a.erase(t,a.end());
    return a;

}


vector<string> solve(string &a,string &b){
    vector<string> res;
    vector<string> tmp={""};
    vector<vector<string>> dp(b.size()+1,tmp),olddp=dp;
 
    
  
    for(auto ia:a){
        for(int i=0;i<b.size();i++)
            if(ia==b[i]){
                dp[i+1]=olddp[i];
                for(auto &t:dp[i+1])
                    t.push_back(ia);

            }
            else

                dp[i+1]=strmax(dp[i],olddp[i+1]);
        olddp=dp;


    }
    return dp.back();

}
int main(){
    string a,b;
    cin>>a>>b;
    auto res=solve(a,b);

    for(auto i:res){
        cout<<i<<endl;
    }
    


}

// 输入样例 1 

// 1A2BD3G4H56JK
// 23EFG4I5J6K7
// 输出样例 1

// 23G456K
// 23G45JK