#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;
//[left,mid) and [mid,right)
//男人的代码，真的帅
void merge(vector<int> &vc, vector<int> &res, int left, int mid, int right)
{

    int tmpleft = left, tmpmid = mid, i = left;
    while (tmpleft != mid && tmpmid != right)
    {
        if (vc[tmpleft] < vc[tmpmid])
        {
            res[i++] = vc[tmpleft];
            tmpleft++;
        }
        else
        {
            res[i++] = vc[tmpmid];
            tmpmid++;
        }
    }
    while (tmpleft != mid)
        res[i++] = vc[tmpleft++];
    while (tmpmid != right)
        res[i++] = vc[tmpmid++];

    copy(res.begin() + left, res.begin() + right, vc.begin() + left);
}

void sort(vector<int> &vc)
{
    vector<int> res;
    res.resize(vc.size());
    stack<pair<int, int>> s;
    s.push({0, vc.size()});
    s.push({0, vc.size()});

    while (!s.empty())
    {
        auto top = s.top();
        s.pop();
        int left = top.first, right = top.second;
        int mid = (left + right) / 2;
        if (mid == left || mid == right)
            continue;
        if (!s.empty()&& s.top() == top)
        {
            if (mid > left)
            {
                s.push({left, mid});
                s.push({left, mid});
            }
            if (right > mid)
            {
                s.push({mid, right});
                s.push({mid, right});
            }
        }
        else
            merge(vc, res, left, mid, right);
    }
}


int main(int argc, char const *argv[])
{
    int count;
    while(cin>>count){
        vector<int> vc;
        while(count--){
            int tmp;
            cin>>tmp;
            vc.push_back(tmp);
        }

        sort(vc);

        for(int i=0;i<vc.size()-1;i++)
            cout<<vc[i]<<" ";
        cout<<vc.back();
        cout<<endl;
    }

}
