    import math

    sqr=math.sqrt(5)
    def getN(n):

        a=(sqr+1)/2
        b=(-sqr+1)/2

        return int((math.pow(a,n)-math.pow(b,n))/sqr)
    n=int(input())
    for i in range(n):

        print(getN(int(input())+1))