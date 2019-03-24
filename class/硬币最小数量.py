'''
2
3 11
1 2 5
2 7
2 6
'''
N=int(input())

def solve(s,nums):

    dp=[-1]*(s+1)
    dp[0]=0
    nums.sort()
    for i in range(1,s+1):
        min=s+1
        for k in nums:
            if k>i:
                break
            
            if(dp[i-k]<min and dp[i-k]!=-1):
                min=dp[i-k]
     
        dp[i]=-1 if min==s+1 else min+1
  


    return dp[-1] if dp[-1]!=s+1 else -1


for _ in range(N):
    n,s=[int(i) for i in input().split()]
    nums=[int(i) for i in input().split()]
    print(solve(s,nums))