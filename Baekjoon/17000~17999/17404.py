import sys

input = sys.stdin.readline

n = int(input().rstrip())

min_cost = [ [ 0 for _ in range(3) ] for _ in range(n) ]
rgb = [ [ 0 for _ in range(3) ] for _ in range(n) ]
minimum = 9999999999999

for i in range(n):
  rgb[i] = list(map(int, input().rstrip().split()))

for first_color in range(3):
  for i in range(3):
    if first_color == i:
      min_cost[0][i] = rgb[0][i]
    else:
      min_cost[0][i] = 999999999999

  for i in range(1, n):
    min_cost[i][0] = min(min_cost[i - 1][1], min_cost[i - 1][2]) + rgb[i][0]
    min_cost[i][1] = min(min_cost[i - 1][0], min_cost[i - 1][2]) + rgb[i][1]
    min_cost[i][2] = min(min_cost[i - 1][0], min_cost[i - 1][1]) + rgb[i][2]

  for i in range(3):
    if i == first_color:
      continue

    minimum = min(minimum, min_cost[-1][i])

print(minimum)