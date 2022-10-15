import sys
input = sys.stdin.readline

current_time = {}
salt_time = {}
time = {}

current_time['hour'], current_time['min'], current_time['sec'] = map(int, input().rstrip().split(':'))
salt_time['hour'], salt_time['min'], salt_time['sec'] = map(int, input().rstrip().split(':'))

time['hour'] = salt_time['hour'] - current_time['hour']
time['min'] = salt_time['min'] - current_time['min']
time['sec'] = salt_time['sec'] - current_time['sec']

if time['sec'] < 0:
  time['sec'] += 60
  time['min'] -= 1
if time['min'] < 0:
  time['min'] += 60
  time['hour'] -= 1
if time['hour'] < 0:
  time['hour'] += 24

if time['hour'] == 0 and time['min'] == 0 and time['sec'] == 0:
  time['hour'], time['min'], time['sec'] = 24, 0, 0

print('{:02d}:{:02d}:{:02d}'.format(time['hour'], time['min'], time['sec']))