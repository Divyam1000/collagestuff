def replaceV(S):
    vowels = "aeiouAEIOU"
    result = []
    count = 0

    for char in S:
        if char in vowels:
            count += 1
            if count == 3:
                l =len(result)
                del(result[l-1])
                del(result[l-2])
                result.append('_')
                count = 0
            else:
               result.append(char)
        else:
            count = 0
            result.append(char)
    return ''.join(result)

S = "aaahellooo"
output = replaceV(S)
print(output)
