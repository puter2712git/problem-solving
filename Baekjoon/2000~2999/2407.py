import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())


combinations = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

combinations[0][0] = 1

for i in range(1, n + 1):
    for j in range(0, i + 1):
        if j == 0 or j == i:
            combinations[i][j] = 1
        else:
            combinations[i][j] = combinations[i - 1][j - 1] + combinations[i - 1][j]

print(combinations[n][m])