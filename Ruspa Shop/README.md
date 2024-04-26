# INTRODUZIONE

RSA è uno degli schemi crittografici più famosi e usa la aritmetica modulare
DES è usa la crittografia a blocchi


# VULNERABILITA:
RSA implementata in questa challenge utilizza un'esponente(e) molto piccolo e un modulo (n) molto grande
per questo possiamo semplicemente fare una radice ennesima così da ottenere la chiave originale che era stata cryptata


# RISOLUZIONE

per risolvere questa challenge dobbiamo seguire i seguenti step:

1:  Come prima cosa dobbiamo decryptare la chiave stampata a schermo che è cryptata con RSA,
    Ma in questa challenge RSA utilizza un'esponente molto piccolo e ha un modulo molto grande
    per questo possiamo fare una semplice radice ennesima così da ricavare il valore originale della flag
    e poi convertirla da long a bytes e dare il decode()

2:  Ora che abbiamo la chiave originale possiamo decryptare la flag,
    per decrypatare la flag basterà copiare la funzione encryptFlag() e scrivere al posto di :
    c = helper.encrypt(FLAG) 

    c = helper.decrypt(bytes.fromhex(FLAG))

3:  all'inizio, il programma diceva che la flag era stata "droppata" e quindi dobbiamo trovare l'algoritmo
    ciclico con il quale la nostra flag è stata cryptata che in realtà è la flag originale
    divisa in sotto parti da 4 caratteri e che poi scambiava la prima e ultimo carattere di queste sotto parti
    e poi univa il tutto così da ottenere questa flag
    
`flag droppata: eodCcinVFCTimR3{_v30cl0bwS_k_7h1u_rA}p45`
`flag: CodeVinciCTF{R3m0v3_bl0ckS_w17h_A_ru5p4}`

made by @haroldboom06

