# #地推公式，乘四加一

# def get(n):
    
#     return getN(n,1,3)
# def getN(n,from_,to_):
#     if(n==1):
       
#         return abs(from_-to_)
#     other=6-from_-to_
#     a=getN(n-1,from_,other)

#     b=getN(n-1,other,to_)
    
#     return a+b+1

# for i in range(14):
#     print(get(i+1))

import numpy as np
print(int(np.power(3,int(input())-1,dtype=float)*3-1))
