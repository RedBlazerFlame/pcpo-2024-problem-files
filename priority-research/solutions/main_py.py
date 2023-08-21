MOD = 999983

def solve(n):
    if(n >= 1075364): return 0

    cur_term = 1
    cur_sum = 0

    for i in range(n):
        cur_sum = (cur_sum + cur_term) % MOD
        cur_term = (cur_term * cur_sum) % MOD
    
    return cur_term

print(solve(int(input())))