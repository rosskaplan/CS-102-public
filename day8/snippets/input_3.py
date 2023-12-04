opened_file = open('README.md')

content = opened_file.read()

print(f'Number of characters: {len(content)}')
words = content.split()
print(f'Number of words: {len(words)}')
lines = content.split('\n')
print(f'Number of lines: {len(lines)}')
print(f'Number of unique words: {len(set(words))}')

opened_file.close()
