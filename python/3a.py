sentence = input('enter sentence : ')
words = sentence.split()
print('split sentence :',words)
words_count = len(words)
lower, upper , digit = 0,0,0
for i in sentence:
    if i.islower():
        lower+=1
    elif i.isupper():
        upper+=1
    elif i.isdigit():
        digit+=1

print('no. of words',words_count)
print('no. of lower',lower)
print('no. of upper',upper)
print('no. of digits',digit)