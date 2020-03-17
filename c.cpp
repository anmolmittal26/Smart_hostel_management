from collections import defaultdict
from collections import deque

n,m = map(int,input().split())
d = defaultdict(list)
q = []
for i in range(m):
    l,r = map(int,input().split())
    d[l].append(r)
    d[r].append(l)
    q.append([l,r])

db = defaultdict(list)   
l = 0
a = deque()
a.append(1)
a.append(-1)
visited = [0]*(n+1)
visited[1] = 1
turn = 1

while len(a)!=0:
    t = a.popleft()
    if t==-1:
        if len(a)==0:
            break
        else:
            l+=1
            a.append(-1)
    else:
        if turn==1:
            for i in d[t]:
                if visited[i]==0:
                    db[t].append(i)
                    a.append(i)
                    visited[i]=1
        if turn==0:
            for i in d[t]:
                if visited[i]==0:
                    db[i].append(t)
                    a.append(i)
                    visited[i]=1
        turn = abs(turn-1)

s = ''
for i in (q):
    l,r = i[0],i[1]
    if l in db[r]:
        s+='1'
    else:
        s+='0'
        
print("YES")
print(s)