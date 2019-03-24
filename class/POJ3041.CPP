#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int,vector<int>> likes;
vector<int> love;
bool findlove(int one,vector<int> cantlove){
    
    if( love.find(one)!=love.end() || find(cantlove.begin(),cantlove.end(),one)!= cantlove.end())
        return false;
    for(auto liked:likes[one]){
        if( love.find(liked)==love.end() && find(cantlove.begin(),cantlove.end(),liked)== cantlove.end())
            {
                love[one]=liked;
                love[liked]=one;
                return true;
            }

    }
    cantlove.push_back(one);
    for(auto liked:likes[one]){
        //cantlove.push_back(liked);
        if(findlove(liked,cantlove))
            return true;
        //cantlove.erase(find(cantlove.begin(),cantlove.end(),liked));
    }
    return false;

}



int main(){

    int N,K;
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int a,b;
        cin>>a>>b;
        likes[a].push_back(b);
        likes[b].push_back(a);

    }
    for (auto pair :likes){
        findlove(pair.first,vector<int>());
    }


    cout<<love.size()/2;

    return 0;
}