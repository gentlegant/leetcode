#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

void show(stack<int> &ss){
    cout<<"begin";
    auto s=ss;
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
        /* code */
    }
    cout<<endl;
    

}

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> left, star;

        for (int i = 0; i < s.size(); i++)
        {
            cout<<s[i]<<endl;
            switch (s[i])
            {
            case '(':
                /* code */
                left.push(i);
                break;
            case '*':
                /* code */
                star.push(i);
                break;

            case ')':
                /* code */
                cout<<"howcould"<<endl;
                if (!left.empty())
                    left.pop();
                else if (!star.empty())
                    star.pop();
                else
                    return false;
                break;
            default:
                break;
            }
            show(left);
            show(star);
            cout<<endl;
        }
        cout<<"!!!";
        while (!left.empty()&&!star.empty())
        {
            if (left.top() < star.top())
            {
                left.pop();
                star.pop();
            }
            else
                return false;
            show(left);
            show(star);
            cout<<endl;
        }
        return left.empty();
    }
};

int main(){
    Solution a;
   cout<< a.checkValidString("(*()");


    return 0;
}