t = int(input())

for i in range(0, t):
  x = input().split()
  y = float(x[0])

  for j in x[1:]:
    if (j == '@'):
      y = y * 3
    if (j == '%'):
      y = y + 5
    if (j == '#'):
      y = y - 7
  
  print("{:.2f}".format(y))