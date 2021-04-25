PL_LOWER = 'aąbcćdeęfghijklłmnńoópqrsśtuvwxyzźż'
PL_UPPER = PL_LOWER.upper()


def encrypt_line(line, key=3):
    def encrypt_char(char, key):
        n_chars = len(PL_LOWER)

        if PL_LOWER.find(char) != -1:
            idx = PL_LOWER.find(char)
            new_idx = (idx + key) % n_chars
            return PL_LOWER[new_idx]

        elif PL_UPPER.find(char) != -1:
            idx = PL_UPPER.find(char)
            new_idx = (idx + key) % n_chars
            return PL_UPPER[new_idx]

        else:
            return char

    encrypted = [encrypt_char(c, key) for c in line]
    return ''.join(encrypted)


def decrypt_line(line, key=3):
    def decrypt_char(char, key):
        n_chars = len(PL_LOWER)

        if PL_LOWER.find(char) != -1:
            idx = PL_LOWER.find(char)
            new_idx = (idx - key) % n_chars
            return PL_LOWER[new_idx]

        elif PL_UPPER.find(char) != -1:
            idx = PL_UPPER.find(char)
            new_idx = (idx - key) % n_chars
            return PL_UPPER[new_idx]

        else:
            return char

    decrypted = [decrypt_char(c, key) for c in line]
    return ''.join(decrypted)


key = int(input('Key: ').strip())

# Encrypting
FILE_IN = r'tekst_jawny.txt'
FILE_OUT = r'szyfrogram.txt'

with open(FILE_IN, mode='rt', encoding='utf-8') as file_in:
    with open(FILE_OUT, mode='wt', encoding='utf-8') as file_out:
        for line in file_in:
            file_out.write(encrypt_line(line, key))


# Decrypting
ENCRYPTED = r'szyfrogram.txt'
DECRYPTED = r'odszyfrowany.txt'

with open(ENCRYPTED, mode='rt', encoding='utf-8') as encrypted:
    with open(DECRYPTED, mode='wt', encoding='utf-8') as decrypted:
        for line in encrypted:
            decrypted.write(decrypt_line(line, key))
