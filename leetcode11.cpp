#include <vector>

using namespace std;
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        if (height.size() <= 1)
            return 0;
        int max = 0;
        int begptr(0);
        auto endptr{height.size() - 1};
        int volumn = 0;
        while (begptr < endptr)
        {
            volumn = height[begptr] > height[endptr]
                         ? (height[endptr] * (endptr-- - begptr))
                         : (height[begptr] * (endptr - begptr++));
            max = volumn > max ? volumn : max;
        }
        return max;
    }
};
