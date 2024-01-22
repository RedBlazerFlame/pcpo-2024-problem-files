def solve(s):
    tally = [0] * 26
    for c in s:
        tally[ord(c) - ord('A')] += 1

    max_tally = max(tally)

    if(max_tally > 1 and all(map(lambda v: v == max_tally or v == 0, tally))):
        letters = list(map(lambda i: chr(i + ord('A')), filter(lambda i: tally[i] == max_tally, range(26))))
        letters.sort()
        return f"({''.join(letters)})^{max_tally}"
    else:
        return "NO"

for _ in range(int(input())):
    print(solve(input()))