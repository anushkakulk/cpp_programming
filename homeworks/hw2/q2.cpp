// Anushka Kulkarni
// 5/22/2023
// c++ program to scans a file for common text/phrases uses for phishing scams
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct Keyword
{
    std::string key;
    int val;
};

/*
I wanted to separate my logic into this function rather than
do everything in the main method, yet I was consistently getting an
error (that I asked for help with on Piazza)

void analyzeForPhishing(const std::string &filename, const Keyword phishingKeywords[], int numKeywords)
{
}
*/

int main()
{
    Keyword phishingKeywords[30] = {
        {"urgent", 1},
        {"credit card", 2},
        {"account", 1},
        {"personal information", 2},
        {"SSN", 2},
        {"verify", 1},
        {"placed on hold", 2},
        {"bank", 2},
        {"update", 1},
        {"security", 2},
        {"fraud", 2},
        {"password", 2},
        {"alert", 1},
        {"invoice", 2},
        {"important", 2},
        {"login", 2},
        {"as soon as possible", 2},
        {"Outlook", 1},
        {"Apple", 1},
        {"PayPal", 2},
        {"Amazon", 2},
        {"Netflix", 2},
        {"Google", 2},
        {"locked for security reasons", 1},
        {"click the link", 1},
        {"free", 3},
        {"hurry", 2},
        {"suspicious", 2},
        {"action required", 3},
        {"Expiration notice", 2}};

    std::ifstream inputFile("phishing.txt");
    // std::ifstream inputFile("notphishing.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the input file." << std::endl;
        return 1;
    }

    int numOccurrences[30] = {0};

    std::string line;
    while (std::getline(inputFile, line))
    {
        for (int i = 0; i < 30; ++i)
        {
            size_t pos = line.find(phishingKeywords[i].key);
            while (pos != std::string::npos)
            {
                numOccurrences[i]++;
                pos = line.find(phishingKeywords[i].key, pos + 1);
            }
        }
    }

    int totalPoints = 0;
    for (int i = 0; i < 30; ++i)
    {
        std::string keyword = phishingKeywords[i].key;
        int occurrences = numOccurrences[i];
        int points = occurrences * phishingKeywords[i].val;

        std::cout << std::setw(30) << std::left << keyword;
        std::cout << " | Occurrences: " << occurrences << ", Point Total: " << points << std::endl;
        totalPoints += points;
    }

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Total points for the entire message: " << totalPoints << std::endl;

    inputFile.close();

    return 0;
}

/*
PHISHING FILE: taken from a phishing text i actually recieved, I noticed many of the
keywords were correctly found and noted down to give the file a high score

NOT A PHISHING FILE: taken from an email sent by northeastern, I noticed that
a high score was not found since no key words were used in the email
*/