#问题的关键在于如何存储每个数字 “出现过" 的信息。这儿采用的是nums[nums[i]%n]+=n的方式。可谓妙哉
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        Basic idea:
        1. for any array whose length is l, the first missing positive must be in range [1,...,l+1], 
            so we only have to care about those elements in this range and remove the rest.
        2. we can use the array index as the hash to restore the frequency of each number within 
            the range [1,...,l+1] 
        """
        nums.append(0)
        n = len(nums)
        for i in range(len(nums)): #delete those useless elements
            if nums[i]<0 or nums[i]>=n:
                nums[i]=0
        for i in range(len(nums)): #use the index as the hash to record the frequency of each number
            nums[nums[i]%n]+=n
        print(nums)
        for i in range(1,len(nums)):
            if nums[i]<n:
                return i
        
        return n

nums=[2,1,3,6]
a=Solution()
res=a.firstMissingPositive(nums)
print(res)