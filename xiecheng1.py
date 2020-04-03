# // 子字符串数量
# // 时间限制：C/C++语言 1000MS；其他语言 3000MS
# // 内存限制：C/C++语言 65536KB；其他语言 589824KB
# // 题目描述：
# // 给定一个由 n 个小写英文字母组成的字符串 s = s1 ... sn ，另给定 k 个各不相同的英文字母， 计算在所有 s 的子字符串中有多少可以由这 k  个字母或这 k  个字母的子集组成。(相同子字符串视为多个子字符串)

# // 输入
# // 第一行为空格分开的两个数字代表 n  和 k  。( 1 <= n <= 105 , 1 <= k <= 26 )

# // 第二行为字符串 s 。

# // 第三行为 k 个由空格分隔开的小写英文字母。

# // 输出
# // 子字符串数量。


# // 样例输入
# // 6 2
# // xyzxyz
# // x y
# // 样例输出
# // 6
import collections
n,k=[int(i) for i in input().split()]
s=input()
kk=input().split()
cnt=collections.Counter(s)

res=1
for k in kk:
    res*=(cnt[k]+1)

print(res)