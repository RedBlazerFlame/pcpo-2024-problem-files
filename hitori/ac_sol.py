n, m = map(int, input().split(" "))
astig_sum = [sum(map(int, input().split(" "))) for _ in range(n)]
astig_sum.sort()
print((100.0 * m + sum(astig_sum[-3:])) / 4)