num = int(input())
lines = []
for i in range(num):
    temp = input().rstrip('\n')
    lines.append(temp)


for line in lines:
    if len(line) <= 2:
        print('+')
    elif line[-2:] == '35':
        print('-')
    elif line[0] == '9' and line[-1] == '4':
        print('*')
    else:
        print('?')
