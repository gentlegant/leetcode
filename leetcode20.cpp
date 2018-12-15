#include <stack>
#include <map>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char i :s){
      
            switch(i){
                case '(':
                case '{':
                case '[':
                    st.push(i);
                    break;
                default:
                    if(st.empty() || abs(i-st.top())>2)
                        return false;
                    st.pop();

            }
        }
        return st.empty();
    }
};
int main(int argc, char const *argv[])
{
    string a="{{)}";
    Solution b;
    cout<<b.isValid(a);
    return 0;
}
