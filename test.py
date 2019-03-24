import torch as t
from torch.optim import SGD



a=t.randn(1,10).requires_grad_()


optim=SGD([a],lr=0.81)
for i in range(1000):
    b=t.softmax(a,1)

    loss=(b-a)**2
    loss=loss.sum()
    
    optim.zero_grad()
    loss.backward()
    optim.step()
    if i%10==0:
        print(i)
        print(a)
        print(loss)

print(a)