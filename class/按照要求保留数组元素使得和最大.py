# 按照要求保留数组元素使得和最大

# Description

# Given an array of N numbers, we need to maximize the sum of selected numbers. At each step, you need to select a number Ai, delete one occurrence of Ai-1 (if exists) and Ai each from the array. Repeat these steps until the array gets empty. The problem is to maximize the sum of selected numbers. 必须从大到小选择元素。

# Input

# The first line of the input contains T denoting the number of the test cases. For each test case, the first line contains an integer n denoting the size of the array. Next line contains n space separated integers denoting the elements of the array. 数组元素已经按照从小到大顺序排列。

# Output

# For each test case, the output is an integer displaying the maximum sum of selected numbers.

# Sample Input 1
'''
1
3
1 2 3
'''
# Sample Output 1

# 4
def solve(nums) : 
  

    ans = dict.fromkeys(range(0, len(nums) + 1), 0)  
  

    for i in range(len(nums)) :  
        ans[nums[i]] += 1
  
    maximum = max(nums)  
  
    print(ans)
    for i in range(2, maximum + 1) : 
        ans[i] = max(ans[i - 1],  
                     ans[i - 2] + ans[i] * i) 
  
    # return the ans stored in the  
    # index of maximum  
    print(ans)
    return ans[maximum]


T=int(input())
while T!=0:
    T-=1
    input()
    nums=[int(x) for x in input().split()]
    print(solve(nums))

