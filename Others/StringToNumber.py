import codecs


def string_to_number(s):
    return int(codecs.encode(s.encode('utf-8'), 'hex'), 16)
