from collections import deque

n, m = map(int, input().split(" "))

adj = list(map(lambda _: [], range(n)))

for _ in range(m):
    u, v = map(lambda s: int(s) - 1, input().split(" "))
    adj[u].append(v)
    adj[v].append(u)

comp = [0] * n
cid = 1
for i in range(n):
    if(comp[i] == 0):
        q = deque()
        q.append(i)
        found = False
        while(len(q) > 0):
            i = q.popleft()
            
            if(comp[i] != 0): continue
            comp[i] = cid
            
            for j in adj[i]:
                q.append(j)
        cid += 1

Q = int(input())

for _  in range(Q):
    cnana, clili = map(lambda s: int(s) - 1, input().split(" "))
    print(f"{'' if comp[cnana] == comp[clili] else 'KONAI '}SAIKAI")