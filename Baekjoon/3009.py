import sys
input = sys.stdin.readline

x_dict = {}
y_dict = {}
x_ans = 0
y_ans = 0

for i in range(3):
  x, y = map(int, input().rstrip().split())
  
  if x in x_dict:
    x_dict[x] += 1
  else:
    x_dict[x] = 1
  
  if y in y_dict:
    y_dict[y] += 1
  else:
    y_dict[y] = 1
  
for key in x_dict.keys():
  if (x_dict.get(key) == 1):
    x_ans = key

for key in y_dict.keys():
  if (y_dict.get(key) == 1):
    y_ans = key

print(x_ans, y_ans)