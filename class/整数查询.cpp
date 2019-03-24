#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void solve(int M,int N){
    vector<int> dividend,divid,res;
    int tmp;
    for(int i=0;i<M;i++){
        cin>>tmp;
        dividend.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        cin>>tmp;
        divid.push_back(tmp);
    }
    for(int i:divid)
        res.push_back(count_if(dividend.begin(),dividend.end(),[i](int x){return x%i==0;}));

    for(int i=0;i<res.size()-1;i++)
        cout<<res[i]<<" ";
    cout<<res.back()<<endl;

}
    


int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int m,n;
        cin>>m>>n;
        solve(m,n);


    }
    return 0;
}
