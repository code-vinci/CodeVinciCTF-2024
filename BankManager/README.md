# Bank Manager

## Introduzione
Ho creato questo programma che simula una banca, puoi controllare se ci sono dei bug?

## Vulnerabilità 
OneByteOverflow

## Risoluzione
L'obbiettivo della challenge è sbloccare l'opzione `[0] - Show flag` nel menù delle azioni sull'account della banca, per farlo, durante la registrazione bisogna inserire un password di  `32 caratteri` in modo tale da sovrascrivere il valore di `.level` e risultare autenticati

## Flag
da aggiungere tra le variabili di sistema una che si chiama FLAG
`export FLAG=CodeVinciCTF{Ar3_You_4uth0riz3d?}`
`CodeVinciCTF{Ar3_You_4uth0riz3d?}`

make by @Gioppy    