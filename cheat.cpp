`#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool isValid(const string& str, const string& allowedLetters) {
    for (char c : str) {
        if (!isalpha(c)) // Check if character is an alphabet letter
            return false;

        // Convert both the character and allowed letters to the same case
        char lowerC = tolower(c);
        bool found = false;
        for (char allowed : allowedLetters) {
            if (tolower(allowed) == lowerC) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}

int main()
{
    string dictionaryWord;
    string letters;
    char middleLetter;
    string word;

    cout << "Enter all 7 letters: ";
    cin >> letters;

    cout << "Enter the middle letter: ";
    cin >> middleLetter;

    ifstream inputFile("words_alpha.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening dictionary file." << endl;
        return 1;
    }

    while (inputFile >> dictionaryWord)
    {
       if (isValid(dictionaryWord, letters) && (dictionaryWord.find(middleLetter) != string::npos) && dictionaryWord.length() >= 4)
        {
            cout << dictionaryWord << endl;
        }
    }

    inputFile.close(); // Close the file after reading

    cout << "\nTask completed!\n";
    return 0;
}
