k, n = map(int, input().split(" "))

def argmax(l, fn):
    max_v = 0
    max_i = None

    for v in l:
        cur_v = fn(v)
        if(cur_v > max_v):
            max_v = cur_v
            max_i = v
    
    return max_i

def to_s(m, s):
    return 60 * m + s

for _ in range(k):
    rt = dict()

    for _2 in range(n):
        ng, m, s = map(int, input().split(" "))
        ts = to_s(m, s)
        genres = input().split(" ")

        for genre in genres:
            if genre not in rt:
                rt[genre] = ts
            else:
                rt[genre] += ts
    
    longest = argmax(rt.items(), lambda x: x[1])

    print(f"{longest[0]} {longest[1]}")
