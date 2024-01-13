import sys
input = sys.stdin.readline

while True:
  n = int(input().rstrip())
  if n == -1:
    break
  
  divisors = []

  for i in range(1, n):
    if n % i == 0:
      divisors.append(i)
  
  if n == sum(divisors):
    print('{} = '.format(n), end = '')
    print(*divisors, sep = ' + ')
  else:
    print('{} is NOT perfect.'.format(n))