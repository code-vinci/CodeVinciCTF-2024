# Binario incompleto

## Descrizione

AIUTO!!!!

Il treno sta per deragliare, se solo qualcuno sapesse costruire dei BINARI

## Soluzione

```
from pwn import process

io = process("./source.py")
for i in range(50):
    io.recvuntil(b"= ")
    n = int(io.recvline(False).decode())
    io.sendlineafter(b"> ", bin(n)[2:].encode())

io. interactive()
```

## Preparazione
Il server ha bisogno dei seguenti file:
- secret.py
- source.py
- server nc

## Autore
`Ruspanera06`

`CodeVinciCTF{b1n4ry_s74T10n_c4N7_wa1T}`

