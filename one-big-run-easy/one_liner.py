print(sum(map(lambda x: x[1] * x[0], list(map(lambda _: tuple(map(int, input().split(" "))), range(int(input())))))))