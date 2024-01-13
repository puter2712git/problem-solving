import sys, math
input = sys.stdin.readline

while True:
  dist, train_speed, plane_speed = map(int, input().rstrip().split())
  
  if (dist == 0 and train_speed == 0 and plane_speed == 0):
    break
  
  time_diff = round((dist / train_speed - dist / plane_speed) * 3600)
  
  hour = time_diff // 3600
  minute = (time_diff % 3600) // 60
  second = time_diff % 60
  
  print('{0}:{1:02d}:{2:02d}'.format(int(hour), int(minute), int(second)))