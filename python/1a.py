t1 = float(input("enter marks1: "))
t2 = float(input("enter marks2: "))
t3 = float(input("enter marks3: "))
avg1 = (t1+t2)/2
avg2 = (t2+t3)/3
avg3 = (t3+t1)/3
if avg1 > avg2 and avg1 > avg3:
    print("avg1 ",avg1)
elif avg2 > avg3 and avg2 > avg1:
    print("avg2 ",avg2)
elif avg3 > avg1 and avg3 > avg1:
    print("avg3 ",avg3)