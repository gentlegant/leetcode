
nums=[int(i) for i in input().split()]
s,e=[int(i) for i in input().split()]
N=int(input())
print(sorted(nums[s-1:e],reverse=True)[-N]) 