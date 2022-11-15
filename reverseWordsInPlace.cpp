/**
 *
 *  Reverse Words
 *
 * Write a function reverseWords() that takes a message as a string and reverses the
 * order of the words in place. ↴
 *
 */

#include <string>

void reverseChars(std::string &str, int leftIndex, int rightIndex)
{
    // find the middle
    while (leftIndex < rightIndex)
    {
        /* code */

        // swap
        std::swap(str[leftIndex], str[rightIndex]);

        ++leftIndex;
        --rightIndex;
    }
};

void reverseWords(std::string &word)
{
    // base case
    if (word.empty())
    {
        return;
    };

    // reverse chars in place
    reverseChars(word, 0, word.length() - 1);

    size_t currentStartIndex = 0;

    for (size_t i = 0; i <= word.length(); ++i)
    {
        // find the end of each word in the string
        if (word[i] == ' ' || i == word.length())
        {
            reverseChars(word, currentStartIndex, i - 1);
            currentStartIndex = i + 1; // found the start of a new word
        };
    };
};
