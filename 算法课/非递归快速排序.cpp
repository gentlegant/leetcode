#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//快排
//区间左闭右开
int partition1(vector<int> &v, int left, int right)
{
    int begin = left;
    int end = right - 1;
    int key = v[end]; // 选基准
    while (begin < end)
    {
        while (begin < end && v[begin] <= key)
            begin++;
        if (begin < end)
            v[end--] = v[begin];
        while (begin < end && v[end] >= key)
            end--;
        if (begin < end)
            v[begin++] = v[end];
    }
    v[end] = key;
    return end;
}



void QiockSortNor(vector<int> &v, int left, int right)
{

    stack<int> s;
    s.push(left);
    s.push(right);
    while (!s.empty())
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();
        if (left != right)
        {
            int boundary = partition1(v, left, right);
            // 左区间
            s.push(left);
            s.push(boundary);
            // 右区间
            s.push(boundary + 1);
            s.push(right);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vc = {3, 2, 1, 23, 5, 4643, 6, 757, 324};
    QiockSortNor(vc, 0, vc.size());
    for (auto &i : vc)
    {
        cout << i << endl;
    }
    return 0;
}
