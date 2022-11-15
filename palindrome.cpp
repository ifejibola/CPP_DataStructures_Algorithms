/**
 *
 * Write an efficient function that checks wheter any permutation of an input is a palindrome.
 *
 *
 *
 */
#include <unordered_set>
#include <string>
bool hasPalidromePermutation(const std::string &str)
{
    // chatacters we've seen an odd number of times
    std::unordered_set<char> unpairedCharacters;

    for (char c : str)
    {
        if (unpairedCharacters.find(c) != unpairedCharacters.end())
        {
            unpairedCharacters.erase(c);
        }
        else
        {
            unpairedCharacters.insert(c);
        }
    }

    return unpairedCharacters.size() <= 1;
}

bool isPremutation(const std::string str)
{
    std::unordered_set<char> unpairedCharacters;

    for (char c : str)
    {
        if (unpairedCharacters.find(c) != unpairedCharacters.end())
        {
            unpairedCharacters.erase(c);
        }
        else
        {
            unpairedCharacters.insert(c);
        }
    }

    return unpairedCharacters.size() <= 1;
};