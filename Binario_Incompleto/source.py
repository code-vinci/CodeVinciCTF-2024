#!/usr/local/bin/python

import signal
from random import randint
from secret import FLAG

TIMEOUT = 100


def main():
    print("ALLARME il treno sta per deragliare")
    print("converti queste 50 operazioni così da completare il BINARIO così da non far deragliare il treno")
    for i in range(50):
        n = randint(0, 100000000)
        print(f"n{i} = {n}")
        converted = input("> ")
        if converted != bin(n)[2:]:
            print("OH NO!!!\nIl treno è deragliato")
            exit(0)
    print("Bravo siamo arrivati a destinazione ecco la tua flag:", FLAG)




def handleTimeOut(signum, frame):
    exit(0)

signal.signal(signal.SIGALRM, handleTimeOut)

if __name__ == '__main__':
    signal.alarm(TIMEOUT)
    main()


    