def selectionSort(arr):
    for i in range(len(arr)):
        mini = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[mini]:
                mini = j 
        arr[i], arr[mini] = arr[mini], arr[i]
        
        
def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1;
        while(j >= 0 and arr[j] > key):
            arr[j + 1] = arr[j]
            j-=1
        arr[j + 1] = key
        
def mergeSort(arr):
    if len(arr) > 1:
        m = len(arr) // 2
        L = arr[:m]
        R = arr[m:]
        
        mergeSort(L)
        mergeSort(R)
        
        i, j, k = 0, 0, 0
        
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k+=1
        
        while i < len(L):
            arr[k] = L[i]
            i+=1
            k+=1
        
        while j < len(R):
            arr[k] = R[j]
            j+=1
            k+=1

def quickSort(arr, l, r):
    if l < r:
        pivot = partition(arr, l, r)
        quickSort(arr, l, pivot - 1)
        quickSort(arr, pivot + 1, r)
        
def partition(arr, l, r):
    pivot = arr[r]
    storeIndex = l -1
    for i in range(l, r):
        if arr[i] < pivot:
            storeIndex += 1
            arr[i], arr[storeIndex] = arr[storeIndex], arr[i]
    
    arr[storeIndex + 1], arr[r] = arr[r], arr[storeIndex + 1]
    return storeIndex + 1

def countingSort(arr):
    m = max(arr) + 1
    count = [0] * m
    output = [0] * len(arr)
    
    for i in arr:
        count[i] += 1
    
    for i in range(1, len(count)):
        count[i] += count[i - 1]
    
    for i in range(len(arr)):
        output[count[arr[i]]- 1] = arr[i]
        count[arr[i]] -= 1
    
    print(output)
    
if __name__ == '__main__':
    arr = [3, 2, 4, 5, 1]
    
    countingSort(arr)
    # print(arr)