name = "mr john smith"

words = name.split()

for word in words:
    print(word, end=" ")

result = "%20".join(words)
print("\n" + result)