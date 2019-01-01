# 题目是这样的，给一个数组，返回一个大小相同的数组。
# 返回的数组的第i个位置的值应当是，对于原数组中的第i个元素，
# 至少往右走多少步，才能遇到一个比自己大的元素（如果之后没有比自己大的元素，
# 或者已经是最后一个元素，则在返回数组的对应位置放上-1）。

# 简单的例子：

# input: 5,3,1,2,4

# return: -1 3 1 1 -1

# explaination: 对于第0个数字5，之后没有比它更大的数字
# ，因此是-1，对于第1个数字3，需要走3步才能达到4（第一个比3大的元素），
# 对于第2和第3个数字，都只需要走1步，就可以遇到比自己大的元素。对于最后一个数字4，
# 因为之后没有更多的元素，所以是-1。
#python 似乎没有原生的支持栈  原因是因为list已经提供了


class Solution:
    def nextExceed(self, x):
        """
        :type x: list int
        :rtype: list int
        """
        stack=[]
        res=[-1]*len(x)
        for index,i in enumerate(x):
            #小顶栈
            while(len(stack)>0 and i>x[stack[-1]]):
                topindex=stack.pop()
                res[topindex]=index-topindex

            stack.append(index)
       
                
        return res

a=Solution()
b=a.nextExceed([5,3,1,2,2,4])
print(b)