from pwn import *
from Crypto.Util.number import long_to_bytes
from sage.all import *

io = remote("localhost", 1342)

io.sendlineafter(b'token)', b'')
io.recvline()
x = io.recvline(False)
ct1 = int(x[:-6])
e1 = int(x[-5:])

io.sendlineafter(b'token)', b'')
io.recvline()
n = int(io.recvline(False)[:-6])

io.sendlineafter(b'token)', b'')
io.recvline()
y = io.recvline(False)
ct2 = int(y[:-6])
e2 = int(y[-5:])

euclidean_alg_res = [int(x) for x in xgcd(e1, e2)[1:]]

pt = (pow(ct1, euclidean_alg_res[0], n) * pow(ct2, euclidean_alg_res[1], n))%n

flag = long_to_bytes(pt).decode()

print(flag)
