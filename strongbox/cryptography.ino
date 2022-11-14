/*
  modexp
  Input : The base a, the exposant e and n
  Output: The remainder of the euclidean division of a^e by n
  Effect: Modular exponentiation
*/

// Why is "e" signed ? ¯\_(ツ)_/¯
// It can't be negative but meh, there's a check in the logigram so let's do it like this !

uint16_t modexp(uint16_t a, int16_t e, uint16_t n) {
  // r is signed in order to be able to return -1 in case the impossible is true
  int16_t r;
  if (e < 0) {
    Serial.println("Authentication error : e was negative !");
    return (-1);
  }
  if (a == 0 || n == 1) {
    r = 0;
  } else {
    r = 1;
    while (e > 0) {
      r = (r * (a % n)) % n;
      e = e - 1;
    }
  }
  return r;
}

/*
  encrypt
  Input : An integrer a, a public key m
  Output: The encrypted a
  Effect: Encryption of a using the m key, using RSA Algorithm
*/
uint16_t encrypt(uint16_t m, uint16_t e) {
  uint16_t n = 43 * 67;  // n = 2881
  uint16_t c = modexp(m, e, n);
  return c;
}