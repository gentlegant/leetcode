#include <iostream>
#include <numeric>
#include <iomanip>
#include <set>
#include <vector>
using namespace std;
typedef pair<int,int> point;
point add(point& p,point& q){
    
    return point(p.first+q.first,p.second+q.second);
}


//x，y 是hole 坐标
//x_,y_是要查询的点
pair<point,point> solve(int n,int x,int y,int x_,int y_){
    vector<point> path;
    int tmp=1<<n;
    bool flag=true;
    while(n--!=1){
        tmp>>=1;
        //hole坐标在哪
        int flag1=x>>n<<n;
        int flag2=y>>n<<n;
        //查询坐标在哪儿
        int flag3=x_>>n<<n;
        int flag4=y_>>n<<n;
        //如果在一个象限
        if(flag1==flag3&&flag2==flag4){
            //hole移动
            x-=flag3;
            y-=flag4;
        }
        //不在同一个象限
        //那么hole前往第一象限，必定在四个角之一
        //其位置由query决定
        else{
            x=flag3?0:tmp-1;
            y=flag4?0:tmp-1;
        }
        //记录路径
        path.push_back(point(flag3,flag4));
        //无论如何，query都要移动,移动策略都是往第一象限
        x_-=flag3;
        y_-=flag4;
        //要查的就是洞洞
        if(x==x_&&y==y_){
            flag=false;
            break;
        }
    }
    //当n==1时，棋盘只剩2*2了，其实很容易判断
    if(flag){
        set<point> st={{0,0},{0,1},{1,0},{1,1}};
        st.erase(point(x,y));
        st.erase(point(x_,y_));
        auto iter=st.begin();
        auto res1=*iter++,res2=*iter;
        point added=accumulate(path.begin(),path.end(),point(0,0),add);
        return pair<point,point>(add(res1,added),add(res2,added));
    }
    else{


        return pair<point,point>({-1,-1},{-1,-1});
    }

}




int main(int argc, char const *argv[])
{
    /* code */
    int T=1;
    int board[255][255];
    //cin>>T;
    
    while(T--){
        int count=1;
        int n=4,x=0,y=0,x_,y_;
        for(int x_=0;x_<16;x_++){
            for(int y_=0;y_<16;y_++){
                if(x_==x&&y_==y)
                    continue;
                if(board[x_][y_]!=0)
                    continue; 
                auto res=solve(n,x,y,x_,y_);
                int a=res.first.first,b=res.first.second,c=res.second.first,d=res.second.second;
                if(a!=-1 &&b!=-1){
                board[a][b]=count;
                board[c][d]=count;
                board[x_][y_]=count;

                count++;
                }
            
            }
        }
     
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                cout<<setw(3)<<board[i][j]<<" ";

            }
            cout<<endl;
        }
        
       
        
    }
    return 0;
}
