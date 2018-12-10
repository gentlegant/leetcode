class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag=False
        if(x<0):
            x=-x
            flag=True
        tmp=str(x)[::-1]
       

        tmp2=-int(tmp) if flag else int(tmp)
        if(tmp2<-2**31 or tmp2>2**31-1):
            return 0
        return tmp2



a=Solution()
b=a.reverse(1534236469)

print(b)