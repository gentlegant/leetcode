class tree:
    def __init__(self, v):
        self.left=None
        self.right=None
        self.val=v


def travel(tree):
    stack=[]
  
    p=tree
    while len(stack)!=0 or p!=None:
       
        if p!=None:

            stack.append(p)
            p=p.left
         
         
        else:  
            p=stack[-1]
            print(p.val)
            stack.pop()
            
            p=p.right
     
      



a=tree(3)
a.left=tree(2)
a.right=tree(4)
a.right.left=tree(5)
a.left.right=tree(8)

travel(a)