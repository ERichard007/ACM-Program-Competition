#include <iostream>
#include <string>
using namespace std;

char MY_LETTER[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

char getMyLetter(char letterToConvert, int intervalOfConv) {
    int myLetterInside = 0;

    for (int i = 0;i < 26;i++) {
        if (letterToConvert == MY_LETTER[i]) {
            myLetterInside = i;
            break;
        }
    }
    
    int newLetterIndex = myLetterInside - intervalOfConv; 
    newLetterIndex = (newLetterIndex < 0) ? (newLetterIndex + 26) : (newLetterIndex);

    //cout << MY_LETTER[newLetterIndex] << endl;
    return MY_LETTER[newLetterIndex];
}

int main()
{

    string encryptedMessage;
    cin >> encryptedMessage;

    string secretWord;
    cin >> secretWord;

    string key;
    string originalMessage = "";

    if (secretWord.size() > encryptedMessage.size()) {
        for (int i = 0;i < encryptedMessage.size();i++) {
            key += secretWord[i];
        }
    }
    else {
        key = secretWord;
    }

    int size = encryptedMessage.size();

    while (originalMessage.size()<size) { 

        //cout << encryptedMessage.size() << endl;

        int originalSize = originalMessage.size();
        int originalKeySize = key.size();

        for (int i = originalSize;i < originalSize + 1;i++) {  //0 - 2, 3 - 5,
            //cout << i;
            int newKeyInt = int(key[i]) - 65;
            int newKey = int(encryptedMessage[i]) - newKeyInt;
            char newLetter = getMyLetter(encryptedMessage[i], newKeyInt);

            originalMessage += newLetter;
            key += newLetter;
        }
        
    }

    cout << originalMessage; 

    return 0;
}

