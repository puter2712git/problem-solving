import sys

input = sys.stdin.readline

testcase = int(input().rstrip())
dp_ways = [ None ] * 12
dp_ways[0] = -1
dp_ways[1] = 1
dp_ways[2] = 2
dp_ways[3] = 4

for i in range(4, len(dp_ways)):
  dp_ways[i] = dp_ways[i - 1] + dp_ways[i - 2] + dp_ways[i - 3]

for i in range(testcase):
  print(dp_ways[int(input().rstrip())])