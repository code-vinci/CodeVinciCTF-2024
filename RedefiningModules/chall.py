import os
from Crypto.Util.number import bytes_to_long, long_to_bytes
from secret import FLAG

def secureModuleGenerator():
    n = 1
    while len(long_to_bytes(n))*8 < 4096: # Larger modules, larger security
        x = bytes_to_long(os.urandom(1))
        while 0 <= x <= 1:
            x = bytes_to_long(os.urandom(1))
        n *= x
        n = int(str(n).strip('0'))
    return n

n = secureModuleGenerator()
e = 65537

c = pow(bytes_to_long(FLAG.encode()), e, n)

print(f"n = {n}\ne = {e}\nc = {c}")
