# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"

# Write the code that will take a string and make this conversion given a number of rows:

# string convert(string s, int numRows);
# Example 1:

# Input: s = "PAYPALISHIRING", numRows = 3
# Output: "PAHNAPLSIIGYIR"

#这是别人的解
class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or numRows >= len(s):
            return s

        L = [''] * numRows
        index, step = 0, 1

        for x in s:
            L[index] += x
            if index == 0:
                step = 1
            elif index == numRows - 1:
                step = -1
            index += step
       
        return ''.join(L)
#这是我的解
class Solution1:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        res=s[::2*numRows-2]
        for i in range(1,numRows-1):
            temp1=s[i::2*numRows-2]
            temp2=s[2*numRows-2-i::2*numRows-2]
            count=0
            while True:
                try:
                    res+=temp1[count]
                    res+=temp2[count]
                    count+=1
                except:
                    break
        res+=s[numRows-1::2*numRows-2]
        return res
