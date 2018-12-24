# 最长公共子序列

# Description

# 给定两个字符串，返回两个字符串的最长公共子序列（不是最长公共子字符串），可能是多个。

# Input

# 输入为两行，一行一个字符串

# Output

# 输出如果有多个则分为多行，先后顺序不影响判断。

# Sample Input 1

# 1A2BD3G4H56JK
# 23EFG4I5J6K7

# Sample Output 1

# 23G456K
# 23G45JK

def strmax(a,b):
    #type of a,b  list[str]
    if len(a[0])>len(b[0]):
        return a
    elif len(a[0])<len(b[0]):
        return b
    else:
        return list(set(a+b))

def solve(m,n):

    dp=[[""]]*(len(n)+1)
    dpold=dp.copy()
    for i in m:
        for indj,j in enumerate(n):
            if i==j:
                dp[indj+1]=dpold[indj]
                for ind,_ in enumerate(dp[indj+1]):
                    dp[indj+1][ind]+=i
            else:
                dp[indj+1]=strmax(dp[indj],dpold[indj+1])
        dpold=dp
    return dp[-1]



m=input()
n=input()

res=solve(m,n)
for i in res:
    print(i)