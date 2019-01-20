n = int(input())

file_name = input()

temp = 0
result = 0
i = 0
while i < len(file_name):
    # print(file_name[i])
    if file_name[i] != 'x':
        temp = 0
    else:
        temp += 1
        if temp == 3:
            file_name = file_name[:i] + file_name[i+1:]
            temp = 0
            result += 1
            i -= 3
    i += 1

print(result)