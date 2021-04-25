from czestotliwosc import count_chars
from cezar_pl import decrypt_line

PL = 'AĄBCĆDEĘFGHIJKLŁMNŃOÓPQRSŚTUVWXYZŹŻ'

ENCRYPTED = r'szyfrogram.txt'
with open(ENCRYPTED, mode='rt', encoding='utf-8') as file:
    text = file.read()


counter = count_chars(ENCRYPTED)
entries = counter.items()
entries = sorted(entries, reverse=True, key=lambda x: x[1])
keys = [entry[0] for entry in entries]


done = False
idx = 0
while not done:
    decryption_key = PL.find(keys[idx].upper())
    decrypted = decrypt_line(text, decryption_key)
    idx += 1

    print(decrypted[:20])
    command = input('Continue? [y/n]').strip()
    if command == 'n':
        done = True

print('All done')

BROKEN = r'zlamany.txt'
with open(BROKEN, mode='wt', encoding='utf-8') as file:
    file.write(decrypted)
