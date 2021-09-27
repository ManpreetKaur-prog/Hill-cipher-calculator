// C++ code to implement Hill Cipher
#include <iostream>
using namespace std;

// Following function generates the
// key matrix for the key string
void getKeyMatrix(string key, int keyMatrix[][3])
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			keyMatrix[i][j] = (key[k]) % 65;
			k++;
		}
	}
}

// Following function encrypts the message
void encrypt(int cipherMatrix[][1],
	int keyMatrix[][3],
	int messageVector[][1])
{
	int x, i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 1; j++)
		{
			cipherMatrix[i][j] = 0;

			for (x = 0; x < 3; x++)
			{
				cipherMatrix[i][j] +=
					keyMatrix[i][x] * messageVector[x][j];
			}

			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

// Function to implement Hill Cipher
void HillCipher(string message, string key,int s)
{	
	// Get key matrix from the key string
	int keyMatrix[3][3];
	getKeyMatrix(key, keyMatrix);

	int messageVector[3][1];

	// Generate vector for the message
	for (int i = 0; i < 3*s; i++)
		messageVector[i][0] = (message[i]) % 65;

	int cipherMatrix[3][1];

	// Following function generates
	// the encrypted vector
	encrypt(cipherMatrix, keyMatrix, messageVector);

	string CipherText;

	// Generate the encrypted text from
	// the encrypted vector
	for (int i = 0; i < 3; i++)
		CipherText += cipherMatrix[i][0] + 65;

	// Finally print the ciphertext
	cout << CipherText;
}

// Driver function for above code
int main()
{
	// Get the message to be encrypted
	string message;
	back:
	cout << "Enter message with length of multiple on 3 only: ";
	cin >> message;
	if (message.length() % 3 != 0)
		goto back;
	int s = 0;
	// Get the key
	string key = "GYBNQKURP";
	cout << "Cipher text: ";
	while (message != "/0")
	{
		s++;
		HillCipher(message, key,s);
	}
	return 0;
}
