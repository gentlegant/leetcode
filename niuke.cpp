// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> dp;


int solve(int k){
    if(dp.size()<=(k+1)){
        int res=k;
        for(int i=1;i<=k;i++){
            res=min(res, max(solve(i-1),solve(k-i))+1); 
        }
        dp[k]=res;

        return res;           
    }
    else return dp[k];
    
    
    
}


int main() {
    int n,k;
    dp.push_back(0);
    dp.push_back(1);

    cin>>n;
    while(n--)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        cin>>k;
        cout<< ceil(log(k+1)/log(2))  <<endl;
    }
    return 0;
}