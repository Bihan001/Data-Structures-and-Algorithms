def linear_search(arr, key, i=0):
    if(i >= len(arr)):
        return -1
    if(arr[i] == key):
        return i
    return linear_search(arr, key, i+1)


arr = [2, 3, 5, 6, 4, 3, 5, 6, 64, 2, 221, 32, 1, 2]

print(linear_search(arr, 100))
print(linear_search(arr, 64))
