num = int(input())

for i in range(num):
    cost = 0
    farmers = int(input())
    for j in range(farmers):
        temp = input().split()
        cost += int(temp[0]) * int(temp[-1])
    print(cost)
