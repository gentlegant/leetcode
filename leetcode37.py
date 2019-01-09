import turtle as t
import time
import copy

b=[
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]

b=[
    [".",".","9","7","4","8",".",".","."],
["7",".",".",".",".",".",".",".","."],
[".","2",".","1",".","9",".",".","."],
[".",".","7",".",".",".","2","4","."],
[".","6","4",".","1",".","5","9","."],
[".","9","8",".",".",".","3",".","."],
[".",".",".","8",".","3",".","2","."],
[".",".",".",".",".",".",".",".","6"],
[".",".",".","2","7","5","9",".","."]
]




class checkBorad():
    def __init__(self,x,y,data):
        self.SIZEX=x
        self.SIZEY=y
   
        self.data=data
        t.speed(0)
        t.hideturtle()
        self.draw()
        for i in range(9):
            for j in range(9):
                if(b[i][j]!='.'):
                    self.append(j,i,b[i][j])
    def draw(self):
       
        for i in range(9+1):
            if i%3==0:
                t.pensize(5)
            else:
                t.pensize(2)
            t.penup()
            t.goto(-self.SIZEX/2,-self.SIZEX/2+self.SIZEX/9*i)
            t.pendown()
            t.forward(self.SIZEX)
        t.left(90)
        for i in range(9+1):
            if i%3==0:
                t.pensize(5)
            else:
                t.pensize(2)
            t.penup()
            t.goto(-self.SIZEY/2+self.SIZEY/9*i,-self.SIZEY/2)
            t.pendown()
            t.forward(self.SIZEY) 
    def append(self,x,y,num):
        t.penup()
        t.goto(
            -self.SIZEX/2+self.SIZEX/9/2+self.SIZEX/9*x,
            self.SIZEY/2-self.SIZEY/9*y-self.SIZEY/9/2
            )
        t.write(num)
      



class Solution:
    #检查[i,j]还有哪些可行解
    def check(self,i,j,board):
        s=set('123456789')
        for c in board[i]:
            if c!='.' and c in s:
                s.remove(c)
        col=[board[v][j] for v in range(9)]
        for c in col:
            if c!='.' and c in s:
                s.remove(c)
        i=i//3*3
        j=j//3*3
        for row in range(i,i+3):
            for col in range(j,j+3):
                c=board[row][col]
                if c!='.' and c in s:
                    s.remove(c)
        return list(s)
    def append(self,x,y,board,able,num):
        board[y][x]=num
        for i in range(9):
            a=able[y][i]
            b=able[i][x]
            if i!=x and num in a:
                a.remove(num)
            if i!=y and num in b:
                b.remove(num)  
        for j in range(y//3*3,y//3*3+3):  
            for i in range(x//3*3,x//3*3+3):
                if i==x and y==j:
                    continue
                a=able[j][i]
                if num in a:
                    a.remove(num)
    def solvewithable(self,board,able,count):
        flag=False
        while count!=0:
            flag=False
            for y,row in enumerate(able):
                for x,col in enumerate(row):
                    if len(col)==1:
                        print(x,y)
                        print(count)
                        print(col[0])
                        flag=True
                        count-=1
                        self.append(x,y,board,able,col[0])
                        cb.append(x,y,col[0])
                        col.pop()
            if not flag:
                break
        #上述方法不能解决，需要采用回溯
      
        if not flag:
            rem=copy.deepcopy(board)
            remable=copy.deepcopy(able)
            for y,row in enumerate(able):
                for x,col in enumerate(row):
                    #有空格还没有填，但是该处已经不能填写了，说明有问题。返回-1
                    if board[y][x]!='.' and len(col)==0:
                        print("!!!!!!!!!!!!!!!!!!!!!!!")
                        return -1
                    if len(col)==2:
                        count-=1
                        #解压
                        a,b=col
                        #一个一个的尝试
                        self.append(x,y,board,able,a)
                        cb.append(x,y,a)
                        col.remove(b)
                        if self.solvewithable(board,able,count)==-1:
                            board=rem
                            able=remable
                            self.append(x,y,board,able,b)
                            cb.append(x,y,b)
                            col.remove(a)
                        else:
                            return 0
        return 0
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        #每个位置的可行解
        count=81
        able=[[[]]*9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j]=='.':
                
                    able[i][j]=self.check(i,j,board)
                else:
                    count-=1
        self.solvewithable(board,able,count)
        for i in able:
            print(i)
       
                

cb=checkBorad(600,600,b)


a=Solution()
a.solveSudoku(b)
print(b)
t.done()