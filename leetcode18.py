# 18. 4Sum
# Medium

# Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

# Note:

# The solution set must not contain duplicate quadruplets.

# Example:

# Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

# A solution set is:
# [
#   [-1,  0, 0, 1],
#   [-2, -1, 1, 2],
#   [-2,  0, 0, 2]
# ]

class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if(len(nums)<4):
            return []
        res=set()
        dic={}
        nums.sort()
        
        for I,i in enumerate(nums):
            for J in range(I+1,len(nums)):
                j=nums[J]
                tmp=dic.get(i+j,[])
                tmp.append([I,J])
    
                dic[i+j]=tmp
      
        for k,v in dic.items():
            if(2*k>target):
                continue
            sub_=target-k
            sub=dic.get(sub_,None)
            if(sub!=None):
                
                tmp=[i+j for i in v for j in sub if(i[0]!=j[0] and i[0]!=j[1] and i[1]!=j[0] and i[1]!=j[1])]
                for i in tmp:
                    four=[nums[k] for k in i]
                    four.sort()
                    res.add(tuple(four))
               
        res=list(res)
        for i in range(len(res)):
            res[i]=list(res[i])

        return res
a=Solution()
b=[-3,-1,0,2,4,5]
c=a.fourSum(b,0)
print(c)