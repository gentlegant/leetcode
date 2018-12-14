// 100 99 98 1 2 3
// 1 2 3 4 5 40



#include <iostream>
#include <set>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
void readinput(vector<int> &vc){
    string s;
    getline(cin,s);
    
    stringstream ss(s);
    int i;
    while(ss>>i)
        vc.push_back(i);
    getline(cin,s);
    stringstream ss1(s);

    auto it=vc.begin();
    while(ss1>>i){
        *it++=abs(*it-i);
     
    }
}
bool setadd(set<int> &st,int target,int add){
    st.
    for(auto it=st.begin();it!=last;it++){
        
        auto added=*it+add;
        if(added==target)
            return true;
        
        st.insert(added);
        if(added>target){
            st.erase(--st.end()); 
            return false;
        }

    }
    return false;

}

int main(int argc, char const *argv[])
{
    vector<int> vc;
    readinput(vc);
    sort(vc.begin(),vc.end());
    int out;
    int target=accumulate(vc.begin(),vc.end(),0)/2;
    set<int> st;
    st.insert(0);

    for(auto & i :vc){
        auto res=setadd(st,target,i);
        if(res){
           out=0;
           break; 
        }
    }
    auto upper=upper_bound(st.begin(),st.end(),target);
    out=min(out,min(upper!=st.end()?*upper-target:0,target- *--upper));
    cout<<out;

    return 0;
}
