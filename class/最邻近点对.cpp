#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class point{
public:

    int x,y,byy=0;
    point(int p1,int p2):x(p1),y(p2){

    }
};

int distance(point &a,point &b){

    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
} 


class Solution{
public:
    int violence(vector<point> &p){
        int d=distance(p[0],p[1]);
        for(int i=0;i<p.size();i++)
            for(int j=i+1;j<p.size();j++)
                d=min(d,distance(p[i],p[j]));
        
        return d;
    }





    int solve(vector<point>& p){
        sort(p.begin(),p.end(),[](point &p1,point &p2)->bool{return p1.y<p2.y;});
        
        int tmp=0;
        for(auto& i:p)
            i.byy=tmp++;
        sort(p.begin(),p.end(),[](point &p1,point &p2)->bool{return p1.x<p2.x;});
    
        return help(0,p.size()-1,p);
    }
private:
    int help(int l,int r,vector<point>& p){
        if(l+1==r)
            return distance(p[l],p[r]);
        int mid=(l+r)/2;
        int d=min(help(l,mid,p),help(mid,r,p));
        for(int i=l;i<=mid;i++){
        
            int count=0;
            int y=p[i].byy;
            for(int j=mid+1;j<=r;j++){
                if(abs(p[j].byy-y)>3)
                    continue;
                if(count++==3)
                    break;

                d=min(d,distance(p[i],p[j]));
            }
        }


        return d;
    }



};

#include <time.h>
int main(){
    srand(time(0));
    int n;
    cin>>n;
    Solution a;
    vector<point> b;
    int x,y;
    for(int i=0;i<n;i++){
        x=rand();
        y=rand();
        b.push_back(point(x,y));
    }
    cout<<a.violence(b)<<endl;
    cout<<a.solve(b);
    return 0;
}