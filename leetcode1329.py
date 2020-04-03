class Solution:
    def diagonalSort(self, mat) :
        m,n=len(mat),len(mat[0])
        for i in range(-n+1,m):
            posy=range( max(i,0) ,m )
            posx=range( max(0,-i)  ,min(m-i,n))
            #print(mat[zip(posy,posx)])
            cpy=[mat[y][x] for y,x in zip(posy,posx)] 
            cpy.sort()
            for y,x,z in zip(posy,posx,cpy) :
                mat[y][x]=z 
            
        return mat

a=Solution()

b=a.diagonalSort( [[7,2,3,4],[5,6,7,8]]  )
print(b)