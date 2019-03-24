// # 无限递归字符串查询

// # Description

// # Consider a string A = "12345". An infinite string s is built by performing infinite steps on A recursively. In i-th step, A is concatenated with ‘$’ i times followed by reverse of A. A=A|$...$|reverse(A), where | denotes concatenation.

// # Constraints:1<=Q<=10^5, 1<=POS<=10^12

// # Input

// # 输入第一行为查询次数，后面为每次查询的具体字符位置。

// # Output

// # 输出每一次查询位置上的字符。

// # Sample Input 1

// # 2
// # 3
// # 10

// # Sample Output 1

// # 3
// # 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//在第K层查第k个数
//第k层有k-1个&
char solve(int n,int an,int k){
    if(n==1)
        return '0'+k;

    int left=(an-n+1)/2;
    int right=an-left+1;
    if(k>left&&k<right)
        return '$';
    else if(k<=left)
        return solve(n-1,left,k);
    else 
        return solve(n-1,left,an-k+1);
}

//An+1=2*An+n
//A1=5
char solve(int para){
    int An=5;
    int n=1;
    while(An<para)
        An=2*An+n++;
    //An is now >=para
    
    return solve(n,An,para);
}

int main(int argc, char const *argv[])
{

    int T;
    int tmp;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>tmp;
        auto res=solve(tmp);
        cout<<res<<endl;

    }
    return 0;
}
