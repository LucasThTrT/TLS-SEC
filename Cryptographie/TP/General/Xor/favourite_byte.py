# For the next few challenges, you'll use what you've just learned to solve some more XOR puzzles.
# I've hidden some data using XOR with a single byte, but that byte is a secret. 
# Don't forget to decode from hex first.
# 73626960647f6b206821204f21254f7d694f7624662065622127234f726927756d

a = bytes.fromhex("73626960647f6b206821204f21254f7d694f7624662065622127234f726927756d")

# on brut force les 256 possibilités car xor avec un seul byte
for i in range(256):
    new_string = ""
    for j in a:
        new_string += chr(j ^ i)
    # print("########################")
    # print(i, "::", new_string)    
    # print(new_string)
    # print("########################")
    if "crypto" in new_string:
        print(new_string)
        print("byte: ", i)
        break