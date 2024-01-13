import sys

input = sys.stdin.readline

n = int(input().rstrip())

dp_pinary = [ [ 0, 1 ] for _ in range(n + 1)]
dp_pinary[1] = [ 0, 1 ]
if n > 1:
  dp_pinary[2] = [ 1, 0 ]

for i in range(3, n + 1):
  dp_pinary[i][0] = dp_pinary[i - 1][0] + dp_pinary[i - 1][1]
  dp_pinary[i][1] = dp_pinary[i - 1][0]

print(sum(dp_pinary[n]))