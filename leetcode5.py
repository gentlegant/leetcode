#最长回文子串

#用一个三角矩阵记录相异性
#以空间换时间
#numpy并没有对三角矩阵或对称矩阵提供很好的支持，因此采用普通矩阵
import numpy as np

class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        #length回文串长度
        #index回文串中心
        size=len(s)
        max_=0
        mid=0
        res=-1
        arr=np.array(list(s))
        #采用了广播机制
        matrix=(arr==arr[:,None])
        print(matrix)
        #接下来在matrix中找到最长的true链就ok
        for i in range(len(s)):    
            r=i
            c=i
            
            #保证只访问下三角矩阵
            while(c>=0 and r<size and matrix[r][c]):
                #向下
                r+=1
                #向左
                c-=1
            if((r-c-1)>max_):
                mid=i
                max_=r-c-1
            r=i+1
            c=i
            while(c>=0 and r<size and matrix[r][c]):
                r+=1
                c-=1
            if((r-c-1)>max_):
                mid=i
                max_=r-c-1
        

       
        if(max_%2==1):
            return s[mid-max_//2:mid+max_//2+1]
        else:
            return s[mid-max_//2+1:mid+max_//2+1]
      
a=Solution()
b=a.longestPalindrome("")
print(b)