import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  index, rail_len, train_speed1, train_speed2, fly_speed = map(float, input().rstrip().split())
  
  print(int(index), (rail_len / (train_speed1 + train_speed2) * fly_speed))
  