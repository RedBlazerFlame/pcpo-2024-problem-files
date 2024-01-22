from itertools import chain
from queue import Queue

n = int(input())
adj = dict()
names = dict()
start_names = []

# Finding the starting marites
for _ in range(n):
    cur_deg = int(input())
    s = input()
    e = input().split(" ")
    adj[s] = e

    for name in chain([s], e):
        if(name not in adj):
            adj[name] = []
        if(name not in names):
            names[name] = 1
        else:
            names[name] += 1
    
    start_names.append(s)

first_marites = None
for start_name in start_names:
    if(names[start_name] == 1):
        first_marites = start_name
        break

# DFS to mark the node depths
depth = dict()
to_visit = Queue()
to_visit.put((first_marites, 0))

while(not to_visit.empty()):
    cur_name, cur_depth = to_visit.get()

    if(cur_name in depth):
        continue
    depth[cur_name] = cur_depth

    for adj_name in adj[cur_name]:
        to_visit.put((adj_name, cur_depth + 1))

# Get max depth
max_depth = max(depth.values())

# List nodes with max depth
most_modified = list(map(lambda x2: x2[0], filter(lambda x: x[1] == max_depth, depth.items())))

print(" ".join(most_modified))