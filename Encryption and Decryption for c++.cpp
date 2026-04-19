#include <iostream>
#include <string>

using namespace std;

// encryption function;
void encryptFourDigits(string input, int encryptedResult[4]) {
    for (int i = 0; i < 4; i++) {
        int digit = input[i] - '0';
        int shifted = (digit + 4) % 10; 
        encryptedResult[i] = shifted;
    }
}
//decryyption function
void decryptFourDigits(string input, int decryptedResult[4]) {
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
    string input, output;
    int encrypted[4]; 
    int decrypted[4]; 

    // Encryption Phase
    cout << "Enter a 4-digit number to ENCRYPT: ";
    cin >> input;
    if (input.length() != 4) {
        cout << "Error: You must enter exactly 4 digits." << endl;
        return 1;
    }
    encryptFourDigits(input, encrypted);
    cout << "Encrypted Result: ";
    for (int i = 0; i < 4; i++) cout << encrypted[i];
    cout << endl << endl;

    // Decryption Phase
    cout << "Enter a 4-digit number to DECRYPT: ";
    cin >> output;
    if (output.length() != 4) {
        cout << "Error: You must enter exactly 4 digits." << endl;
        return 1;
    }
    decryptFourDigits(output, decrypted);
    cout << "Decrypted Result: ";
    for (int i = 0; i < 4; i++) cout << decrypted[i];
    cout << endl;

    return 0;
}