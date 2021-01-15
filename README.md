# RSA-Encrypt
This program implements the RSA encryption scheme in C++ and allows for encryptng and decrypting integers.

## How RSA Encryption Works
#### Setup
1. Let *e = 65537*
2. Find two large unique prime numbers *p* and *q*
3. Calculate *n = pq*
4. Calculate *ϕ(n) = (p - 1)(q - 1)*
5. Make sure that *1 < e < ϕ(n)* and *e* is coprime with *ϕ(n)*
6. Solve the congruence *ed === (mod ϕ(n))*
7. Your public key is *(e, n)* and your private key is  *(d, n)*
 
#### Public Key *(e, n)*
* The public key is used for encrypting a message *M*
* To do so, we perform the operation *C === M^e (mod n)*
* *C* is your ciphertext (encrypted number)

#### Private Key *(d, n)*
* The private key is used for decrypted the ciphertext *C* to retrieve the original message *M*
* To retrieve *M*, we calculate *M === C^d (mod ϕ(n))*
* *M* is your original message
