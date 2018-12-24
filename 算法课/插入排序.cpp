#include <iostream>
#include <vector>
#include<sstream>
#include <algorithm>
using namespace std;

void readinput(vector<int> &vc)
{
    string str;
    getline(cin, str);
    int tmp;
    istringstream s(str);
    while (s >> tmp)
        vc.push_back(tmp);

}
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> vc;
    readinput(vc);
    for(auto i=vc.begin();i!=vc.end();i++){
        auto place=upper_bound(vc.begin(),i,*i);
        //cha ru
        int rem=*i;
        for(auto tmp=i;tmp!=place;tmp--)
            *tmp=*(tmp-1);
        *place=rem;
    }
    
    for(int i=0;i<vc.size()-1;i++)
        cout<<vc[i]<<" ";
    cout<<vc.back();
    return 0;
}
