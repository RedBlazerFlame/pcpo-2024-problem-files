from collections import deque

n, m = map(int, input().split(" "))
cnana, clili = map(lambda s: int(s) - 1, input().split(" "))

adj = list(map(lambda _: [], range(n)))

for _ in range(m):
    u, v = map(lambda s: int(s) - 1, input().split(" "))
    adj[u].append(v)
    adj[v].append(u)

q = deque()
vis = [False] * n
q.append(cnana)
found = False

while(len(q) > 0):
    i = q.popleft()
    
    if(vis[i]): continue
    vis[i] = True
    if(i == clili):
        found = True
        break
    
    for j in adj[i]:
        q.append(j)

print(f"{'' if found else 'KONAI '}SAIKAI")