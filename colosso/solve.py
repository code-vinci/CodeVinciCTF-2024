from pwn import *
from string import ascii_uppercase, ascii_lowercase, digits

possible = digits + ascii_uppercase + '_' + ascii_lowercase + '{}'

io = remote("localhost", 1341)

io.recvlines(10)

flag = ''

while True:
    bottom = 0
    top = len(possible)-1
    while True:
        middle = round((bottom+top)/2)
        io.recvline()
        io.sendline(possible[middle].encode())
        io.recvline()
        res = io.recvline(False).decode()
        if 'O' in res:
            flag += possible[middle]
            if flag[-1] == '}':
                print(flag)
                exit(0)
            break
        elif 'Aiuto' in res or 'Eh no' in res:
            top = middle
        else:
            bottom = middle
