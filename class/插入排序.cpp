#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int count;
    while (cin>>count)
    {
        vector<int> vc;
        while(count--){
            int tmp;
            cin>>tmp;
            vc.push_back(tmp);
        }
   
        for (auto i = vc.begin(); i != vc.end(); i++)
        {
            auto place = upper_bound(vc.begin(), i, *i);
            //cha ru
            int rem = *i;
            for (auto tmp = i; tmp != place; tmp--)
                *tmp = *(tmp - 1);
            *place = rem;
        }
      
        for (int i = 0; i < vc.size() - 1; i++)
            cout << vc[i] << " ";
        cout << vc.back();
    }
    return 0;
}
