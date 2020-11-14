def binary_search(arr, key, l, h):
    if(l > h):
        return -1
    mid = (l+h) // 2
    if(key == arr[mid]):
        return mid
    if(key < arr[mid]):
        return binary_search(arr, key, l, mid - 1)
    else:
        return binary_search(arr, key, mid+1, h)


arr = [2, 3, 5, 6, 4, 3, 5, 6, 64, 2, 221, 32, 1, 2]

arr.sort()

print(arr)

print(binary_search(arr, 64, 0, len(arr)))
