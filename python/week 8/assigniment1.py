def squareT(T):
    T1 = tuple(y for y in T if y == 2 
    T2 = tuple(y**2 for y in T )
    T3 = T1 + T2
    return T3
T = (1,2,3)
print(squareT(T))
