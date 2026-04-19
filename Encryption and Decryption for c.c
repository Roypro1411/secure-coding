#include <stdio.h>
#include <string.h>

// Encryption function
void encryptFourDigits(char input[], int encryptedResult[4]) {
    for (int i = 0; i < 4; i++) {
        int digit = input[i] - '0';
        int shifted = (digit + 4) % 10;
        encryptedResult[i] = shifted;
    }
}

// Decryption function
void decryptFourDigits(char input[], int decryptedResult[4]) {
    for (int i = 0; i < 4; i++) {
        int digit = input[i] - '0';
        int shifted = digit - 4;
        if (shifted < 0) {
            shifted += 10;
        }
        decryptedResult[i] = shifted;
    }
}

int main() {
    char input[10]; 
    char output[10];
    int encrypted[4];
    int decrypted[4];

    // Encryption Phase
    printf("Enter a 4-digit number to ENCRYPT: ");
    scanf("%s", input);

    if (strlen(input) != 4) {
        printf("Error: You must enter exactly 4 digits.\n");
        return 1;
    }

    encryptFourDigits(input, encrypted);

    printf("Encrypted Result: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", encrypted[i]);
    }
    printf("\n\n");

    // Decryption Phase
    printf("Enter a 4-digit number to DECRYPT: ");
    scanf("%s", output);

    if (strlen(output) != 4) {
        printf("Error: You must enter exactly 4 digits.\n");
        return 1;
    }

    decryptFourDigits(output, decrypted);

    printf("Decrypted Result: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", decrypted[i]);
    }
    printf("\n");

    return 0;
}