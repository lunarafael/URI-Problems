a, b, c = input().split(" ")

print(f'TRIANGULO: {(float(a) * float(c))/2:.3f}')
print(f'CIRCULO: {3.14159 * float(c)**2:.3f}')
print(f'TRAPEZIO: {(float(a)+float(b)) * float(c)/2:.3f}')
print(f'QUADRADO: {float(b)**2:.3f}')
print(f'RETANGULO: {float(a) * float(b):.3f}')