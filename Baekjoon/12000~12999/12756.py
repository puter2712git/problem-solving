import sys
input = sys.stdin.readline

a_card = { 'attack': 0, 'health': 0 }
b_card = { 'attack': 0, 'health': 0 }

a_card['attack'], a_card['health'] = map(int, input().rstrip().split())
b_card['attack'], b_card['health'] = map(int, input().rstrip().split())

while a_card['health'] > 0 and b_card['health'] > 0:
  a_card['health'] -= b_card['attack']
  b_card['health'] -= a_card['attack']

if a_card['health'] > 0:
  print('PLAYER A')
elif b_card['health'] > 0:
  print('PLAYER B')
else:
  print('DRAW')