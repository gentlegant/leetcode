class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s=str(x)
        for i in range(int(len(s)/2)):
            if(s[i]!=s[-1-i]):
                return False
        return True
