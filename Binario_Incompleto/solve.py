from pwn import *

io = remote("localhost", 1347)
for i in range(50):
    io.recvuntil(b"= ")
    n = int(io.recvline(False).decode())
    io.sendlineafter(b"> ", bin(n)[2:].encode())

io. interactive()
