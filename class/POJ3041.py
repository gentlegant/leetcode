N,K=[int(i) for i in input().split()]
likes={}

love={}
def fallinlove(a,b):
    love[a]=b
    love[b]=a


for _ in range(K):
    boy,girl=[int(i) for i in input().split()]
    girl=-girl
    if boy in likes:
        likes[boy].append(girl)
    else:
        likes[boy]=[girl]
    if girl in likes:
        likes[girl].append(boy)
    else:
        likes[girl]=[boy]
   
def findlove(one,cantlove):
    
    for liked in likes[one]:
        if liked in cantlove:
            continue
        cantlove.append(liked)
        if liked not in love or findlove(love[liked],cantlove):
            love[liked]=one
            return True
    return False



for one,onelikes in likes.items():

    findlove(one,cantlove=[])

print(love)

print(len(love)//2)