# Given the string label, XOR each character with the integer 13. 
# Convert these integers back to a string and submit the flag as crypto{new_string}.

label = "label"
new_string = ""
for i in label:
    new_string += chr(ord(i) ^ 13)

print("crypto{" + new_string + "}")