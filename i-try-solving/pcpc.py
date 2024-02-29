n = int(input())

acts = [None] * n

ect = [-1] * n

for _ in range(n):
    line = list(map(int, input().split(" ")))
    act_number = line[0]
    act_dur = line[1]
    act_count = line[2]
    act_list = line[3:]
    acts[act_number - 1] = (act_dur, list(map(lambda x: x - 1, act_list)))

def compute_ect(i, acts, ect):
    # print(acts)
    if(ect[i] > -1):
        return ect[i]
    if(len(acts[i][1]) == 0):
        ect[i] = acts[i][0]
    else:
        max_ect = 0

        for act in acts[i][1]:
            compute_ect(act, acts, ect)
            max_ect = max(max_ect, ect[act] + acts[i][0])
        ect[i] = max_ect

for i in range(n):
    compute_ect(i, acts, ect)

print(max(ect))