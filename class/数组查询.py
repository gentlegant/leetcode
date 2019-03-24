# 数组查询

# Description

# Given an array, the task is to complete the function which finds the maximum sum subarray, where you may remove atmost one element to get the maximum sum.

# Input

# 第一行为测试用例个数T；后面每两行表示一个用例，第一行为用例中数组长度N，第二行为数组具体内容。

# Output

# 每一行表示对应用例的结果。

# Sample Input 1
'''
1
5
1 2 3 -4 5
'''
# Sample Output 1

# 11

# Hint

# 例如，对一个数组A[] = {1, 2, 3, -4, 5}，要移除-4得到最大和的子数组，和为11.

def solve( nums):
    res=0
    dp1=[0]*len(nums)
    dp2=dp1.copy()
    dp1[0]=nums[0]
    dp2[-1]=nums[-1]
    for i in range(1,len(nums)):
        dp1[i]=max(0,dp1[i-1])+nums[i]
    for i in range(len(nums)-2,-1,-1):
        dp2[i]=max(0,dp2[i+1])+nums[i]

    for i in range(1,len(nums)-1):
    
        res=max(res,dp1[i-1]+dp2[i+1]+max(nums[i],0))
 
    return res


T=int(input())
while T!=0:
    T-=1
    input()
    nums=[int(x) for x in input().split()]
    print(solve(nums))
