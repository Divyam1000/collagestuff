L = list(map(int, input().split()))
l = [0] *( max(L)+1)
for i in L:
    l[i] = i
print(*l)
    