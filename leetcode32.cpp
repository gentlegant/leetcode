#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//初始方法，遍历 [start,end)  O(n*n)  超时
class Solutionold {
public:
    int longestValidParentheses(string s) {
        int res=0;
        for(int i=0;i<s.size()-1;i++){
            int tmp=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='(')
                    tmp++;
                else
                    tmp--;
                if(tmp<0)
                    break;
                if(tmp==0)
                    res=max(res,j-i+1);

            }



        }
        return res;
    }
};




class Solution {
public:
    int longestValidParentheses(string s) {
        //强行让第一个元素为')'
        if(s[0]=='(')
            return longestValidParentheses(")"+s);
        int res=0;
        stack<int> sta;
        int begin=s.find('(');
        sta.push(begin-1);
        for(int i=begin;i<s.size();i++){
            if(s[i]=='(')
                sta.push(i);
            //遇到了')'  根据设置，此时stack 肯定不为空
            else{
                int top=sta.top();
                //栈顶
                if(s[top]=='('){
                    sta.pop();
                    res=max(res,i-sta.top());
                }
                //如果栈顶也是')'  。说明当前的')'已经不能构成合法的括号了
                //此时将老的')'弹出，新的')'入栈
                else{
                    sta.pop();
                    sta.push(i);
                }

            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s=")()())";
    Solution b;
    int a=b.longestValidParentheses(s);
    cout<<a;
    return 0;
}
