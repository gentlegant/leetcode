#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <string >
#include <windows.h>
using namespace std;

class CombinationIterator
{
    string chars;
    int n, m;
    vector<int> now;
    bool flag;

public:
    CombinationIterator(string characters, int combinationLength) : m(combinationLength), n(characters.size()),
                                                                    chars(characters), now(m, 1),flag(true)
    {
    }

    string next()
    {
        flag=false;
        string res(m, ' ');

        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += now[i];
            res[i] = chars[sum - 1];
        }

        for (auto i = m - 1; i >= 0; i--)
        {
            if (sum < n)
            {
                now[i]++;
                break;
            }
            else
            {
                sum -= now[i] - 1;
                now[i] = 1;
            }
        }

        return res;
    }

    bool hasNext()
    {
     
        if(flag){
           
            return true;
        }

        for (int i = 0; i < m; i++)
            if (now[i] != 1)
                return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    CombinationIterator a("abc", 2);
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
    cout << a.next() << endl;
}