# Wydawanie reszty metodą dynamiczną

amount = int(input("Kwota = ").strip())
values = input("Nominały, oddzielone przecinkami:\n").strip().split(',')
values = list(map(int, values))


def how_many_coins(amount, values):

    # Każdy wynik będzie mniejszy od amount + 1
    how_many = {0: 0}  # amount: coins
    for i in range(1, amount+1):
        how_many[i] = amount + 1

    for curr_amount in range(amount + 1):
        for val in values:
            if val <= curr_amount:
                if how_many[curr_amount - val] + 1 < how_many[curr_amount]:
                    how_many[curr_amount] = how_many[curr_amount - val] + 1



    return how_many[amount]

how_many = how_many_coins(amount, values)
print(f"Potrzeba w sumie {how_many} monet")



