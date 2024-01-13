import sys

input = sys.stdin.readline

n = int(input().rstrip())
tile_ways = [ 0 for _ in range(n + 1) ]

if n >= 2:
  tile_ways[2] = 3

for i in range(4, n + 1, 2):
  for j in range(i - 2, 1, -2):
    if j == i - 2:
      tile_ways[i] += tile_ways[j] * tile_ways[2]
      continue
    tile_ways[i] += tile_ways[j] * 2
  tile_ways[i] += 2

print(tile_ways[n])