6
0,30
0,50
10,20
15,30
20,50
20,65

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

#include <algorithm>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int calcMinStaff() {
    int n;
    cin>>n;
    
    vector<pair<int,int>> vc;
    for(int i=0;i<n;i++){
        int x,y;
        char b;
        cin>>x>>b>>y;
        cout<<x<<" "<<y<<endl;
        vc.push_back(pair<int,int>(x,y));
    }
    sort(vc.begin(),vc.end(),[](pair<int,int> &p1,pair<int,int> &p2)->bool{return p1.first<p2.first;  });
    vector<int>  way;
    for(auto p:vc){
        auto iter=upper_bound(way.begin(),way.end(),p.first)-1;
        if(iter==way.end()-1)
            way.push_back(p.second);
        else{
            way.erase(iter);
            auto ins=lower_bound(way.begin(),way.end(),p.second);
            way.insert(ins,p.second);
        } 
    }
    return way.size();
}
/******************************结束写代码******************************/


int main() {
    int res;

    
    res = calcMinStaff();
    cout << res << endl;
    
    return 0;

}
