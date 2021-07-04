"""
field - kwadrat zawierajacy liczbę w każdym polu

program znajduje taką ścieżkę w kwadracie, że
zaczynająć od lewego górnego rogu suma wartości
pól przez które przejdzie będzie maksymalna

dozwolone ruchy: w dół i w prawo
"""
from random import randint
from pprint import pprint

def max_sum(field):
    # Wyliczenie sum częściowych dla 1 wiersza
    partial_sum = field[0][0]
    for col in range(1, size):
        partial_sum += field[0][col]
        field[0][col] = partial_sum

    # Wyliczenie sum częściowych dla 1 kolumny
    partial_sum = field[0][0]
    for row in range(1, size):
        partial_sum += field[row][0]
        field[row][0] = partial_sum

    # Wyliczenie sum częściowych dla pozostałych pól
    for row in range(1, size):
        for col in range(1, size):
            field[row][col] += max(field[row-1][col], field[row][col-1]) 

    return field[size-1][size-1]

size = 5
field = [[randint(1,9) for i in range(size)] for j in range(size)]
pprint(field)

print(f"Maksymalna suma w kwadracie wynosi {max_sum(field)}")
pprint(field)


