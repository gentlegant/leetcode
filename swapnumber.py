# 最小交换次数

# Description

# Given an array of N distinct elementsA[ ], find the minimum number of swaps required to sort the array.Your are required to complete the function which returns an integer denoting the minimum number of swaps, required to sort the array.

# Input

# The first line of input contains an integer T denoting the no of test cases . Then T test cases follow . Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .(1<=T<=100;1<=N<=100;1<=A[] <=1000)

# Output

# For each test case in a new line output will be an integer denoting minimum umber of swaps that are required to sort the array.

# Sample Input 1

# 2
# 4
# 4 3 2 1
# 5
# 1 5 4 3 2

N=int(input())
while(N!=0):
    N-=1
    _=input()
    res=0
    line=input().split()
    nums=[int(i) for i in line]
    sort=sorted(nums)
    for i,n in enumerate(zip(nums,sort)):
        if(n[0]!=n[1]):
            ii=sort.index(n[0])
            res+=1
            nums[i],nums[ii]=nums[ii],nums[i]
    #目标是利用单调栈求出nums的逆序 数
  
    print(res)
   
