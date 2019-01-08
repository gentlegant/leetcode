import matplotlib.pyplot as plt



with open(r'.\out.txt') as file:
    for line in file:
        a,b=line.split()
        a,b=int(a),int(b)
        plt.scatter(a,b)


x=[]
y=[]
with open(r'.\out1.txt') as file: 
    for line in file:
        a,b=line.split()
        a,b=int(a),int(b)
        x.append(a)
        y.append(b)
plt.plot(x,y)
plt.show()

