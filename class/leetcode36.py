
import collections
class Solution:
    def isValidSudoku(self, board):
        return 1 == max(collections.Counter(
            x
            for i, row in enumerate(board)
            for j, c in enumerate(row)
            if c != '.'
            for x in ((c, i), (j, c), (i/3, j/3, c))
        ).values() + [1])
     
    def check(self,lis):
        s=set()
        for i in lis:
            if i!='.':
                if i in s:
                   
                    return False
                s.add(i)
        return True
    def isValidSudoku1(self, board):
        for i in board:
            if not self.check(i):
                return False
        for i in range(9):
            lis=[board[ii][i]  for ii in range(9)]
       
            if not self.check(lis):
                return False
        for i in range(0,9,3):
            for j in range(0,9,3):
                lis=[board[ii][jj] for ii in range(i,i+3) for jj in range(j,j+3)]
                if not self.check(lis):
                    return False
        return True


b=[
    ["8","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]


a=Solution()
c=a.isValidSudoku1(b)
print(c)
