def countingSort(arr):
    #Array for storing the sorted characters
    output_array = [0 for i in range(len(arr))]
    #Array to store the count of occurences of each character
    count_array = [0 for i in range(256)]
    #Counting the occurences of characters
    for i in arr:
        count_array[ord(i)] += 1

    # Changing the value of count_array[i] so that count_array[i] contains actual
    # position of this element in the result.
    for i in range(256):
        count_array[i] += count_array[i - 1]

    #Building the output character array
    for i in range(len(arr)):
        output_array[count_array[ord(arr[i])] - 1] = arr[i]
        count_array[ord(arr[i])] -= 1

    return "".join(output_array)

arr = "hacktoberfest"
ans = countingSort(arr)
print("Character array After sorting is % s" % ("".join(ans)))
