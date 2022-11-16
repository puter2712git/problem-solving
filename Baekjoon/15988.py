import sys

input = sys.stdin.readline

dp_sum = [ 0 ] * 10000001
dp_sum[1] = 1
dp_sum[2] = 2
dp_sum[3] = 4

for i in range(4, 1000001):
  dp_sum[i] = (dp_sum[i - 1] % 10000000009 + dp_sum[i - 2] % 10000000009 + dp_sum[i - 3] % 10000000009) % 1000000009

t = int(input().rstrip())

for _ in range(t):
  print(dp_sum[int(input().rstrip())])