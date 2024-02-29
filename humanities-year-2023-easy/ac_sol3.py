ans = 0
for i in range(1, int(input()) + 1):
    if(i % 2 == 1 and i % 3 == 2 and i % 5 == 3 and i % 7 == 5):
        ans += 1
print(ans)