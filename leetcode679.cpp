#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class pos
{
public:
    int dir, index;
    double val;
    pos(int p1, int p2, double p3) : dir(p1), index(p2), val(p3)
    {
    }
    pos(const pos &a) : dir(a.dir), index(a.index), val(a.val)
    {
    }
    pos() {}
};

class Solution
{
    bool sjtalg(vector<pos> &o)
    {
        for (auto &i : o)
        {
            cout << i.val << (i.dir == 1 ? "->" : "<-") << i.index << "  ";
        }
        cout << endl;
        auto m = o.begin();
        vector<vector<pos>::iterator> iters;
        while (m != o.end())
        {
            if ((o.begin() <= m + m->dir) && (m + m->dir < o.end()) && m[m->dir].index < m->index)
            {
                iters.push_back(m);
            }
            m++;
        }
        if (iters.empty())
            return false;
        auto max_ = *max_element(iters.begin(), iters.end(),
                                 [](vector<pos>::iterator &p1,
                                    vector<pos>::iterator &p2) -> bool {
                                     return p1->index < p2->index;
                                 });
        auto rem = *max_;

        swap(*max_, max_[max_->dir]);
        max_ += rem.dir;
        for (auto &i : o)
        {
            if (i.index > max_->index)
                i.dir = -i.dir;
        }
        return true;
    }

    bool backtrace(double tmp, int s, vector<pos> &o)
    {
        if (s == 4)
            return abs(tmp - 24) < 0.000001;

        return backtrace(tmp * o[s].val, s + 1, o) || backtrace(tmp / o[s].val, s + 1, o) || backtrace(tmp + o[s].val, s + 1, o) ||
               backtrace(tmp - o[s].val, s + 1, o) ||
               backtrace(o[s].val - tmp, s + 1, o) || backtrace(o[s].val / tmp, s + 1, o);
    }
    bool backtrace1(double tmp, double tmp2, int s, vector<pos> &o)
    {
        if (s == 0)
        {
            return backtrace1(o[0].val + o[1].val, 0, 1, o) || backtrace1(o[0].val - o[1].val, 0, 1, o) || backtrace1(o[0].val * o[1].val, 0, 1, o) || backtrace1(o[0].val / o[1].val, 0, 1, o);
        }
        else if (s == 1)
        {
            return backtrace1(tmp, o[2].val + o[3].val, 2, o) || backtrace1(tmp, o[2].val - o[3].val, 2, o) || backtrace1(tmp, o[2].val * o[3].val, 2, o) || backtrace1(tmp, o[2].val / o[3].val, 2, o);
        }
        else if (s == 2)
        {

            return backtrace1(tmp * tmp2, 0, 3, o) || backtrace1(tmp / tmp2, 0, 3, o) ||
                   backtrace1(tmp + tmp2, 0, 3, o) || backtrace1(tmp - tmp2, 0, 3, o);
        }
        else
            return abs(tmp - 24) < 0.000001;
    }

public:
    bool judgePoint24(vector<int> &nums)
    {
        vector<pos> o(nums.size());
        for (int i = 0; i < o.size(); i++)
            o[i] = pos(-1, i, double(nums[i]));

        int i = 0;
     
        do
        {
            if (backtrace(o[0].val, 1, o) || backtrace1(0, 0, 0, o))
                return true;

        } while (   next_permutation(o.begin(),o.end(),[]
        (pos&a,pos&b)->bool{return a.index<b.index;}
        ));
        return false;
    }
};

int main()
{
    Solution a;
    // double aa=8,bb=3;
    // cout<<aa/(bb-aa/bb);
    vector<int> b = {3, 3, 8, 8};
    cout << a.judgePoint24(b);
}

