import sys

input = sys.stdin.readline

paper_num = int(input().rstrip())

paper = [ [ 0 for _ in range(101) ] for _ in range(101) ]
area = 0

for _ in range(paper_num):
  x, y = map(int, input().rstrip().split())

  for i in range(x, x + 10):
    for j in range(y, y + 10):
      paper[i][j] += 1

for i in range(101):
  for j in range(101):
    if paper[i][j] > 0:
      area += 1

print(area)