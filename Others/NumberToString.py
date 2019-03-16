def number_to_string(n):
    h = hex(n)[2:]
    if len(h) % 2 == 1:
        h = '0' + h
    return "".join([chr(int(h[i:i+2], 16)) for i in range(0, len(h), 2)])
