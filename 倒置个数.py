
# 1
# 8
# 8 3 2 9 7 1 5 4

# Sample Output 1

# 17

#核心思想：基于归并排序来 计数 逆序数
class Solution:
    def __init__(self,arr):
        self.arr=arr
   
        self.res=0
        self.mergesort(0,len(arr)-1)
        print(self.res)
     


    def merge(self,start,mid,end):
        i=start
        j=mid+1
        tmp=[]
        while(i<=mid and j<=end):
            #前面的数大于后面的数，这意味着一大群 逆序
            if(self.arr[i]>self.arr[j]):
                self.res+=mid-i+1
                tmp.append(self.arr[j])
                j+=1
                
            else:
                tmp.append(self.arr[i])
                i+=1
        #残余
        while(i<=mid):
            tmp.append(self.arr[i])
            i+=1
        while(j<=end):
            tmp.append(self.arr[j])
            j+=1
   
        for k in range(start,end+1):
            self.arr[k]=tmp[k-start]


    def mergesort(self,start,end):
        if(start==end):
            return 0
        mid=(start+end)//2
        self.mergesort(start,mid)
        self.mergesort(mid+1,end)
        self.merge(start,mid,end)


N=int(input())
while(N!=0):
    N-=1
    _=input()
    m=dict()
    line=input().split()
    nums=[int (i) for i in line]
    Solution(nums)
    