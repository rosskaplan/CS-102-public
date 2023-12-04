import re

pattern = ' [0-9].[0-9][0-9] '
string = '$123.0 1.23 12.23'
matches = list(re.finditer(pattern, string))
print(matches)

pattern = '[0-9]'
string = '$123.0 1.23 12.23'
new_string = re.sub(pattern, '#', string)
print(new_string)

pattern = '^[a-zA-Z]+ [a-zA-Z]+$'
print(re.match(pattern, 'Cory Charles Nezin'))
print(re.match(pattern, 'Cory Nezin'))
