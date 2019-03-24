# 棋盘覆盖问题

# Description

# 棋盘覆盖问题：给定一个大小为2^n2^n个小方格的棋盘，其中有一个位置已经被填充，现在要用一个L型（22个小方格组成的大方格中去掉其中一个小方格）形状去覆盖剩下的小方格。求出覆盖方案，即哪些坐标下的小方格使用同一个L型格子覆盖。注意：坐标从0开始。左上方的第一个格子坐标为(0,0)，第一行第二个坐标为(0,1)，第二行第一个为(1,0)，以此类推。

# Input

# 输入第一行为测试用例个数，后面每一个用例有两行，第一行为n值和特殊的格子的坐标（用空格隔开），第二行为需要查找其属于同一个L型格子的格子坐标。

# Output

# 输出每一行为一个用例的解，先按照行值从小到大、再按照列值从小到大的顺序输出每一个用例的两个坐标；用逗号隔开。

# Sample Input 1

# 1
# 1 1 1
# 0 0

# Sample Output 1

# 0 1,1 0


#判断在2^n 2^n棋盘中x,y在哪个方位

def judge(n,x,y):
    tmp=pow(2,n-1)
    #是否在左，是否在上
    xres=0 if x<=tmp else tmp
    yres=0 if y<=tmp else tmp
    return xres,yres
def solve(n,x,y,x_,y_):
    if n==1:
        return ((x,y_),(x_,y))
    tmp=pow(2,n-1)
    dir=judge(n,x,y)
    dir_=judge(n,x_,y_)
    if dir==dir_:
        tmp=solve(n-1,x,y,x_,y_)
        
    

T=int(input())
for _ in range(T):
    #x y是特殊点的左边
    n,x,y=map(int,input().split())
    #x_,y_是查询的点的坐标
    x_,y_=map(int,input().split())
    #转化为从1开始到pow(2,n)
    solve(n,x+1,y+1,x_+1,y_+1)