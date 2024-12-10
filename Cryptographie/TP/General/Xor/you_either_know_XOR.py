# I've encrypted the flag with my secret key, you'll never be able to guess it.
# Remember the flag format and how it might help you in this challenge!
# 0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104

# On sait que le flag commence par "crypto{"

a = bytes.fromhex("0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104")

# On va retrouver la clef secrète en xorant avec "crypto{"

result="crypto{"
clef = ""

for i in range(len(result)):
    clef += chr(a[i] ^ ord(result[i]))

print(clef) # -> myXORke | on a trouvé la clef secrète on rajoute "y" pour avoir "myXORkey"

clef = "myXORkey"
new_string = ""

for i in range(len(a)):
    new_string += chr(a[i] ^ ord(clef[i % len(clef)]))

print(new_string)