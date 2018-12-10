#include <string>
#include <numeric>
#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;
class Solution
{
    
  public:
  
     bool compare(vector<string>::iterator a,vector<string>::iterator b){
            return a->size()>b->size();
     }
     int shortest(vector<string>& strs) {
      
        auto b=min_element(strs.begin(),strs.end(),compare);
        return b->size();
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        int N=shortest(strs);
        cout<<N;
        string res;
        for (int i = 0;i<N; i++)
        {
            if(strs[0].size()==i)
                return res;

            auto first = strs[0][i];
            for (auto &s : strs)
            {
                if (s[i] != first)
                    return res;
            }
        
            res.push_back(first);
               
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    Solution a;
    vector<string> b({"123","1222","121123"});
    auto bb=a.longestCommonPrefix(b);


    return 0;
}
