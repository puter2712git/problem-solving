import sys
input = sys.stdin.readline

c1 = int(input().rstrip())
n = 1

while c1 != 1:
  if c1 % 2 == 0:
    c1 //= 2
  else:
    c1 = c1 * 3 + 1
  n += 1
  
print(n)