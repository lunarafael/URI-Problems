from decimal import Decimal

n = int(input())
qhora = int(input())
recebehora = Decimal(input())

print(f'NUMBER = {n}')
print(f'SALARY = U$ {qhora * recebehora:.2f}')

print('{}'.format())