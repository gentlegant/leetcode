#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        if(s.size()>12)
            return res;
        int size=s.size();
        for (int i = 1; i <=min(size-3, 3); i++)
        {
            auto s1 = s.substr(0, i);
            if (!valid(s1))
                continue;
            for (int j = 1; j <= min(3,size-i-2); j++)
            {
                auto s2 = s.substr(i, j);
                if (!valid(s2))
                    continue;

                for (int k = 1; k <= min(3,size-i-j-1); k++)
                {

                    auto s3 = s.substr(j + i, k), s4 = s.substr(i + j + k);
                    if (!valid(s3) || !valid(s4))
                        continue;
                    res.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                }
            }
        }

        return res;
    }

//#private:
    bool valid(string s)
    {
      
        if (atoi(s.c_str()) > 255 || (s[0] == '0' && s.size() > 1))
            return false;
        return true;
    }
};
int main()
{
    Solution a;
    cout<<    a.valid( "6786374048" );
    return 0;
}