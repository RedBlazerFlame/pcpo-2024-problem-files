n, k = map(int, input().split(" "))
pois = []

for i in range(0, 210):
    mods = [i % 2 == 1, i % 3 == 2, i % 5 == 3, i % 7 == 5]
    count = sum(map(lambda x: 1 if x else 0, mods))
    if(count == k):
        pois.append(i)

nm210 = n % 210
extra_add = len(list(filter(lambda poi: poi <= nm210, pois)))

print(len(pois) * ((n) // 210) + extra_add - (1 if k == 0 else 0))