from math import comb, perm, factorial
def bij(n,m):
    if n==m:
        return factorial(n)
    return 0

def one_one(n,m):
    if n<=m:
        return perm(n,m)
    return 0

def onto(n,m):
    if m>=n:
        sum  = 0
        for l in range(n):
            sum += (-1)**l * comb(n,n-l) * (n-l)**m
        return sum
    return 0

def fun(m,n):
    return n**m

a = int(input("enter n: "))
b = int(input("enter m: "))
print("no of function from a to b",fun(a,b))
print("no of function from b to a",fun(b,a))
print("no of one one functions from a to b",one_one(a,b))
print("no of one one functions from b to a",one_one(b,a))
print("no of onto functions from a to b",onto(a,b))
print("no of onto functions from b to a",onto(b,a))
print("no of bijective functions from a to b",bij(a,b))
print("no of bijective functions from b to a",bij(b,a))