// Anushka Kulkarni
// 5/15/2023
// c++ to report statistics from a user-inputted paragraph
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 

// returns true if given char is a vowel
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// returns true if given char is punctuation
bool isPunctuation(char c) {
     return (c == '!' || c == '.' || c == ',' || c == ';' || c == '\"' ||
            c == '\'' || c == '?' || c == '$');
}

// returns true if word contains any punctuation
bool containsPunctuation(std::string word) {
    bool hasPunct = false;
    for (int i = 0; i < word.length(); i++) {
        if (isPunctuation(word[i])) {
            hasPunct = true;
            break;
        }
    }
    return hasPunct;
}

// returns true if word contains multiple vowels
bool containsVowels(std::string word) {
    int numVowels = 0;
    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i])) {
            numVowels++;
        }
    }
    return (numVowels > 1);
}

// returns the number of words of length greater than the given limit within the given text
int wordsGreaterThan (std::string text, int limit) {
    std::string word = ""; // for each word to be processed
    int wordsGreaterThanLength = 0;
    bool insideWord = false; 
    for (int i = 0; i < text.length(); i++) {
        char curr = text[i];
        // avoids counting punctuation as part of a word
        if (isalnum(curr)) { 
            if (!insideWord) { 
            insideWord = true;
            word = curr;
             } else { 
            word += curr;
            }
         } else { 
            if (insideWord) { 
                 if (word.length() > limit) {
                    wordsGreaterThanLength++;              
                }
                 word = "";
                insideWord = false;
            }
        }
    }

// processing last word
if (insideWord && word.length() > limit) {
    wordsGreaterThanLength++;
}
return wordsGreaterThanLength;
}

int main(){ 
    std::string paragraph;
    std::cout<< "Enter a paragraph to be analyzed: ";
    std::getline(std::cin, paragraph);
    std::cout << "-------------------------" << std::endl;
    std::cout << paragraph << std::endl;
    std::cout << "-------------------------" << std::endl;
 
    
    std::string word = ""; // for each word to be processed
    int totalWords = 0;
    int totalVowels = 0; 
    int totalConsonants = 0;
    int withPunctuation = 0;
    int withVowels = 0;
    
// iterates over each character in the paragraph
for (int i = 0; i <= paragraph.length(); i++) {
    char curr = paragraph[i];
    if (curr != ' ') {
        word += curr;
        if (isVowel(curr)) {
            totalVowels+=1;
        } else if (isalpha(curr)) {
            totalConsonants +=1;
        } 
    } else {
        
        totalWords+=1;

        if (containsPunctuation(word)) {
            withPunctuation +=1;
        }
        if (containsVowels(word)) {
            withVowels +=1;
        }
        word = "";
    }
}

// processing the last word
if (word.length() > 0) {
    totalWords += 1;

    if (containsPunctuation(word)) {
        withPunctuation += 1;
    }
    if (containsVowels(word)) {
        withVowels += 1;
    }
}
std::cout << "STATISTICS "  << std::endl;
std::cout << "total words: " << totalWords << std::endl;
std::cout << "total vowels: " << totalVowels << std::endl;
std::cout << "total consonants: " << totalConsonants << std::endl;
std::cout << "# of words with punctuation: " << withPunctuation << std::endl;
std::cout << "# of words with multiple vowels: " << withVowels << std::endl;

int maxLength;

std::cout << "Enter a number (representing a length of a word)"  << std::endl;
std::cin >> maxLength;

std::cout << "# of words of length greater than "<< maxLength << " : " << wordsGreaterThan(paragraph, maxLength) << std::endl;

srand(time(NULL));
int randNum = rand() % 5 + 6;

std::cout << "# of words of length greater than "<< randNum << " (a random # between 6 and 10) : " << wordsGreaterThan(paragraph, randNum) << std::endl;
return 0;
}