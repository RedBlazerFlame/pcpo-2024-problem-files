import sys
sys.setrecursionlimit(300000)

N = int(input())
act_data = [None] * N
for _ in range(N):
    act_num, act_dur, act_count, *act_ipa = map(int, input().split(" "))
    act_data[act_num - 1] = act_dur, list(map(lambda i: i - 1, act_ipa))

memo = [-1] * N
def compute_ect(act_data, act_num):
    if(memo[act_num] == -1):
        act_dur, act_ipas = act_data[act_num]
        memo[act_num] = max(map(lambda act: compute_ect(act_data, act), act_ipas)) + act_dur if len(act_ipas) > 0 else act_dur
    return memo[act_num]

for i in range(N):
    compute_ect(act_data, i)

print(max(memo))