n = int(input())
l = list(map(lambda _: tuple(map(int, input().split(" "))), range(n)))
print(sum(map(lambda x: (x[2] * (x[1] - x[0])) << 1, l)) + sum(map(lambda i: (l[i][2] + l[i + 1][2]) * (l[i + 1][0] - l[i][1]), range(n - 1))))