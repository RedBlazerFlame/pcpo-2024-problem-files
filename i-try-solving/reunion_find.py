from collections import deque

n, m = map(int, input().split(" "))

adj = list(map(lambda _: [], range(n)))

for _ in range(m):
    i, j = map(int, input().split(" "))
    adj[i - 1].append(j - 1)
    adj[j - 1].append(i - 1)

vis = [False] * n
comp_ids = [0] * n
comp_id = 0
for i in range(n):
    if(vis[i]): continue
    comp_id += 1
    q = deque()
    q.append(i)

    while(len(q) > 0):
        cur = q.pop()

        if(vis[cur]): continue
        vis[cur] = True
        comp_ids[cur] = comp_id

        for j in adj[cur]:
            q.append(j)
        

q = int(input())

for _ in range(q):
    u, v = map(int, input().split(" "))

    print("SAIKAI" if(comp_ids[u - 1] == comp_ids[v - 1]) else "KONAI SAIKAI")