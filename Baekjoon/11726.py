import sys

input = sys.stdin.readline

n = int(input().rstrip())
dp_ways = [ None ] * (n + 1)
dp_ways[0] = -1
dp_ways[1] = 1

for i in range(2, n + 1):
  if i == 2:
    dp_ways[i] = 2
    continue
  dp_ways[i] = dp_ways[i - 1] + dp_ways[i - 2]

print(dp_ways[n] % 10007)