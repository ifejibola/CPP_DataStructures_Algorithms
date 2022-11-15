/**
 *
 * Write a function that takes a string and reverses the letter in-place
 *
 */
#include <string>
void reverseInPlace(std::string &str)
{
    // base case
    if (str.empty())
    {
        return;
    };

    size_t leftIndex = 0, rightIndex = str.length() - 1;

    // walk down the middle
    while (leftIndex < rightIndex)
    {

        // swap
        std::swap(str[leftIndex], str[rightIndex]);

        --rightIndex;
        ++leftIndex;
    };
};