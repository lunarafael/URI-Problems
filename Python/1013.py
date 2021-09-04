a, b, c = input().split(" ")
a = int(a)
b = int(b)
c = int(c)

p1 = (a + b + abs(a - b)) / 2;
maior = (c + p1 + abs(c - p1)) / 2;

print(f'{int(maior)} eh o maior')