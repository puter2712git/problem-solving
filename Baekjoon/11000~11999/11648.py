import sys
input = sys.stdin.readline

num = str(input().rstrip())
count = 0

while int(num) >= 10:
  temp = 1
  for element in str(num):
    temp *= int(element)
  
  num = temp
  count += 1

print(count)