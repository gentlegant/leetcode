import math
# def solve(p):
#     #  n（n+1）（2n+1）/6
#     #ax*x*x+bx*x+cx+d=p
#     # a=1/3
#     # b=1/2
#     # c=1/6
#     # d=-p
#     A=1/12
#     B=1/12+3*p
#     C=1/36+3/2*p
 
#     delata=B*B-4*A*C
#     print(delata)
  
#     sqr=math.sqrt(delata)
#     #delata肯定大于0
#     flag1=False
#     Y1=-1/2*p-sqr/2
#     Y2=-1/2*p+sqr/2
#     if Y1<0:
#         Y1=-Y1
#         flag1=True
#     y1_3=math.pow(Y1,1/3)
#     if flag1:
#         y1_3=-y1_3
#     X=-1/2-y1_3-math.pow(Y2,1/3)
#     return X
        


def solve(p):
    end=math.pow((6*p),1/3)
    for res in range(1,int(end)+1):
        tmp=(1/3)*res*res*res+(1/2)*res*res+(1/6)*res
        if tmp==p:
            return res
        if tmp>p:
            return res-1
 
t=int(input())
for _ in range(t):
    p=int(input())
    print(solve(p))
 
