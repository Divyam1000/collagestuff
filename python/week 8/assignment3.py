n = 10
L = list(map(int, input().split()))

count = 0
x = []
for value in L:
    if value == 0:
        count += 1
    else:
        x.append(value)
for i in range(count):
    x.append(0)
    
print(x)