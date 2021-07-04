"""
Optymalne rozwiązanie problemu plecakowego,
Program wczytuje dane z pliku plecak.csv


"""
from pprint import pprint

class Item():
    def __init__(self, index, value, weight):
        self.index = index
        self.value = value
        self.weight = weight
    def __repr__(self) -> str:
        return f"value = {self.value}\nweight = {self.weight}"


# Wczytanie danych
FILE = 'Programowanie dynamiczne\plecak.csv'
items = []
with open(FILE, mode='r') as file:
    header = file.readline()
    for line in file:
        line = line.strip().split(",")
        line = list(map(int, line))
        items.append(Item(line[0], line[1], line[2]))


def backpack(items, max_weight):
    """
    Złożoność czasowa O(max_weight * len(items))
    Złożoność pamięciowa O(max_weight * len(items))
    """
    # Wyznaczenie maksymalnej wartości dla każdej pośredniej wagi
    values = [0] * (max_weight + 1)
    item_distribution = [[0 for item in items] for weight in range(max_weight + 1)]

    for weight in range(max_weight + 1):
        for item in items:
            if item.weight <= weight:
                if values[weight - item.weight] + item.value > values[weight]:
                    values[weight] = values[weight - item.weight] + item.value

                    # Wyliczanie liczebności przedmiotów każdego rodzaju
                    # Tyle ile było przed dodaniem nowego + 1 nowy
                    for it in range(len(items)):
                        item_distribution[weight][it] = item_distribution[weight - item.weight][it]
                    item_distribution[weight][item.index] += 1

    distribution = dict(enumerate(item_distribution[-1]))
    max_value = values[-1]

    return max_value, distribution

max_weight = int(input("Max weight = ").strip())
best_value, distribution = backpack(items, max_weight)
print(f"Maksymalna wartość: {best_value}")
print(f"Ile przedmiotów {distribution}")