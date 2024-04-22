
def xor(a, b): 
    repeated_key = (b * (len(a) // len(b))) + b[:len(a) % len(b)] 
    result = bytes([x ^ y for x, y in zip(a, repeated_key)]) 
    return result

plaintext = "ciao come stai spero tu stia bene e che la tua giornata stia procedendo senza intoppi oggi una bella giornata di sole perfetta per una passeggiata in riva al mare o per un picnic nel parco non vedo ora di trascorrere del tempo con te e di goderci insieme questa splendida giornata ricorda sempre di apprezzare i momenti felici e di trovare sempre il lato positivo delle cose se hai bisogno di qualcosa non esitare a chiedere sono qui per te sempre insieme possiamo affrontare qualsiasi cosa ti voglio bene"
flag = "CodeVinciCTF{0n3_Tim3_Pad_i5_n0t_s0_g08d}"

ciphertext = xor(plaintext.encode(), flag.encode())

with open("encrypted.txt", 'w') as file:
    lines = [ciphertext[i:i+len(flag)] for i in range(0, len(ciphertext), len(flag))]

    for line in lines:
        file.write(line.hex() + '\n')
