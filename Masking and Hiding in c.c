#include <stdio.h>

// Helper function to print a byte in binary format
void printBinary(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
}

int main() {
    // 1. DATA TO HIDE: 1010 1101 (Hex 0xAD, Decimal 173)
    unsigned char originalData = 0xAD; 

    // 2. THE MASK: 0000 1111 (Hex 0x0F)
    // Used to "hide" the first 4 bits and keep the last 4.
    unsigned char mask = 0x0F; 

    // 3. MASKING OPERATION (AND)
    unsigned char maskedData = originalData & mask;

    // 4. HIDING WITH XOR
    unsigned char key = 0x64; 
    unsigned char hiddenData = originalData ^ key;
    unsigned char revealedData = hiddenData ^ key;

    // Outputting results
    printf("Original: "); printBinary(originalData); printf(" (%d)\n", originalData);
    printf("Mask:     "); printBinary(mask);         printf("\n");
    printf("Masked:   "); printBinary(maskedData);   printf(" (First 4 bits 'hidden')\n");
    
    printf("------------------------------------\n");
    
    printf("Hidden:   "); printBinary(hiddenData);   printf(" (XOR Encryption)\n");
    printf("Revealed: "); printBinary(revealedData); printf(" (Back to original)\n");

    return 0;
}