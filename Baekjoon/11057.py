import sys

input = sys.stdin.readline

n = int(input().rstrip())
dp_stair = [ [ 0 for _ in range(10) ] for _ in range(n + 1) ]
dp_stair[1] = [ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ]

for i in range(2, n + 1):
  for j in range(0, 10):
    for k in range(j, 10):
      dp_stair[i][j] += dp_stair[i - 1][k]
    dp_stair[i][j] % 10007

print(sum(dp_stair[n]) % 10007)