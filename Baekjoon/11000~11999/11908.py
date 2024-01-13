import sys
input = sys.stdin.readline

card_num = int(input().rstrip())
cards = list(range(card_num))

cards = list(map(int, input().rstrip().split()))
cards.sort()

print(sum(cards) - cards[card_num - 1])