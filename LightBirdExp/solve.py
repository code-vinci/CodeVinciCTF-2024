def hash( key:str, mod:int ) -> int:
    hash_value = 0
    for c in key:
        hash_value = (hash_value * 31 + ord(c)) % 4294967296
    return hash_value % mod


pointer = hash( '/flag', 256 )

for i in range( 1000 ):
    if pointer + 1 == hash( f'/flag{i}', 256 ):
        print(f'/flag{i}')
        break
