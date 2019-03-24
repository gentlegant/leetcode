def solve(matrix,indegree):
    #type dict  {char:[char,char....],}
    res=0
    for begin,end in matrix:
        if begin not in indegree.keys() or indegree[begin]==0:
            #delete begin
            cpy=indegree.copy()
            for e in end:
                cpy[e]-=1
            res+=solve(matrix,cpy)

    return res


N=int(input())
while N!=0:
    N-=1
    matrix={}
    indegree={}
    path=input().split(',')
    for s in path:
        begin,end=s.split()
        if begin in matrix.keys():
            matrix[begin].append(end)
        else:
            matrix[begin]=[end]
        
        indegree[end]=indegree.get(end,0)+1
    
    ans=solve(matrix,indegree)
    print(ans)