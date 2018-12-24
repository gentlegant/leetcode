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

struct val_num
{
    int val, num;

    val_num()
    {
        val = 0;
        num = 0;
    }
};

//读入数组并做初始化
void readinput(vector<int> &vc,vector<int> &vc1)
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    int i;
    while (ss >> i)
        vc.push_back(i);
    getline(cin, s);
    stringstream ss1(s);
    while (ss1 >> i)
        vc1.push_back(i);


}
int solve(vector<int> &vc, double target, int n, int gcd)
{
    vector<val_num> dp(int(target) + 1), dpold = dp;
    //在前j个数字中，使用i个数字能达到的最大值
    //dp[m][t]表示在前m个数中 对于target=t时的最优值，则有
    //dp[m][t]= max(dp[m][t-A[m]]+A[M],dp[m-1][t])
    //为了记录结果，在这个过程中不仅要记录最优值，还要记录已经选了的个数
    //由 上式子可知，空间复杂度可以优化到 O（target）
    int res = 0;
    for (auto &now : vc)
    {
        //now:当前这个数

        for (int tar = now; tar <= target; tar++)
        {
            //当前的任务是求解 dp[tar]
            //条件成立，表示可以将当前数字加入
            auto &tmp = dpold[tar - now];
            //当前数字可以入选
            if (tmp.val + now >= dpold[tar].val)
            {
                dp[tar].val = tmp.val + now;
                dp[tar].num = tmp.num + 1;
                //如果刚好使用了n个数字，记录此时达到的值
                if (dp[tar].num == n)
                    res = max(res, dp[tar].val);
            }
        }

        dpold = dp;
    }
    return gcd * (2 * target - 2 * res);
}

void solve2(vector<int> & pa, vector<int>&  pb, int len)
{
    int suma = accumulate(pa.begin(),pa.end(),0);
    int sumb = accumulate(pb.begin(),pb.end(),0);
    int diff = suma - sumb;
    while (diff!=0)
    {
        int besti = 0, bestj = 0;
        int bestChange = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                int change = pa[i] - pb[j];
             
                if (abs(diff - 2 * change) < abs(diff - 2 * bestChange))
                {
                    besti = i;
                    bestj = j;
                    bestChange = change;
                }
            }
        }
        if (bestChange == 0) // 差不能再缩小
            return ;

        swap(pa[besti],pb[bestj]);
        suma = suma - bestChange;
        sumb = sumb + bestChange;
        diff = suma - sumb;
    
    }


}

int main(int argc, char const *argv[])
{
    vector<int> vc,vc1;
    //gcd是数组的最大公约数（不计较0）
    //n是数组长度
 
    //target是我们希望优化到的目标


    readinput(vc,vc1);
    solve2(vc,vc1,vc.size());
    cout << accumulate(vc.begin(),vc.end(),0)-accumulate(vc1.begin(),vc1.end(),0);

    return 0;
}
