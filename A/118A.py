
n = input()

n = n.lower()

vowels = ['a', 'i', 'u', 'e', 'o', 'y']

result = ""

for i in range(-1, len(n)):
    if i >= 0 and n[i] not in vowels:
        result += n[i]
    if i + 1 != len(n) and n[i + 1] not in vowels:
        result += "."
    

print(result)