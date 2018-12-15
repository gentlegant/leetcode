// 22. Generate Parentheses
// Medium

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
    void helper(vector<string> &vc, string tmp, int m, int n)
    {
        if (m == 0 && n == 0)
        {
            vc.push_back(tmp);
            return;
        }
        if (m > 0)
        {
            helper(vc, tmp + "(", m - 1, n);
        }
        if (n > 0 && m < n)
        {
            helper(vc, tmp + ")", m, n - 1);
        }
    }

  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string tmp;
        helper(res, tmp, n, n);

        return res;
    }
};
int main()
{
    Solution a;
    auto b = a.generateParenthesis(3);
    cout << b.size();
}