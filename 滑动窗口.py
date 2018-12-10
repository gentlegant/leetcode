#借用 单调 队列

# Description

# 给定一个整型数组arr和一个大小为w的窗口，窗口从数组最左边滑动到最右边，每次向右滑动一个位置，求出每一次滑动时窗口内最大元素的和。

# Input

# 输入的第一行为数组，每一个元素使用空格隔开；第二行为窗口大小。

# Output

# 输出一个值。


# Sample Input 1

# 4 3 5 4 3 3 6 7
# 3

# Sample Output 1

# 27

from collections import queue

#read input
line=input().split()
nums=[int(i) for i in line]
N=int(input())

Q=queue()

