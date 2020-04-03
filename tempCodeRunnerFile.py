import random
def upper_bound(nums, target):
    if(len(nums)==0):
        return 0
    low, high = 0, len(nums)-1
    pos = len(nums)
    while low<high:
        mid=int((low+high)/2)
        if nums[mid]<=target:
            low = mid+1
        else:#>
            high = mid
            pos = high
    if nums[low]>target:
        pos = low
    return pos
res=[]
for _ in range(200):
    y=random.randint(0,100)
    ins=upper_bound(res,y)
    res.insert(ins,y)
    print(res)