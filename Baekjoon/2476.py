import sys
input = sys.stdin.readline

def calculate_price(dice):
  if (dice[0] == dice[1] and dice[0] == dice[2]):
    return 10000 + dice[0] * 1000
  elif (dice[0] == dice[1] or dice[1] == dice[2]):
    return 1000 + dice[1] * 100
  else:
    return dice[2] * 100


max_price = 0
person_count = int(input().rstrip())

for i in range(person_count):
  dice = list(map(int, input().rstrip().split()))
  
  dice.sort()
  
  if (max_price < calculate_price(dice)):
    max_price = calculate_price(dice)

print(max_price)