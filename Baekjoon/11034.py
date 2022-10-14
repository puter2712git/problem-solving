import sys
input = sys.stdin.readline

while True:
  try:
    locations = list(map(int, input().rstrip().split()))
    
    print(max(locations[2] - locations[1], locations[1] - locations[0]) - 1)
  except:
    break