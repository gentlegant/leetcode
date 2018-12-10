# Given n non-negative integers a1, a2, ..., an ,
#  where each represents a point at coordinate (i, ai).
#  n vertical lines are drawn such that the two endpoints of 
# line i is at (i, ai) and (i, 0). Find two lines, 
# which together with x-axis forms a container, such that the container contains the most water.

# Note: You may not slant the container and n is at least 2.


# Input: [1,8,6,2,5,4,8,3,7]
# Output: 49

class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ret=0
        begin=0
        end=len(height)-1
        while(begin!=end):
            #谁小谁移动
            if(height[begin]>height[end]):
                ret=max(ret,(end-begin)*height[end])
                end-=1
            else:
                ret=max(ret,(end-begin)*height[begin])
                begin+=1

        return ret

