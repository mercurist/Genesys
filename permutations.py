# permutations of strings with unique characters


def permutations(string_name):
    if len(string_name) == 1:
        return list(string_name)
    else:
        smaller_permutations = permutations(string_name[: len(string_name) - 1])
        last_character = string_name[len(string_name) - 1]
        final_permutations = list()

        for word in smaller_permutations:
            for i in range(5):
                modified_word = word[:i] + last_character + word[i:]
                final_permutations.append(modified_word)

        return final_permutations


word = input("Enter word : ")
collection = dict()
all_permutations = permutations(word)
for words in all_permutations:
    collection[words] = collection.get(words, 0) + 1

for k, v in collection.items():
    print(k, end=" ")
