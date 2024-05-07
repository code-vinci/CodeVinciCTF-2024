#!/bin/python3

import signal
import random

TIMEOUT = 300

FLAG = "CodeVinciCTF{l0_s4i_Ch3_1_p4pAv3ri_50n_4lt1_al7i_alt1}"

HIGH_PHRASES = [
    '\nAutosave: "Eh no questo non si può salvare qui, renderebbe le cose più alte del capo. Non facciamolo arrabbiare"',
    '\nAutosave: "Aiuto! Troppo alto, soffro di vertigini io"'
]

LOW_PHRASES = [
    '\nAutosave: "Guarda che non sono mica l\'autosave di nano. Punta più in alto amigo"',
    '\nAutosave: "Non mi dispiacerebbe questo carattere messo qui, solo che è un po\' troppo basso per gli standard di colosso"',
]

def getHigh():
    return random.choice(HIGH_PHRASES)

def getLow():
    return random.choice(LOW_PHRASES)

def intro():
    print("Benvenuto su colosso, l'unico text-editor da console più alto del suo principale competitor")
    print("Con colosso avrai la possibilità di scrivere tutto quello che vuoi senza nessuna preoccupazione, grazie al comodo autosave.*\n")
    print("* L'algoritmo di autosave è basato sulla deficienza artificiale.\n  Per questo motivo è un po' schizzinoso. Ogni tanto perde anche la pazienza\n")
    print("----------------------------------------------------------------------------------------------")
    print("Nuovo Documento Senza Titolo (premi invio dopo un nuovo inserimento per richiamare l'autosave)")
    print("----------------------------------------------------------------------------------------------\n")

def handle():
    intro()
    current = ''
    for l in FLAG:
        limit = 7
        while limit != 0:
            guess = input('\n' + current)
            if len(guess) != 1:
                print('\nAutosave: "Non ci siamo capiti, io accetto solo un carattere alla volta, altrimenti le cose te le salvi da solo/a. Ciao, ciao"')
                exit(0)
            elif guess > l:
                print(getHigh())
                limit -= 1
            elif guess < l:
                print(getLow())
                limit -= 1
            else:
                current += guess
                if current == FLAG:
                    print('\nAutosave: "Oh no ci ha scoperti, stacca stacca!"')
                    exit(0)
                else:
                    print('\nAutosave: "Ok ora si ragiona, questo te lo salvo"')
                    limit = 1
                    break
        if limit == 0:
            print('\nAutosave: "Per oggi ho visto troppi caratteri discutibili. Non rompere per un po\'"')
            exit(0)


def timeout_handler(signum, frame):
    print('\nAutosave: "Basta mi sono stancato, ci stai mettendo troppo. Arrivederci"')
    exit(0)

signal.signal(signal.SIGALRM, timeout_handler)

if __name__ == "__main__":
    signal.alarm(TIMEOUT)
    handle()