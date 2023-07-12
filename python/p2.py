def bintodec(n: str):
    if len(n)==1:
        return int(n)
    
    return int(n[0]) * 2**(len(n)-1) + bintodec(n[1:])

def oct2dec(n: str):
    if len(n)==1:
        return int(n)
    
    return int(n[0]) * 8**(len(n)-1) + oct2dec(n[1:])

def maper( n: int ):
    if n <= 9:
        return str(n)
    
    s  = { 10 : "A", 11 : "B", 12 : "C", 13 : "D", 14 : "E", 15 : "F" }
    return s[n]

def dec2hex( x : int ):
    if x < 16:
        return maper( x )

    return dec2hex(x // 16) + maper(x % 16)

choice = int(input("1. Binary to decimal \n2. Octal to hexadecimal\nEnter choice : "))

if choice == 1:
    num = input("enter binary number : ")
    print(bintodec(num))

elif choice == 2:
    num = input("enter octal number : ")
    octal_num = oct2dec(num)
    print(f"oct {num} = ",dec2hex(octal_num))

else:
    print("invalid choice")