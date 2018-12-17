import re

REGEX_ASTRAL_SYMBOLS = re.compile(r'[\uD800-\uDBFF][\uDC00-\uDFFF]', re.UNICODE)

def count_symbols(string):
    return len(REGEX_ASTRAL_SYMBOLS.sub('_', string))
