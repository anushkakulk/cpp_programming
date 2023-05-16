// Anushka Kulkarni
// 5/15/2023
// c++ to find and replace from a user-inputted paragraph
#include <iostream>
#include <string>
 
 int main(){ 
    std::string paragraph;
    std::string toBeFound;
    std::cout<< "Enter a paragraph to be analyzed: ";
    std::getline(std::cin, paragraph);
    std::cout << "-------------------------" << std::endl;
    std::cout << paragraph << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<< "Enter a sentence/word to be found within paragraph: ";
    std::getline(std::cin, toBeFound);
    std::string word = ""; 

   
    int count = 0;
    // iterate through all words in the paragraph
    for (int i = 0; i <= paragraph.length() - toBeFound.length(); i++) {
        bool found = true;
        for (int j = 0; j < toBeFound.length(); j++) {
            // check if characters don't match up
            if (paragraph[i+j] != toBeFound[j]) {
                found = false;
                break;
            }
        }
        // if the characters match up, then increment count and print out index at which
        // word is found
        if (found) {
            count++;
            std::cout << "appears at index " << i << std::endl;
        }
    }
    std::cout << "The sentence/word to be found appears a total of " << count << " times" << std::endl;
    std::string replacement;
    std::cout<< "Enter a word/sentence to replace all instances of the word/sentence that was found: ";
    std::getline(std::cin, replacement);

    // go through the whole paragraph, replacing all instances of toBeFound with replacement.
    int start = 0;
    while ((start = paragraph.find(toBeFound, start)) != std::string::npos) {
        paragraph.replace(start, toBeFound.length(), replacement);
        start += replacement.length();
    }

    std::cout << "Edited paragraph: " << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << paragraph << std::endl;
    std::cout << "-------------------------" << std::endl;

 return 0;
 }