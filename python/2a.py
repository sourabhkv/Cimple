def fib(n):
    if n<=1:
        return n
    return fib(n-1) + fib(n-2)


n = int(input("enter terms: "))
for i in range(n+1):
    print(fib(i))