N=int(input())
for i in range(N):
    line=input().split()
    nums=[int(i) for i in line] 
    print(sum(nums)-nums[0])
    print()