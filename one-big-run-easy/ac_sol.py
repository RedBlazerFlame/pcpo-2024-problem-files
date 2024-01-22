n = int(input())
l = list(map(lambda _: tuple(map(int, input().split(" "))), range(n)))
print(sum(map(lambda x: x[1] * x[0], l)))