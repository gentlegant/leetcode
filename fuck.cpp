#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
               
                int cur = st.top(); st.pop();
          
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }

            st.push(i);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b={1,2,4,6,3,4,1};
   cout<< a.largestRectangleArea(b);
    return 0;
}
