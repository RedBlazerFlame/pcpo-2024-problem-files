def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def gcd_l(ls):
    cur = ls[0]
    for v in ls:
        cur = gcd(cur, v)
    
    return cur

def ind(c):
    return ord(c) - ord("A")

def char_from_ind(i):
    return chr(i + ord("A"))

def solve(s):
    tally = [0] * 26

    for c in s:
        tally[ind(c)] += 1
    
    gcd_count = gcd_l(tally)

    if(gcd_count == 1):
        return "NO"
    
    s = []
    for i in range(26):
        for _ in range(tally[i] // gcd_count):
            s.append(char_from_ind(i))
    
    return f"({''.join(s)})^{gcd_count}"

for _ in range(int(input())):
    print(solve(input()))