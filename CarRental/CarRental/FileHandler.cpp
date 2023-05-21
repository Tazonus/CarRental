#include "FileHandler.h"
#include <iostream>
#include <cctype>

using namespace std;

string FileHandler::Encrypt(string toEncrypt) {
    char keys[3] = { this->key1, this->key2, this->key3 };
    string encrypted = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
    {
            char letter = toEncrypt[i] ^ keys[i % (sizeof(keys) / sizeof(char))];
            encrypted[i] = tolower(letter);
    }

    return encrypted;
}