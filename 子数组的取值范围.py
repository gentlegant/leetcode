# 子数组的取值范围

# Description

# 给定数组arr和整数num，求arr的连续子数组中满足：其最大值减去最小值的结果大于num的个数。请实现一个时间复杂度为O(length(arr))的算法。

# Input

# 输入的第一行为数组，每一个数用空格隔开，第二行为num。

# Output

# 输出一个值。

# Sample Input 1

# 3 6 4 3 2
# 2

# Sample Output 1

# 6

nums=[int(i) for i in input().split()]
n=int(input())