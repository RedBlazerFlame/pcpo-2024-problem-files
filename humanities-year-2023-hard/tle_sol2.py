n, k = map(int, input().split(" "))
ans = 0
for i in range(1, n + 1):
    mods = [i % 2 == 1, i % 3 == 2, i % 5 == 3, i % 7 == 5]
    count = sum(map(lambda x: 1 if x else 0, mods))
    if(count == k):
        ans += 1
    

print(ans)