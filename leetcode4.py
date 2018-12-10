class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if(len(nums1)>len(nums2)):
            return self.findMedianSortedArrays(nums2,nums1)

        leng=len(nums1)+len(nums2)
        

        if(leng%2==1):
            return self.findkth(nums1,nums2,0,0,len(nums1),len(nums2),int(leng/2)+1)
        else:
            return (self.findkth(nums1,nums2,0,0,len(nums1),len(nums2),int(leng/2))+
            self.findkth(nums1,nums2,0,0,len(nums1),len(nums2),int(leng/2)+1))/2
        #k从1开始计数
    def findkth(self,nums1,nums2,start1,start2,k):
        end1=len(nums1)
        end2=len(num2)
        if(start1==end1):
            return nums2[start2+k-1]
        if(start2==end2):
            return nums1[start1+k-1]
        if(k==1):
            return min(nums1[start1],nums2[start2])

        p=min(int(k/2),end1-start1)
        q=k-p
        index1=start1+p-1
        index2=start2+q-1
  
   
        num1=nums1[index1]
        num2=nums2[index2]
        if(num1==num2):
            return num1
        #nums1的后半段 不可能，nums2的前半段不可能
        elif(num1>num2):
            k-=q
            start2=index2+1 
            
        else:
            k-=p
            start1=index1+1
          
        return self.findkth(nums1,nums2,start1,start2,end1,end2,k)

a=Solution()
b=a.findMedianSortedArrays([1],[2,3,4,5,6])
print(b)