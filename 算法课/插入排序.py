line=input().split()

nums=[int(i) for i in line] 
nums.sort()
for i in range(len(nums)-1):
    print(nums[i],end=" ")
print(nums[-1],end='') 


