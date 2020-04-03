#include <vector>
#include <map>
#include<algothrim>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        map<string ,vector<string>> m;
        for(auto s:strs){
            string cp=s;
            sort(cp.begin(),cp.end());
            if (m.end() != m.find(cp)){
                m[cp].push_back(s);
            }
            else
            {
                m[cp]=new vector<string>({s});
            }
            
        }
        for(auto s:m){
            res.push_back( s.second);
        }
        return res;


    }
};


int main()
{

    return 0;
}