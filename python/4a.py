def insertion_sort(arr):
    for i in range(1,len(arr)):
        key = arr[i]
        j = i-1
        while j>=0 and arr[j]>key:
            arr[j+1] = arr[j]
            j-=1
        arr[j+1] = key

def merge_sort(x):
    if len(x)>1:
        mid = len(x) // 2
        left = x[:mid]
        right = x[mid:]
        merge_sort(left)
        merge_sort(right)

        i,j,k = 0,0,0
        while i < len(left) and j < len(right):
            if left[i]<=right[j]:
                x[k] = left[i]
                i+=1
            else:
                x[k] = right[j]
                j+=1
            k+=1
        
        while i < len(left):
            x[k] = left[i]
            i+=1
            k+=1
        
        while j < len(right):
            x[k] = right[j]
            j+=1
            k+=1

import random
n = int(input('enter length : '))
x = []
for i in range(n):
    x.append(random.randint(0,999))
print('before sorting')
print(x)
print('sorting using insertion sort')
insertion_sort(x)
print(x)

x = []
for i in range(n):
    x.append(random.randint(0,999))
print('\nbefore sorting')
print(x)
print('sorting using merge sort')
merge_sort(x)
print(x)