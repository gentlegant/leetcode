# -*- coding:utf-8
import numpy as np
import functools as fc
#test data
'''

1 0 1 1
1 1 1 1
1 1 1 0


'''
#该解法思路来自于   Winter Camp2002,奶牛浴场 。
#time O(s^2)  s=number of zero
#matrix:默认四个角已经封印好了
#具体解法可参见 https://wenku.baidu.com/view/bc8311f69e314332396893f7.html
#但该算法有小bug，已在本代码通过预处理解决


#约定：坐标系 x轴从左向右  y轴自上而下
#出于ndarray的定义，访问元素是先用纵坐标再用很坐标 即 matrix[y][x]

def solution1(zeros,n):
    res=0
    #以下代码当传入一个ndarray matrix时：
    #m,n=matrix.shape
    #枚举zero的坐标，顺序至上而下，同行先左再右
    #出于cache命中的考虑，先 上下
    #元组中  先存的是y坐标，其次x坐标
    #zeros=[(i,j)  for i in range(m)  for j in range(n)  if matrix[i][j]==0]                            
    
    for indexu,u in enumerate(zeros):
        left=0
        right=n+1
        #上顶点的横纵坐标
        x=u[1]
        y=u[0]
        #在确定up边界的情况下向下扫描，在这个过程中要保证up还在矩形内\
        #为了保证up在矩形内，矩形的左不能大于x，右不能小于x
        
        for indexd in  range(indexu+1,len(zeros)):
            #corner case :如果当前点已经在可行矩阵外了 ，肯定不会影响结果了，忽略
            #corner case:如果当前点在同一行，忽略
            d=zeros[indexd]
      
            if(d[1]<left or d[1]>right or d[0]==y):
                continue
            #不管接下来怎样更新可行矩阵的形状，先记录当前矩阵
            s=(d[0]-y-1)*(right-left-1)
            res=max(res,s)
            #如果 下 顶点的横坐标 大于上顶点的横坐标(即在垂线的右边）)
            if(d[1]>x):            
                right=d[1]
            elif(d[1]<x): 
                left=d[1]
            else:#在一条竖线上有两个障碍.走不下去了
                break
    return res


def readinput():
    zeros=[]
    
  
    row=1
    while True:
        try:
            line=input().split()
            if(len(line)==1):
                break
            for ind,i in enumerate(line):
                if(i=='0'):
                    zeros.append((row,ind+1))
            row+=1
        except:
            break
    #m行，n列
    #语言特性，全局可见 ~O(∩_∩)O
    row-=1
    n=len(line)
    #在矩形的四周钉钉子
    # zeros.append((0,0))
    # zeros.append((0,n+1))
    # zeros.append((m+1,0))
    # zeros.append((m+1,n+1))
    #预处理：
    #把缺了的钉子补上
    column_with_zero=set([i[1] for i in zeros])
    column_without_zero=set(range(1,n+1))-column_with_zero
    #zeros.extend([(0,i) for i in column_without_zero])
    #zeros.extend([(row+1,i) for i in column_without_zero])
    zeros.extend([(0,i) for i in range(1,n+1)])
    zeros.extend([(row+1,i) for i in range(1,n+1)])
    #临时函数：用于排序
    def compare(tup1,tup2):
        if(tup1[0]!=tup2[0]):
            return tup1[0]>tup2[0]
        else:
            return tup1[1]>tup2[1]
    #元祖的比较 默认采用字典顺序 所以上面这个函数可以不使用，在这 作注释用
    #print(zeros)
    zeros.sort()
    print(zeros)
    
    return zeros,n




zeros,n=readinput()
res=solution1(zeros,n)

print(res)



