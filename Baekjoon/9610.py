import sys
input = sys.stdin.readline

point_of_quadrant = {
  'Q1': 0, 'Q2': 0, 'Q3': 0, 'Q4': 0,
  'AXIS': 0
}

n = int(input().rstrip())
for i in range(n):
  x, y = map(int, input().rstrip().split())
  
  if    x > 0 and y > 0:
    point_of_quadrant['Q1'] += 1
  elif  x < 0 and y > 0:
    point_of_quadrant['Q2'] += 1
  elif  x < 0 and y < 0:
    point_of_quadrant['Q3'] += 1
  elif  x > 0 and y < 0:
    point_of_quadrant['Q4'] += 1
  else:
    point_of_quadrant['AXIS'] += 1

for key, value in point_of_quadrant.items():
  print('{}: {}'.format(key, value))