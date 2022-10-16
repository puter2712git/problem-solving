import sys
input = sys.stdin.readline

candy_num = int(input().rstrip())
candy_list = { '1': 0, '2': 0, '3': 0 }
way_count = 0

while candy_list['1'] < candy_num:
  candy_list['1'] += 2
  temp = candy_num - candy_list['1']
  
  for i in range(1, temp):
    candy_list['2'] = i
    candy_list['3'] = temp - candy_list['2']
    
    if candy_list['2'] + 2 <= candy_list['3']:
      way_count += 1

print(way_count)