auxa = 0
auxb = 0
n = 0

a = []
b = []
c = []

n = int(input())
a = list(int(x) for x in input().split(" ",n))
b = list(int(x) for x in input().split(" ",n))



for i in range(n):
    auxa = a[i] + b[i]
    auxb = a[i] - b[i]
    if (auxa < 0):
        auxa = auxa * -1
    if (auxb < 0):
        auxb = auxb * -1
    c.append([auxa, auxb])

print(a)
print(b)
print(c)
