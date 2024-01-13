import sys
input = sys.stdin.readline

testcase = int(input().rstrip())
for i in range(testcase):
  spaceship_count, dist = map(int, input().rstrip().split())
  count = 0
  
  for j in range(spaceship_count):
    speed, fuel_size, fuel_use = map(int, input().rstrip().split())
    
    if (fuel_size / fuel_use * speed >= dist):
      count += 1
  
  print(count)