#include <bits/stdc++.h>
using namespace std;
 
int n;
char res[] = "ABC";
 
void solve(int cur)
{
    if(cur == n){
        res[cur] = 0;
        puts(res);
        return ;
    }
    for(int j = cur; j < n; j++){
        swap(res[j], res[cur]);
        solve(cur+1);
        swap(res[j], res[cur]);
    }
}
 
int main()
{
    n = strlen(res);
    solve(0);
    return 0;
}