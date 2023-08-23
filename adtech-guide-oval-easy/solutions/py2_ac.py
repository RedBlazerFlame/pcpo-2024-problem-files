N = int(input())
res = ""

for i in range(N):
    for j in range(N - i):
        res += "-"
    for j in range(2 * (N + i)):
        res += "#"
    for j in range(N - i):
        res += "-"
    res += "\n"

for i in range(N):
    for j in range(N):
        res += "#"
    for j in range(2 * N):
        res += "-"
    for j in range(N):
        res += "#"
    res += "\n"

for i in range(N):
    for j in range(i + 1):
        res += "-"
    for j in range(4 * N - 2 * (i + 1)):
        res += "#"
    for j in range(i + 1):
        res += "-"
    res += "\n"

print(res, end="")