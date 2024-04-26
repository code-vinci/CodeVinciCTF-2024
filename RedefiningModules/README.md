# Redefining Modules

## Descrizione

Ecco la mia versione sperimentale di un nuovo sistema di generazione di moduli per RSA!
Dato che uso un generatore di numeri crittograficamente sicuri, nulla può rompere i miei moduli, credo.
P.S. la decifratura può causare la formazione di artefatti, oh beh, l'ho detto che era sperimentale!

## Soluzione

Per generare il modulo, il codice moltiplica tra loro tanti numeri di un solo byte non necessariamente primi (da cui derivano gli "artefatti", ops l'ho fatto apposta).
Un moderno computer non ha grande difficoltà nel fattorizzare numeri di questo tipo, di conseguenza non ha nemmeno grande difficoltà a trovare phi(n). Detto ciò possiamo invertire l'esponente pubblico e decifrare il messaggio.

```python

from sympy import totient, factorint
from Crypto.Util.number import bytes_to_long, long_to_bytes

with open("output.txt", "r") as f:
    n = int(f.readline()[4:])
    e = int(f.readline()[4:])
    c = int(f.readline()[4:])

d = pow(e, -1, int(totient(n)))
m = pow(c, d, n)
print(long_to_bytes(m))

```

## Flag

`CodeVinciCTF{1_9u35s_my_modu1e5_wer3n't_so_53cure_aft3r_a1l}`


## Autore

`Simone Lauro`
