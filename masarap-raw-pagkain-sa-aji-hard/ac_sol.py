X, n = map(int, input().split(" "))
p = list(map(int, input().split(" ")))
min_p = min(p)
p = list(filter(lambda x: x > 0, p))
dp = [0]
for i in range(1, X + 1):
    max_prev = max(map(lambda curp: dp[i - curp] if i - curp >= 0 else -1, p))
    dp.append(max_prev + 1 if max_prev >= 0 else -1)
print(f"{dp[-1]} {X // min_p}" if min_p > 0 else f"{'0' if dp[-1] == -1 else 'infinite'} infinite")