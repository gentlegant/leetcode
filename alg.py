import numpy as np
def solution(matrix):
    res=0
    len=matrix.shape[1]
    dpwidth=[0 for i in range(len+1)]
    dpheight=dpwidth.copy()
    olddp1=dpheight.copy()
    olddp2=dpheight.copy()
    for row in matrix:
        for index,item in enumerate(row):
            if(item==1):
             
                dpheight[index]=min(olddp1[index],olddp1[index-1])+1
                dpwidth[index]=min(dpwidth[index-1],olddp2[index-1]) +1
                res=max(res,dpheight[index]*dpwidth[index])
            else:
                dpheight[index]=0
                dpwidth[index]=0 
        olddp1=dpheight
        olddp2=dpwidth
        print (dpwidth)
        #print(olddp1)
    return res
a=np.array([[1,0,1,1],[1,1,1,1],[1,1,1,0]])

print( solution(a))
