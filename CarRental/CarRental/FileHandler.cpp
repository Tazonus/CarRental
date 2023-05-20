#include "FileHandler.h"
#include <iostream>

using namespace std;

string FileHandler::Encrypt(const string& text) {
    string encryptedMessage;
    for (int a = 0; a < text.length(); a++) {
        encryptedMessage += text[a] ^ this->key[a % this->key.length()];
    }
    return encryptedMessage;
}

string FileHandler::Decrypt(const string& encryptedText, const string& key) {
    return Encrypt(encryptedText);
}