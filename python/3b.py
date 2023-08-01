str1 = input('enter string 1: ')
str2 = input('enter tring2: ')
low = min(len(str1),len(str2))
high = max(len(str1),len(str2))
matchcnt = 0
for i in range(low):
    if str1[i]==str2[i]:
        matchcnt+=1

print('match percentage = %.2f'% (matchcnt/high))