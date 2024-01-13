from math import * 

d, h, w = map(int, input().split())
x = sqrt(d * d / (h * h + w * w))

print(floor(h * x), floor(w * x))