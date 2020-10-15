def keytocrypto():
    encr = raw_input()
    key = raw_input()
    originalMessage = ""
    if len(key) > len(encr):
        key = key[:len(encr)]
    for i in range(0, len(key)):
        originalMessage += chr(((ord(encr[i]) - ord(key[i])) % 26) + ord('A')) 
    for i in range(0, len(encr[len(key):])):
        originalMessage += chr(((ord(encr[i + len(key)]) - ord(originalMessage[i])) % 26) + ord('A')) 
    print originalMessage
keytocrypto()