#include <iostream>
#include <queue>

#include <algorithm>

using namespace std;

struct Compare {
    bool operator() (int a,int b) {
        if(b==-1)
            return false;
        if(a==-1)
            return true;
        return a > b;
    } 
};

int main(){

  
    
    priority_queue<int,vector<int>,Compare> q;
    q.push(-1);
    q.push(3);
       
 
    q.push(-1);
    q.push(66);
    q.push(66);
        q.push(-1);
    q.push(1);

 
    q.push(1);
    cout<<endl;
    int count=0;
    while(!q.empty()&&count++<20){
        cout<<q.top()<<endl;
        q.push(-1);
        q.pop();
    }
    while(!q.empty())
    {
        cout<<q.top();
        q.pop();
    }
}