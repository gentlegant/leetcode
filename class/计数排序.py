import sys
for line in sys.stdin:

    nums=[int(i) for i in line.split()]
    nums=nums[1:]
    res=[0]*len(nums)
    m=max(nums)

    arr=[0]*(m+1)
    for i in nums:
        arr[i]+=1
    for i in range(1,m+1):
        arr[i]+=arr[i-1]

    for i in nums:
        
        res[arr[i]-1]=i
        arr[i]-=1
    for i in range(len(res)-1):
        print(res[i],end=" ")
    print(res[-1],end='')



