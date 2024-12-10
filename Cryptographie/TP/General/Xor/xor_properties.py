# 1 KEY1 = a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313
# 2 KEY2 ^ KEY1 = 37dcb292030faa90d07eec17e3b1c6d8daf94c35d4c9191a5e1e
# 3 KEY2 ^ KEY3 = c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1
# 4 FLAG ^ KEY1 ^ KEY3 ^ KEY2 = 04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf

# on transforme les hexa en bytes
# on xor : 4 ^ 3 = FLAG ^ KEY 1 puis xor avec KEY 1 pour avoir FLAG

KEY1 = bytes.fromhex("a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313")
KEY2_KEY3 = bytes.fromhex("c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1")
FLAG_KEYS = bytes.fromhex("04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf")

FLAG = bytes([FLAG_KEYS[i] ^ KEY1[i] ^ KEY2_KEY3[i] for i in range(len(FLAG_KEYS))])

print(FLAG)