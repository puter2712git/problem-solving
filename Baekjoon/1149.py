import sys

input = sys.stdin.readline

n = int(input().rstrip())
dp_price = [ [ 0 for _ in range(3) ] for _ in range(n) ]

for i in range(n):
  rgb = list(map(int, input().rstrip().split()))
  
  if i == 0:
    dp_price[i] = rgb
    continue
  
  for j in range(3):
    dp_price[i][j] = min(dp_price[i - 1][(j + 1) % 3], dp_price[i - 1][(j + 2) % 3]) + rgb[j]

print(min(dp_price[n - 1]))