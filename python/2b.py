def some2dec(n, base):
    if len(n)==1:
        return int(n)
    return int( n[0] )* base**(len(n)-1) + some2dec( n[1:],base )

def maper( n ):
    if n <= 9:
        return str(n)
    s  = { 10 : "A", 11 : "B", 12 : "C", 13 : "D", 14 : "E", 15 : "F" }
    return s[n]

def dec2hex(n):
    if n<16:
        return maper(n)
    return dec2hex(n // 16) + maper(n % 16)

print('1. binary2dec \n2. octal2hex')
ch = int(input('enter choice: '))
if ch==1:
    n = input("enter binary: ")
    print(some2dec(n,2))
elif ch==2:
    n = input("enter octal number: ")
    print(dec2hex(some2dec(n,8)))