#ifndef BASE64_H
#define BASE64_H

int base64_encode(int infd, int outfd);
int base64_decode(int infd, int outfd);

char* ERROR_MSG[2] = { "OK", "ERROR" };

extern char encode_table[64];
extern char PADDING_SYMBOL;

#endif
