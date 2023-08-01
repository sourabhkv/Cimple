n = input('enter a number: ')
if n==n[::-1]:
    print(n,' is palindrome')
else:
    print(n,' is not palindrome')

digit_count = {}
for i in n:
    if i not in digit_count:
        digit_count[i]=1
    else:
        digit_count[i]+=1

print("occurance : ",digit_count)