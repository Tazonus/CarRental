#pragma once
#include <iostream>

using namespace std;
class FileHandler
{
public:
	string key = "klucz";

	/// <summary>
	/// Function encrypts given text using XOR crypting
	/// </summary>
	/// <param name="message">string to be encrypted</param>
	/// <returns></returns>
	string Encrypt(const string& message);

	/// <summary>
	/// Function decrypts text previously crypted with Encrypt method
	/// </summary>
	/// <param name="encryptedMessage">string to be decrypted</param>
	/// <returns></returns>
	string Decrypt(const string& encryptedMessage, const string& key);

};

