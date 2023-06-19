auxa = 0
auxb = 0
n = 0

a = []
b = []
c = []

n = int(input())
a = list([int(x) for x in input().split(" ",n)])
print(a)

for i in a:
    print(type(i))
# b = input().split(" ",n)

# for i in a:
#     auxa = i + b[i]
#     auxb = i - b[i]
#     if (auxa < 0):
#         auxa = auxa * -1
#     if (auxb < 0):
#         auxb = auxb * -1
#     c[i] = list(auxa, auxb)

# print(a)
# print(b)
# print(c)