import sys

input = sys.stdin.readline

n, k = map(int, input().rstrip().split())
dp_sum = [ [ 0 for _ in range(k + 1) ] for _ in range(n + 1) ]
dp_sum[0] = [ 0 for _ in range(k + 1) ]
dp_sum[1] = [ _ for _ in range(k + 1) ]

for i in range(2, n + 1):
  for j in range(k + 1):
    if j == 0:
      dp_sum[i][j] = 0
    elif j == 1:
      dp_sum[i][j] = j
    elif j == 2:
      dp_sum[i][j] = i + 1
    else:
      dp_sum[i][j] = dp_sum[i - 1][j] + dp_sum[i][j - 1]

print(dp_sum[n][k] % 1000000000)