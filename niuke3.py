import copy


a=input()
M,N=[int(i) for i in a.split()]

nums=[]

for _ in range(M):
  
    a=input()
    nums.append([int(i) for i in a.split()]) 



#从某个方向看到了m,n点
#mini出发点海拔
#除了出发点的最低点海拔
def backtrace(nums,m,n,dir,mini,mapp):
    if nums[m][n]<mini:
        return 0
    elif nums[m][n]==mini:
        if dir==0:
            mapp.append([m,n])
            return backtrace(nums,m,n-1,dir,mini,mapp)
        if dir==1:
            mapp.append([m,n])
            return backtrace(nums,m+1,n,dir,mini,mapp)
        if dir==2:
            mapp.append([m,n])
            return backtrace(nums,m,n+1,dir,mini,mapp)
        if dir==3:
            mapp.append([m,n])
            return backtrace(nums,m-1,n,dir,mini,mapp)
    else:
        mapp.append([m,n])
      
        return mini


# def look(nums,m,n):
#     t=nums[m][n]
#     mm=100
    
#     #记录水平的位置
#     rem=[[m,n]]
#     ##向下看，一直找平的
#     for i in range(m+1,M):
        
#         if nums[i][n]>t:
#             rem.append([i,n])
#             mm=min(mm,nums[i][n])
#             break
#         elif i==M or nums[i][n]<t:
#             return 0

#     ##向右看
#     cpy=copy.deepcopy(rem)

#     for j in cpy:
#         j=j[0]
#         for i in range(n+1,N):
#             try:
#                 if nums[j][i]>t:
#                     rem.append( [j,i])
#                     mm=min(mm,nums[j][i])
#                     break 
#                 elif i==N or nums[j][i]<t:
                    
#                     return 0
#             except:
#                 print(j,end=',')
#                 print(i,end='。')
    
#     nums[m][n]+=1
#     return len(rem)







def check_fill(nums,M,N):
    for m in range(1,M-1):
        for n in range(1,N-1):
            if nums[m-1][n]<nums[m][n] or nums[m][n-1]<nums[m][n]:
                continue
            kk=[[m,n]]
            a=backtrace(nums,m,n-1,0,nums[m][n],100,kk)
            b=backtrace(nums,m+1,n,1,nums[m][n],100,kk)
            c=backtrace(nums,m,n+1,2,nums[m][n],100,kk)
            d=backtrace(nums,m-1,n,3,nums[m][n],100,kk)
            e=min(a,b,c,d)
            if a>0:
                return a
    return 0           
res=0
while True:
    tmp=check_fill(nums,M,N)
    if tmp==0:
        break
    res+=tmp

print(res)
print(nums)

