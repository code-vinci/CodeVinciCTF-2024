from Crypto.Util.number import bytes_to_long, long_to_bytes
from Crypto.Cipher import DES
from string import ascii_letters, digits
from random import randint
from sympy import root
from secret import FLAG

TIMEOUT = 300
#Meglio generare un numero molto grande così da non essere vulnerabili
n = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
e = 7

def handle():
    print("       __________                            ")
    print("       |______   |           ____            ")
    print("       |      \  |          /  _ \  _   _    ")
    print("       |      |  |         /  / | \| |_| |   ")
    print("       |      |  |        /  /  |        |   ")
    print("  _____|______|  |_______/  /   \_______/    ")
    print("  |                         |                ")
    print("  |___   ___    ___    ____ |                ")
    print("  |_________________________|                ")
    print("     /   _     _      _   \                  ")
    print("     |  |_|   |_|    |_|  |                  ")
    print("     \____________________/              \n\n")



def banner():
    print("\n\n0. genera chiave")
    print("1. Mostra chiave")
    print("2. Mostra flag criptata")
    print("3. RUSPA!!!!")
    print("4. Arrenditi")



def encryptKey(key):
    # print(bytes_to_long(bytes.fromhex(key)))
    return long_to_bytes(pow(bytes_to_long(str(key).encode()), e, n)).hex()


def generateKey():
    lista = ascii_letters+digits
    s = "".join([lista[randint(0,len(lista)-1)] for x in range(8) ])
    return s



def encryptFlag(key):
    key = long_to_bytes(bytes_to_long(str(key).encode())).hex()
    key = bytes.fromhex(key)
    iv = key[::-1]
    helper = DES.new(key=key, mode=DES.MODE_CBC,iv=iv)
    c = helper.encrypt(FLAG)
    return c.hex()

def main():

    start = True
    while start:
        try:
            key = generateKey()
            encrypted_Flag= encryptFlag(key)
            key = encryptKey(key)
            start = False
        except ValueError:
            print(end="")

    handle()
    print("Benvenuto nel negozio di RUSPE dove rimuoviamo il problemma alla radice, ecco le varie opzioni: ")
    print("FLAG =",encrypted_Flag)
    print("KEY =", key)
    print("Be careful I accidentaly dropped the key")

    while True:
        banner()
        try:
            choice = int(input('> '))
        except ValueError:
            print('Invalid option')
            continue

        if choice < 0:
            print('Negative numbers are not allowed!')
            continue

        elif choice == 0:
            print("Ecco la nuova chiave criptata della tua ruspa:")
            start = True
            while start:
                try:
                    key = generateKey()
                    encrypted_Flag= encryptFlag(key)
                    key = encryptKey(key)
                    start = False
                except ValueError:
                    print(end="")
            print("FLAG =", encrypted_Flag)
            print("KEY =",str(key))

        elif choice == 1:
            print("KEY =",key)

        elif choice == 2:
            print("Encrypted FLAG = ", encrypted_Flag)

        elif choice == 3:
            handle()

        elif(choice == 4):
            print('Grazie per aver partecipato')
            break



if __name__=='__main__':
    main()

