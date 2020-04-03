#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
class dolphin
{
private:
    int birthday, dieday, now;
    vector<int> givebirthday;

public:
    dolphin(int bday, int die)
    {
        birthday = bday;
        dieday = die;
    }
};

long countDolphin(int n, int m, vector<int> birthYear, int x)
{
    //cout<<n<< " "<<m <<"  "<<x<<endl;
    vector<int> dols = {0}, cp = dols;
    for (int i = 0; i < x; i++)
    {
        // cout<<"the"<<i<<" day:"<<dols.size()<<endl;
        // for(auto iii:dols){
        //     cout<<iii<<" ";
        // }
        // cout<<endl;
        for (auto dol = cp.begin(); dol != cp.end(); dol++)
        {
            
            auto flag=false;
            //auto k=find(birthYear.begin(), birthYear.end(), i-(*dol) );
            for(auto b:birthYear){
                if(i-b==*dol){
                    dols.push_back(i);
                    flag==true;
                    break;
                }
            }
                
               
            if (!flag &&(i - *dol) == m)
                dols.erase(dol);
        }
        cp = dols;
    
    }
    return n * dols.size();
}
/******************************结束写代码******************************/

int main()
{
    long res;

    int _n;
    cin >> _n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int _m;
    cin >> _m;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int _birthYear_size = 0;
    cin >> _birthYear_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _birthYear;
    int _birthYear_item;
    for (int _birthYear_i = 0; _birthYear_i < _birthYear_size; _birthYear_i++)
    {
        cin >> _birthYear_item;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _birthYear.push_back(_birthYear_item);
    }

    int _x;
    cin >> _x;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    res = countDolphin(_n, _m, _birthYear, _x);
    cout << res;

    return 0;
}
