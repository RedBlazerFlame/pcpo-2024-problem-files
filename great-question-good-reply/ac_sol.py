poss_punc = [",", "!", "?", "."]

def extract_punc(s):
    res = []
    n = len(s)
    for i in range(n - 1):
        c1 = s[i]
        c2 = s[i + 1]
        if(c1 in poss_punc):
            res.append(c1)
        elif(c1 not in poss_punc and c2 in poss_punc):
            res.append(" ")
    
    if(s[-1] in poss_punc):
        res.append(s[-1])
    
    return "".join(res).split(" ")

puncs = [",", "?!", "!?", "!", "?", "."]
def compress_punc(p):
    for test_str in puncs:
        if(p.startswith(test_str)):
            return test_str

def count_punc(plist):
    tally = dict()
    for punc in puncs:
        tally[punc] = 0
    
    for p in plist:
        tally[p] += 1

    return tally

QUESTION = "great question!"
STATEMENT = "great statement!"
def solve(s):
    tally = count_punc(list(map(compress_punc, extract_punc("," + s))))

    if(tally["?!"] > 0):
        return STATEMENT
    elif(tally["!?"] > 0):
        return QUESTION
    elif(tally["?"] > 0):
        return QUESTION
    else:
        return STATEMENT

for _ in range(int(input())):
    print(solve(input()))