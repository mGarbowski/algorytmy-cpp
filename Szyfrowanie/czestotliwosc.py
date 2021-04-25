"""
Program zlicza częstotliwość występowania znaków w pliku tekstowym,
i tworzy plik .csv z rezultatem w kolejności malejącej.
"""
import csv


TEXT_FILE = r'tekst_jawny.txt'
RESULT_FILE = r'czestotliwosc.csv'


def count_chars(file_path):
    PL = 'AĄBCĆDEĘFGHIJKLŁMNŃOÓPQRSŚTUVWXYZŹŻ'
    counter = {}
    
    with open(file_path, mode='rt', encoding='utf-8') as text:
        for line in text:
            for char in line:

                char = char.upper()
                if char not in PL:
                    continue

                if char in counter:
                    counter[char] += 1
                else:
                    counter[char] = 1

    return counter


def main():
    counter = count_chars(TEXT_FILE)
    entries = counter.items()
    entries = sorted(entries, key=lambda x: x[1], reverse=True)

    with open(RESULT_FILE, mode='wt', encoding='utf-8') as file:
        writer = csv.writer(file, lineterminator='\n')
        writer.writerows(entries)


if __name__ == '__main__':
    main()