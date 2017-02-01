import re

stralnumcmp_re = re.compile(r'((\d+)|(\D+))')

def stralnumcmp(a0, b0):
    a = a0
    b = b0

    while len(a) > 0 and len(b) > 0:
        m_a = stralnumcmp_re.match(a)
        m_b = stralnumcmp_re.match(b)
        if m_a.group(2) and m_b.group(2):
            c = cmp(int(m_a.group(2)), int(m_b.group(2)))
        else:
            c = cmp(m_a.group(3), m_b.group(3))
        if c != 0:
            return c;
        a = a[m_a.end(1):]
        b = b[m_b.end(1):]

    return len(a0) - len(b0)
