import sys

input = sys.stdin.readline

n = int(input().rstrip())
cards = [ None ]
cards += list(map(int, input().rstrip().split()))
dp_cards = [ None ] * (n + 1)
dp_cards[1] = cards[1]

for i in range(2, n + 1):
  dp_cards[i] = cards[i]
  for j in range(1, i):
    dp_cards[i] = min(dp_cards[i], dp_cards[i - j] + cards[i - (i - j)])

print(dp_cards[n])