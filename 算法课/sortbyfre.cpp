// 按数值个数排序

// Description

// Given an array of integers, sort the array according to frequency of elements. For example, if the input array is {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12}, then modify the array to {3, 3, 3, 3, 2, 2, 2, 12, 12, 4, 5}. If frequencies of two elements are same, print them in increasing order.

// Input

// The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.（1 ≤ T ≤ 70；30 ≤ N ≤ 130；1 ≤ A [ i ] ≤ 60 ）

// Output

// Print each sorted array in a seperate line. For each array its numbers should be seperated by space.

// Sample Input 1

// 1
// 5
// 5 5 4 6 4

// Sample Output 1

// 4 4 5 5 6

#include<iostream>
#include<algorithm>
#include <map>
#include<sstream>
#include<vector>
using namespace std;

typedef pair<int, int> PAIR;


bool cmp(const PAIR& lhs, const PAIR& rhs) {
return lhs.second > rhs.second;
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    char a[0];
    //为了清空一行
    cin.getline(a,0);
    while(n--){
        string s;
        //长度读取可以不需要
        getline(cin,s);
      
        getline(cin,s);
    
        stringstream ss(s);
        map<int,int> m;
        int tmp;
        while(ss>>tmp)
            m[tmp]+=1;
        vector<PAIR> vc(m.begin(), m.end());
        sort(vc.begin(),vc.end(),cmp);

        for(auto i:vc)
            for(int j=0;j<i.second;j++)
                cout<<i.first<<" ";
    }
    return 0;
}




