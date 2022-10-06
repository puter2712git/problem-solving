import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  car_price = int(input().rstrip())
  option = int(input().rstrip())
  
  for j in range(option):
    q, p = map(int, input().rstrip().split())
    car_price += q * p
  
  print(car_price)