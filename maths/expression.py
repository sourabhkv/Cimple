# not ((p or q) and (not p or r) and (not q or r)) or r
expression = "not ((p or q) and (not p or r) and (not q or r)) or r"
expression = expression.replace("and", "&")
expression = expression.replace("or","|")
expression = expression.replace("not","~")
print("Logical Expression:")
print(" X= ")
print(expression)
X=[]
print("InTruth Table:")
print(" -----------------")
print(" | p | q | r | x |")
print("-----------------")
for p in range(0,2):
    for q in range(0,2):
        for r in range(0,2):
            x = abs(eval(expression))
            X.append(x)
            print(" | "+str(p)+" | "+str(q) +" | " +str(r) + " | " + str(x) + " |" )
            print("-----------------")

check=all( i == X[0] for i in X) 
if check:
    if X[0]==0:
        print("Given logical expression is contradiction")
    else:
        print("Given logical expression is Tautology")
else:
    print("Given logical expression is neither Tautology nor contradiction")