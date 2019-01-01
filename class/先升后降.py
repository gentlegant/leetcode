# 先升后降

# Description

# 从一列数中筛除尽可能少的数使得从左往右看，这些数是从小到大再从大到小的，连续出现的数值不应该有相等的情况。

# Input

# 输入时一个数组，数值通过空格隔开。

# Output

# 输出筛选之后的数组，用空格隔开。如果有多种结果，则一行一种结果。

# Sample Input 1

# 1 2 4 7 11 10 9 15 3 5 8 6

# Sample Output 1

# 1 2 4 7 11 10 9 8 6
from functools import reduce

nums = input().split(" ")
nums= [int(i) for i in nums]


left = [1 for i in nums] 
right = left.copy()

leftnums= []
rightnums = []
for i in range(len(nums)):
    leftnums.append([])
    rightnums.append([])


    
length = len(nums)
leftnums[0].append([nums[0]])
rightnums[-1].append([nums[-1]])


for i in range(1,length):
    #left 从左向右
    for j in range(0,i+1):
        if(nums[i]>nums[j] and left[j]+1>left[i]):
            left[i]=left[j]+1
    if(left[i]>1):
     
        k = left[i]-1
        for h in range(i):
            if(left[h]==k and nums[h]<nums[i]):
                for every in leftnums[h]:
                    leftnums[i].append(every.copy())
                for y in range(len(leftnums[i])):
                    lengthOfLast = len(leftnums[i][y])
                    if(leftnums[i][y][lengthOfLast-1]<nums[i]):
                        leftnums[i][y].append(nums[i])
    else:
        leftnums[i].append([nums[i]])


    Bi = length-(i+1)
    for k in range(length-(i+1),length):
        if(nums[length-i-1]>nums[k] and right[k]+1>right[length-i-1]):
            right[length-i-1] = right[k]+1
    if (right[Bi] > 1):
    
        if (nums[Bi] == nums[Bi+1]): continue
        k = right[Bi] - 1
        for e in range(Bi,length):
            if (right[e] == k and nums[e] < nums[Bi]):
                for every in rightnums[e]:
                    rightnums[Bi].append(every.copy())
                for y in range(len(rightnums[Bi])):

                    if (rightnums[Bi][y][0] < nums[Bi]):
                        rightnums[Bi][y].insert(0,nums[Bi])
    else:
        rightnums[Bi].append([nums[Bi]])





# 分配的下标
maxList = []
m=0
length = len(left)
for i in range(length):
    if(left[i]+right[i] > m):
        m = left[i]+right[i]

m=reduce(lambda x,y:max(x,y[0]+y[1]) ,zip(left,right),0)        

for i in range(length):
    if(left[i]+right[i] == m):
        maxList.append(i)


res = []
for m in maxList:
    L = leftnums[m]
    R = rightnums[m]

    LforMax = 0
    RforMax = 0
    for i in range(len(L)):
        if(LforMax<len(L[i])):
            LforMax = len(L[i])

    for i in range(len(R)):
        if(RforMax<len(R[i])):
            RforMax = len(R[i])



    for i in range(len(L)):
        if(len(L[i]) == LforMax):
            for j in range(len(R)):
                if (len(R[j])==RforMax):
                    temp = R[j].copy()
                    temp.pop(0)
                    res.append(L[i]+temp)
for i in range(len(res)):
    for j in range(len(res[i])):
        print(str(res[i][j]),end=" ")
    print()