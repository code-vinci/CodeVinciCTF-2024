# Colosso

## Descrizione

Siamo lieti di presentarvi il futuro dei text-editor da console. Colosso è semplicemente il più alto (e quindi il migliore) di tutti, data la vasta quantità di righe che comporta la scrittura di una semplice frase. Inoltre, il nostro autosave intelligente vi seguirà in ogni momento (forse troppo). Nano, guarda e impara...

## Preparazione

Il servizio nc deve esporre solo challenge.py

## Soluzione

Questa challenge è risolvibile applicando un algoritmo di binary search su un set relativamente ristretto di caratteri ascii (messi comunque in ordine).

Utilizzare l'intero codice ascii non funzionerebbe per il modo in cui è setuppata la challenge. Infatti, il numero massimo di tentativi necessari per trovare ogni carattere della flag con questo algoritmo, usando l'intero codice ascii, è 8, mentre la challenge prevede un numero massimo di 7 tentativi per carattere.

Ecco un esempio di codice risolutivo:

```python
from pwn import process
from string import ascii_uppercase, ascii_lowercase, digits

possible = digits + ascii_uppercase + '_' + ascii_lowercase + '{}'

io = process('./challenge.py')

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
```

## Flag

```CodeVinciCTF{l0_s4i_Ch3_1_p4pAv3ri_50n_4lt1_al7i_alt1}```

## Autore

`Simone Lauro`