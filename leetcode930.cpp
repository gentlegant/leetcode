#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {

        vector<int> index;
    
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == 1)
                index.push_back(i);
        }

        int res = 0;
        if(S==0){
           
            if(index.empty())
                return A.size()*(A.size()+1)/2;
            
            for(int i=0;i<=index.size();i++){
                 
                auto tmp=(i==index.size()? A.size() : index[i])-  (i==0? -1:index[i-1]) -1;
                res+=tmp*(tmp+1)/2;
               

            }
            return res;
        }
  

        for (int fir = 0, sec = S - 1;sec<index.size(); fir++, sec++)
        {
           
            
            res += (index[fir] - (fir == 0 ? -1 : index[fir - 1]) ) *(((sec == (index.size() - 1)) ? A.size() : index[sec+1]) - index[sec] );
     
        }

        return res;
    }
};

int main()
{

    vector<int> a =
{0,0,0,0,0,0,1,0,0,0};
    int b = 0;
    Solution c;
    auto d = c.numSubarraysWithSum(a, b);
    

    return 0;
}