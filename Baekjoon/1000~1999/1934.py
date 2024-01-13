import sys
input = sys.stdin.readline

def get_gcd(a, b):
  if (a > b):
    temp = b
  else:
    temp = a
  
  for i in range(1, temp + 1):
    if (a % i == 0 and b % i == 0):
      gcd = i
  
  return gcd

t = int(input().rstrip())

for i in range(t):
  a, b = map(int, input().rstrip().split())

  print(a * b // get_gcd(a, b))