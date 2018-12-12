class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if( len(nums)==0):
            return []
        dic={}
   
        res=[]
        for ind,i in enumerate(nums):
            for indj in range(ind+1,len(nums)):
                if( (-i-nums[indj]) in dic.keys()):
                    res.append([i,nums[indj],-i-nums[indj]])
                dic[nums[indj]]=indj
           
        return res

a=Solution()
b=a.threeSum([-1, 0, 1, 2, -1, -4])
print(b)