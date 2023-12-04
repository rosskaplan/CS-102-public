with open('output.txt', 'w') as opened_file:
    opened_file.write('Hello, ')
    opened_file.write('world')
    opened_file.write('!')

with open('output.txt') as opened_file:
    print(opened_file.read())
