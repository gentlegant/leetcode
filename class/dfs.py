

def dfs(matrix,path,n):
    
    top=path[-1]
    res=0
    for i in range(n):
        if matrix[top][i]==1 and i not in path:
            path.append(i)
            res=max(res,dfs(matrix,path,n))
            path.pop()
    return res+1
    
def solve(matrix):
    res=0
    for i in range(len(matrix)):
        path=[i]
        res=max(res,dfs(matrix,path,len(matrix)))
    return res
       
  

N=int(input())
while N!=0:
    N=N-1
    n,_=input().split()
    _=input()
    n=int(n)
    matrix=[]
    while n!=0:
        n-=1
        matrix.append([int(i) for i in input().split()[1:]])
    print(solve(matrix))