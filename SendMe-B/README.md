# SendMe-B

## descrizione: 
questa mucca non è simpatica e non mi vuole neanche dire la flag :(

## comando di compilazione:
gcc main.c -o cow -fno-stack-protector -O0

## soluzione: 
l'opzione corretta è la seconda, da ghidra vediamo il buffer è grande 31 bytes e l'input non è controllato
quindi inviamo 31 bytes a caso più un B per farci leggere la Flag

## flag:
da aggiungere tra le variabili di sistema una che si chiama FLAG
`export FLAG=CodeVinciCTF{n0n_s0n0_s1mp4t1ch3_l3_mucch3}`

`CodeVinciCTF{n0n_s0n0_s1mp4t1ch3_l3_mucch3}`

make by @Greva151