import random
def mergesort(x: list):
    if len(x) > 1:
        mid = len(x) // 2
        left = x[:mid]
        right = x[mid:]

        mergesort(left)
        mergesort(right)

        i, j, k = 0, 0, 0

        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                x[k] = left[i]
                i += 1
            else:
                x[k] = right[j]
                j += 1

            k += 1

        while i < len(left):
            x[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            x[k] = right[j]
            j += 1
            k += 1

def insertionSort(array):

    for step in range(1, len(array)):
        key = array[step]
        j = step - 1
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1

        array[j + 1] = key

n = int(input("enter number of elements in list:"))


mylist=[]
for i in range(n):
    mylist.append(random.randint(0,999))

print("unsorted list\n")
print(mylist)
print("sorting using insertion sort")
insertionSort(mylist)
print(mylist)



mylist=[]
for i in range(n):
    mylist.append(random.randint(0,999))
print("\n\nunsorted list\n")
print(mylist)
print("sorting using merge sort")
mergesort(mylist)
print(mylist)
