
import math

def solve(nums):
    len_=len(nums)
    res=[]
          
    DIFF =0.00000000000005
    for i in range(1,len_):
        left=nums[i-1]
        right=nums[i]
        while left<right:
            mid=(left+right)/2.0
            lsum=0.0
            rsum=0.0
            for ii in range(i):
                lsum+=1/(mid-nums[ii])
            for ii in range(i,len_):
                rsum+=1/(nums[ii]-mid)
            sub=lsum-rsum
            
            if (right-left)<DIFF or sub==0:
                res.append(mid)
                break
            #左边的力太小了
            elif sub<0:
                right=mid
            else:
                left=mid
    return res
t=int(input())
for _ in range(t):
    input()
    line=input()
    nums=[float(i) for i  in line.split()]
    res=solve(nums)

    for i in range(len(res)-1):
        print('%.2f' %res[i],end=" ")
    print('%.2f' %res[-1])
    