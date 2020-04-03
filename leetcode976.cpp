
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <map>
#include <string >
#include <windows.h>
#include <set>

using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        
        sort(A.begin(),A.end(),[](int &p1,int &p2)->bool{ return p1>p2;});
        for(int i=0;i<A.size()-2;i++)
           if(A[i]+A[i+1]>A[i+2])
            return A[i]+A[i+1]+A[i+2];


        return 0;
    }
};

int main(){

    Solution a;
    vector<int > b={2,3,4,5};
    cout<<a.largestPerimeter(b);


    

    return 0;
}