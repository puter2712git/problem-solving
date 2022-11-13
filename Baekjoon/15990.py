import sys

input = sys.stdin.readline

testcase = int(input().rstrip())
dp_sum_ways = [ [ 0, 0, 0 ] for _ in range(100001) ]
dp_sum_ways[1] = [ 1, 0, 0 ]
dp_sum_ways[2] = [ 0, 1, 0 ]
dp_sum_ways[3] = [ 1, 1, 1 ]

for i in range(4, 100001):
  # 1로 끝나는 경우
  dp_sum_ways[i][0] = (dp_sum_ways[i - 1][1] % 1000000009) + (dp_sum_ways[i - 1][2] % 1000000009)
  # 2로 끝나는 경우
  dp_sum_ways[i][1] = (dp_sum_ways[i - 2][0] % 1000000009) + (dp_sum_ways[i - 2][2] % 1000000009)
  # 3으로 끝나는 경우
  dp_sum_ways[i][2] = (dp_sum_ways[i - 3][0] % 1000000009) + (dp_sum_ways[i - 3][1] % 1000000009)

for _ in range(testcase):
  print(sum(dp_sum_ways[int(input().rstrip())]) % 1000000009)