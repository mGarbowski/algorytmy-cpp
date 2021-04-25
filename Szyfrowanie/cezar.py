def encode_line(line, key=3):
    n_chars = 26
    encoded = []

    for char in line:
        ascii = ord(char)
        if ord('A') <= ascii <= ord('Z'):
            new_ascii = (ascii + key - ord('A')) % n_chars + ord('A')
            encoded.append(chr(new_ascii))
        elif ord('a') <= ascii <= ord('z'):
            new_ascii = (ascii + key - ord('a')) % n_chars + ord('a')
            encoded.append(chr(new_ascii))
        else:
            encoded.append(char)

    text = ''.join(encoded)
    return text

PATH_IN = r'tekst_jawny.txt'
PATH_OUT = r'szyfrogram.txt'

with open(PATH_IN, mode='rt') as file_in:
    with open(PATH_OUT, mode='wt') as file_out:
        
        for line in file_in:
            file_out.write(encode_line(line))
