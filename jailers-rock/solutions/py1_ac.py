A = int(input())

i = 0
ans = (-1, -1)
while ((i + 1) * (i + 1) < A):
    i += 1
    if(A % i != 0): continue
    f2 = A // i
    if(((i + f2) & 0b1) == 1): continue
    ans = ((f2 - i) >> 1, (f2 + i) >> 1)
    break

if(ans == (-1, -1)):
    print("impossible")
else:
    print("possible")
    print(f"{ans[0]} {ans[1]}")