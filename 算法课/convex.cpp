// # Graham扫描法

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using   namespace std;

class point{
private:
    double x,y;
public:
    void show(){

        cout<<x<<" "<<y<<" "<<endl;
    }
    point(double x_,double y_){
        x=x_;
        y=y_;
    }
    //l>r
    friend bool cmp1(point &l,point &r);
    friend bool operator==(point &l,point &r);
    friend bool cmp2(point &l,point &r,point &) ;
};
bool operator==(point &l,point &r){
    return l.x==r.x && l.y==r.y;
}
bool cmp1(point &l,point &r){
        auto x=l.x-r.x;
        if(x!=0)
            return x<0;
        return l.y<r.y;
    }
// l 和r 谁到p的夹角更大
bool cmp2(point &l,point &r,point &p){
    if(l.x==p.x)
        return true;
    if(r.x==p.x)
        return false;
    return (l.y-p.y)/(l.x-p.x)<(r.y-p.y)/(r.x-p.x);
}
vector<point> readinput(){
    vector<point> vc;
    string s;
    getline(cin,s);
    istringstream ss(s);
    int x,y;
    while (ss >>x>>y)
        vc.push_back(point(x,y));
    sort(vc.begin(),vc.end(),cmp1);
     for(auto &i:vc)    {
        i.show();
    }
    vector<point> res;
    auto del=res.begin();
    res.push_back(*del);
    while(!vc.empty()){
        vc.erase(del);
        auto k=max_element(vc.begin(),vc.end(),[del](point& x,point y)->bool{return cmp2(x,y,*del);} );
        res.push_back(*k);
        if(*k==*res.begin())
            break;
    }
    return res;
}

int main(){
    
    auto p=readinput();
    cout<<1<<endl;
    for(auto &i:p){
        i.show();
    }
}