import math
import turtle



class point:
    def __init__(self,x,y,s):
        self.x=x
        self.y=y
        self.speed=s  
        #self.tur=turtle.Turtle()


    def goto(self,p,t):
        tan=(p.y-self.y)/(p.x-self.x)
        add=self.speed/math.sqrt(tan*tan+1)
        self.x+=add*t
        self.y+=add*tan*t
        #self.tur.goto(self.x*100,self.y*100)  
    
    def gototan(self,sin,cos,t):
        self.x+=self.speed*cos*t
        self.y+=self.speed*sin*t
        #self.tur.goto(self.x*100,self.y*100)  





def distance(a,b):
    return math.sqrt((a.x-b.x)**2+(a.y-b.y)**2)
m=0
for cos in range(1,100):

    cos/=100
    sin=math.sqrt(1-cos**2)
    t=0.00001
    dog=point(0,0,4)
    people=point(0,1,1)
    for i in range(100000):
        people.gototan(sin,cos,t)
        dog.goto(people,t)
        if  distance(dog,people)<0.00001:
            print(cos*100)
            print(i*t)
            print()
            m=max(m,i*t)
            break
          
print(m)
