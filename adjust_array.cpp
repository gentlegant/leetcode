/*
100 99 98 1 2 3
1 2 3 4 5 40
*/


//该问题本质是 背包问题 ，只不过同时限制了 背包的个数容量和体积容量
//优化途径，根据 最大公约数对原始数组  做 线性变换，可以成倍减少 dp数组的间隙




#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct  val_num{
    int val,num;

    val_num(){
        val=0;
        num=0;
    }
};


//读入数组并做初始化
void readinput(vector<int> &vc,int &gcd,double &target,int &n){
    string s;
    getline(cin,s);
    stringstream ss(s);
    int i;
    while(ss>>i)
        vc.push_back(i);
    getline(cin,s);
    stringstream ss1(s);
    while(ss1>>i)
        vc.push_back(i);
    target=accumulate(vc.begin(),vc.end(),0.0)/2;

    n=vc.size()/2;

    sort(vc.begin(),vc.end());
    //由于已经得知target 和 数组 长度，可以直接将vector 后面部分删除
    //将大于target的数全部删除，因为他们没有参考价值
    auto end=upper_bound(vc.begin(),vc.end(),target);
 
    vc.erase(end,vc.end());

    //为了后续工作的快速，对vc施加线性变换,opt

  
    gcd=vc.back();
    for(auto &i:vc)
        if(i!=0){
            gcd=__gcd(gcd,i);
            if(gcd==1)
                break;
        }
    //所有数都除最大公约数， opt
    for(auto &i:vc)
        i/=gcd;
  
}

int main(int argc, char const *argv[])
{
    vector<int> vc;
    //gcd是数组的最大公约数（不计较0）
    //n是数组长度
    int gcd,n;
    //target是我们希望优化到的目标
    double target;

    readinput(vc,gcd,target,n);
    

    vector<val_num> dp(int(target)+1),dpold=dp;
    //在前j个数字中，使用i个数字能达到的最大值
    //dp[m][t]表示在前m个数中 对于target=t时的最优值，则有
    //dp[m][t]= max(dp[m][t-A[m]]+A[M],dp[m-1][t])
    //为了记录结果，在这个过程中不仅要记录最优值，还要记录已经选了的个数
    //由 上式子可知，空间复杂度可以优化到 O（target）
    int res=0;
    for(auto &now:vc){
        //now:当前这个数
    
        for(int tar=now;tar<=target;tar++){
            //当前的任务是求解 dp[tar]
            //条件成立，表示可以将当前数字加入
            auto & tmp=dpold[tar-now];
            //当前数字可以入选
            if(tmp.val+now>=dpold[tar].val){
          
                

                dp[tar].val=tmp.val+now;
                dp[tar].num=tmp.num+1;
                //如果刚好使用了n个数字，记录此时达到的值
                if(dp[tar].num==n)
                    res=max(res,dp[tar].val);
            }
        }
       
        dpold=dp;
    }
    // cout<<target<<endl;
    // cout<<res<<endl;

    // cout<<dp[target].val<<endl;
    cout<<2*gcd*(target-res);
    
    return 0;
}
