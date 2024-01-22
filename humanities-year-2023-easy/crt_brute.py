def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def lcm_l(l):
    ans = 1

    for v in l:
        ans = lcm(ans, v)

    return ans

mods = [(1, 2), (2, 3), (3, 5), (5, 7)]

period = lcm_l(list(map(lambda x: x[1], mods)))

for i in range(period):
    poss = True
    for p, q in mods:
        if(i % q != p):
            poss = False
            break
    if(poss):
        print(i)