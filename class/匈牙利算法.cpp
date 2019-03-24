#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;
class Graph{
    //用矩阵存储二部图
    vector<vector<int>> edge;
public:
    void readinput(){
        int n; 
        cin>>n;
         //读取\n
        cin.get();
        edge=vector<vector<int>>(n,vector<int>(n,0));
        int people,task,weight;
        string line;
        stringstream ss;
        getline(cin,line);
        ss<<line;
        char _;
        while(ss>>people>>task>>weight){
            ss>>_;
            edge[people-1][task-1]=weight;
        };
        // for(auto &i:edge){
        //     for(auto &ii:i)
        //         cout<<ii<<" ";
        //     cout<<endl;
        // }
    }
};


int main(int argc, char const *argv[])
{
    int t=1;
    cin>>t;
    //读取\n
    cin.get();
    while(t--!=0){
        Graph g;
        g.readinput();
    }
    return 0;
}
