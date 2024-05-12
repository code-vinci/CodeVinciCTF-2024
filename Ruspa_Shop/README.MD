# Ruspa Shop
## INTRODUZIONE

RSA è uno degli schemi crittografici più famosi e usa la aritmetica modulare
DES è usa la crittografia a blocchi

## Descrizione
Benvenuto nel nostro negozio di Ruspe. Per sbaglio abbiamo
fatto cadere le chiavi e la ruspa c'è passata sopra,
riusciresti ad aggiustare la chiave?

## VULNERABILITA:
RSA implementata in questa challenge utilizza un'esponente(e) molto piccolo e un modulo (n) molto grande
per questo possiamo semplicemente fare una radice ennesima così da ottenere la chiave originale che era stata cryptata


## RISOLUZIONE

per risolvere questa challenge dobbiamo seguire i seguenti step:

1) Come prima cosa dobbiamo decryptare la chiave stampata a schermo che è cryptata con RSA,
    Ma in questa challenge RSA utilizza un'esponente molto piccolo e ha un modulo molto grande
    per questo possiamo fare una semplice radice ennesima così da ricavare il valore originale della flag
    e poi convertirla da long a bytes e dare il decode()

2)  Ora che abbiamo la chiave originale possiamo decryptare la flag,
    per decrypatare la flag basterà copiare la funzione encryptFlag() e scrivere al posto di :
    c = helper.encrypt(FLAG) 
    c = helper.decrypt(bytes.fromhex(FLAG))

3)  all'inizio, il programma diceva che la flag era stata "droppata" e quindi dobbiamo trovare l'algoritmo
    ciclico con il quale la nostra flag è stata cryptata che in realtà è la flag originale
    divisa in sotto parti da 4 caratteri e che poi scambiava la prima e ultimo carattere di queste sotto parti
    e poi univa il tutto così da ottenere questa flag

## Soluzione
```
from Crypto.Util.number import bytes_to_long, long_to_bytes, getPrime
from Crypto.Util.Padding import pad
from Crypto.Cipher import DES
from string import ascii_letters, digits
from random import randint
from sympy import root


FLAG = "a6ecb4300a5090fb6b005016601f732661b68c13fee10c8da41b55cfe779c3184bb0cff83563ffb1"
KEY = "051b1129960df4135e28739c09620ea9bb012e4c368df02ad304090aa0085d18a87c01b61786d586836f03f76b52db4a4d16aed0000000"
e = 7


def decryptFlag(key, encrypted_Flag):
    key = long_to_bytes(bytes_to_long(str(key).encode())).hex()
    key = bytes.fromhex(key)
    iv = key[::-1]
    helper = DES.new(key=key, mode=DES.MODE_CBC,iv=iv)
    p = helper.decrypt(bytes.fromhex(encrypted_Flag))
    return p.decode()

def decryptKey(key):
    n = bytes_to_long(bytes.fromhex(key))
    key = long_to_bytes(root(n,e))
    return key.decode()

dropped_flag = decryptFlag(decryptKey(KEY), FLAG)

lista = []
for i in  range(0,len(dropped_flag),4):
    l = []
    for j in range(4):
        l.append(dropped_flag[i+j])
    lista.append(l)
flag=""
for x in lista:
    x = list(x)  
    x[0], x[len(x)-1] = x[len(x)-1], x[0]  
    flag += "".join(x) 
print(flag)

```    

## Preparazione
Il server ha bisogno dei seguenti file:
- secret.py
- source.py

# Autore

`Ruspanera06`

flag droppata: `eodCcinVFCTimR3{_v30cl0bwS_k_7h1u_rA}p45`

flag: `CodeVinciCTF{R3m0v3_bl0ckS_w17h_A_ru5p4}`