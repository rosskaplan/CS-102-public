age = 23
greeting = 'hi'
gpa = 3.0

str1 = greeting + ' I am ' + str(age) + ' years old and my gpa is ' + str(gpa)
print(str1)

str2 = '%s I am %s years old and my gpa is %s' % (greeting, age, gpa)
print(str2)

str3 = '{} I am {} years old and my gpa is {}'.format(greeting, age, gpa)
print(str3)

str4 = '{greeting} I am {age} years old and my gpa is {gpa}'.format(
        greeting=greeting, age=age, gpa=gpa)
print(str4)

str5 = f'{greeting} I am {age} years old and my gpa is {gpa}'
print(str5)
