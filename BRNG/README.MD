# BRNG

## Descrizione

Siccome ultimamente vanno di moda i servizi di generazione di immagini basati su token, ho pensato che anche agli amanti dei numeri farebbe piacere averne uno tutto loro.
Per questo motivo ho ideato il BRNG.

## Preparazione

Il servizio nc deve disporre dei file challenge.py e secret.py

## Soluzione

DISCLAIMER: per poter capire a pieno la teoria sotto a questa challenge, è necessario prima leggere con attenzione il codice per non cadere nelle piccole complicazioni aggiunte ad essa (es. il padding casuale tra ct ed esponente)

Questa challenge si basa su una vulnerabilità di rsa che si presenta cifrando due volte un certo plaintext usando lo stesso modulo ma due esponenti diversi.

Per risolvere la challenge si deve applicare l'algoritmo di euclide esteso sui due esponenti, ottenendo così due numeri a e b tali per cui:

```e1*a + e2*b = gcd(e1, e2)```

In questo caso il massimo comun divisore tra il primo ed il secondo esponente è 1, essendo i numeri entrambi primi e quindi coprimi tra loro.

Fatto questo, possiamo elevare i due ciphertexts per rispettivamente a e b, in questo modo per le proprietà delle potenze e1 ed e2 si moltiplicheranno per a e b.

Infine, i due numeri intermedi ottenuti vanno moltiplicati tra loro, ottenendo quindi (sempre per le proprietà delle potenze) il plaintext elevato alla somma degli esponenti dei numeri intermedi, che per il teorema di euclide esteso diventerà:

```pt**1```

Otteniamo quindi il plaintext.

Di seguito viene presentato un esempio di codice risolutore:
```python

from pwn import process
from Crypto.Util.number import long_to_bytes
from sage.all import *

io = process("./challenge.py")

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

```

## Flag

```CodeVinciCTF{Hey!_Com3_7i_p3rmett1_di_rub4rmi_il_5e3d!_(╯'□')╯︵ ┻━┻_}```

## Autore

`Simone Lauro`