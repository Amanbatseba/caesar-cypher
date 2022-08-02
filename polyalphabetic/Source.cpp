#include<iostream>
#include<string>

using namespace std;

int main()
{
	int a, i = 0, k, nChar;
	string key;
	cout << "Enter key lower case format: ";
	cin >> key;
	int g;

	string pText = " save yourself.";
	int keyLen = key.length();
	int j = keyLen;

	cout << "\nThe Cipher text is : ";
	for (i = 0; i<pText.length(); i++) {
		if (j == keyLen) {
			j = 0;
		
		}

		k = int(key[j]) - 97;

		if (pText[i] == ' ') {
			cout << "  ";
		}
		else if (pText[i] == '.' || pText[i] == ',' || pText[i] == '!') {
		}
		else if (isupper(pText[i])) {
			int p = int(pText[i]) - 65;
			cout << char(((k + p) % 26) + 65);
			j++;
		}
		else if (islower(pText[i])) {
			int p = int(pText[i]) - 97;
			cout << char(((k + p) % 26) + 97);
			j++;
		}
	}
	cout << endl;
	system("pause");
	return 0;

}