import re
#without regex
def isphonenumber(number):
    if len(number)!=12:
        return False
    if number[3]!='-' and number[7]!='-':
        return False
    for i in range(len(number)):
        if i==3 or i==7:
            continue
        if not number[i].isdigit():
            return False
        
    return True

#with regex
def isphonenumber_regex(number):
    pattern = r'\d{3}-\d{3}-\d{4}'
    match = re.findall(pattern,number)
    return match is not None

ph = "999-999-9999"
print(isphonenumber_regex(ph))