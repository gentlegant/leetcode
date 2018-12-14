nums=[int(i) for i in input().split()]
m,n=[int(i) for i in input().split()]
k=int(input())
print(sorted(nums[m-1:n])[k-1])