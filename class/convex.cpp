// # Graham扫描法
#include <time.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>  
#include <algorithm>
using   namespace std;

class point{
private:
    double x,y;
public:
    void show(ostream &o){
        o<<x<<" "<<y<<" "<<endl;
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
//p总是再左边
bool cmp2(point &l,point &r,point &p){


    if(l.x==p.x)
        return false;
    if(r.x==p.x)
        return true;
    return (l.y-p.y)/(l.x-p.x)<(r.y-p.y)/(r.x-p.x);
}
vector<point*> readinput(){
    vector<point> vc;
    
    for(int i=0;i<30;i++){
        int x=rand()%1000;
        int y=rand()%1000;    
        vc.push_back(point(x,y));
    }
  
    ofstream out;
    out.open(".\\out.txt");
    for(auto &i:vc){
        i.show(out);
    }

    sort(vc.begin(),vc.end(),cmp1);
   
    //不占用多余空间，只存储迭代器
  
    vector<point*> res;
    res.push_back(&*vc.begin());
    //先从左到右，再从右到左
    auto tmp=vc.begin();
    while(tmp!=vc.end()-1){
        tmp=max_element(tmp+1,vc.end(),[tmp](point &a,point &b )->bool {return cmp2(a,b,*tmp);});
        res.push_back(&*tmp);
    }
    auto rtmp=vc.rbegin();
    while(rtmp!=vc.rend()-1){
        rtmp=max_element(rtmp+1,vc.rend(),[rtmp](point &a,point &b )->bool {return cmp2(a,b,*rtmp);});
        res.push_back(&*rtmp);
    }
    for(auto &i:res)  
        i->show(cout);
    
    ofstream out1;
    out1.open(".\\out1.txt");
    for(auto &i:res){
        i->show(out1);
    }
    return res;
}

int main(){
   
    srand( unsigned(time(0)));
    auto p=readinput();
    system("python C:\\Users\\james\\Desktop\\alg\\class\\paint.py");
   
}