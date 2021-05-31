// Copyright (c) Year Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: May 28, 2021
// This program asks the user to enter a string,
// how many characters of the string, and how
// many times those characters should be repeated
// before displaying the subword

#include <iostream>
#include <string>

// define variables
int charNumberInt, charNumberIntIndex, i = 0, timesRepeatedInt, len, counter;
int subwordStartInt;
char c;
std::string mainWord, charNumberString, mainWordSub;
std::string timesRepeatedString, outputSub = "", subwordStartString;


int output() {
    // output the subword repeated number of times specified
    for (counter = 0; counter < timesRepeatedInt; counter++) {
        outputSub = outputSub + mainWordSub;
    }
    std::cout << "\n";
    std::cout << outputSub;
}


int repetition() {
    while (true) {
        // ask user how many times to repeat subword
        std::cout << "How many times should the subword repeat: ";
        std::cin >> timesRepeatedString;

        try {
            // check if input is an integer
            timesRepeatedInt = std::stoi(timesRepeatedString);

            if (timesRepeatedInt <= 0) {
                // check if input is not positive
                std::cout << timesRepeatedInt << " is not a positive number, ";
                std::cout << "try again.\n";
            } else {
                output();
                break;
            }
        } catch (std::invalid_argument) {
            // error message if not an integer
            std::cout << timesRepeatedString << " is not a positive number, ";
            std::cout << "try again.\n";
        }
    }
}


int subwordSize() {
    while (true) {
        // ask user to enter the size of the subword
        std::cout << "Enter the size of the subword: ";
        std::cin >> charNumberString;

        try {
            // check if size is an integer
            charNumberInt = std::stoi(charNumberString);
            i = subwordStartInt;
            charNumberIntIndex = i + charNumberInt;
            mainWordSub = "";
            while (i < charNumberIntIndex) {
                // create the subword
                c = mainWord[i];
                mainWordSub += c;
                i++;
            }

            if (charNumberInt <= 0) {
                // check if size is a not positive
                std::cout << charNumberInt << " is not a positive number, ";
                std::cout << "try again.\n";
            } else {
                len = mainWord.length();
                if (charNumberInt <= len) {
                    // check if size is not bigger than word
                    std::cout << "\n";
                    repetition();
                    break;
                } else {
                    // error message if size is too big
                    std::cout << mainWordSub << " does not have that many ";
                    std::cout << "characters, try again.\n";
                }
            }
        } catch (std::invalid_argument) {
        // error message if not an integer
        std::cout << charNumberString << " is not a positive number, ";
        std::cout << "try again.\n";
        }
    }
}


int subwordStart() {
    while (true) {
        // ask the user where the subword will start
        std::cout << "At what index will the subword start? ";
        std::cin >> subwordStartString;

        try {
            // check if input is an integer
            subwordStartInt = std::stoi(subwordStartString);
            if (subwordStartInt < 0) {
                // check if size is negative
                std::cout << subwordStartInt << " is negative, try again.\n";
            } else {
                len = mainWord.length();
                if (subwordStartInt <= len) {
                    // check if size is not bigger than word
                    std::cout << "\n";
                    subwordSize();
                    break;
                } else {
                    // error message if size is too big
                    std::cout << mainWord << " does not have that many ";
                    std::cout << "characters, try again.\n";
                }
            }
        } catch (std::invalid_argument) {
            // error message if not an integer
            std::cout << subwordStartString << " is not a valid number, ";
            std::cout << "try again.\n";
        }
    }
}


int main() {
    // ask user to enter a string
    std::cout << "Enter a string: ";
    std::cin >> mainWord;
    std::cout << "\n";
    subwordStart();
}
