#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>
#include <vector>
#include <set>

int main(){
    set<int> st={2,3,5,3,34,5,7};
    auto a=st.end();

    for (auto i=st.begin();i!=a;i++){
        st.insert(*i*2);
    }
    for (auto ii:st){
        cout<<ii<<endl;
    }
    
   
}