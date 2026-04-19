#include <iostream>
#include <bitset> // Used to print binary versions of numbers

using namespace std;

int main() {
    // 1. DATA TO HIDE: 1010 1101 (Decimal 173)
    unsigned char originalData = 0xAD; 

    // 2. THE MASK: 0000 1111 (Decimal 15)
    // We want to "hide" the first 4 bits and only keep the last 4.
    unsigned char mask = 0x0F; 

    // 3. MASKING OPERATION (AND)
    // Only bits that are '1' in both the data and the mask will remain.
    unsigned char maskedData = originalData & mask;

    // 4. HIDING WITH XOR (Simple Encryption)
    // XORing with a key hides the data. XORing again with the same key reveals it.
    unsigned char key = 0x64; // 0110 0100
    unsigned char hiddenData = originalData ^ key;
    unsigned char revealedData = hiddenData ^ key;

    cout << "Original: " << bitset<8>(originalData) << " (" << (int)originalData << ")" << endl;
    cout << "Mask:     " << bitset<8>(mask) << endl;
    cout << "Masked:   " << bitset<8>(maskedData) << " (First 4 bits 'hidden')" << endl;
    cout << "---" << endl;
    cout << "Hidden:   " << bitset<8>(hiddenData) << " (XOR Encryption)" << endl;
    cout << "Revealed: " << bitset<8>(revealedData) << " (Back to original)" << endl;

    return 0;
}