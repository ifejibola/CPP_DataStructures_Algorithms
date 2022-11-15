/**
 *
 * Given a vector of integers, find the highest product you can get
 *  from three of the integers
 *
 *
 */

#include <vector>
#include <stdexcept>
#include <string>

int highestProductOf3(const std::vector<int> &vectorOfInts)
{
    if (vectorOfInts.size() < 3)
    {
        throw std::invalid_argument("Less than 3 items!");
    };

    int highest = std::max(vectorOfInts[0], vectorOfInts[1]);
    int lowest = std::min(vectorOfInts[0], vectorOfInts[1]);

    int highestProductOf2 = vectorOfInts[0] * vectorOfInts[1];
    int lowestProductOf2 = vectorOfInts[0] * vectorOfInts[1];

    int highestProductOf3 = vectorOfInts[0] * vectorOfInts[1] * vectorOfInts[2];

    // walk throug items, starting at index 2
    for (size_t i = 2; i < vectorOfInts.size(); ++i)
    {
        int current = vectorOfInts[i];

        // do we have a new highest product of 3?
        highestProductOf3 = std::max(std::max(highestProductOf3, current * highestProductOf2), current * lowestProductOf2);

        // do we have the new highest product of two ?
        highestProductOf2 = std::max(std::max(highestProductOf2, current * highest), current * lowest);

        // do we have a new lost product of two?
        lowestProductOf2 = std::min(std::min(lowestProductOf2, current * highest), current * lowest);

        //  do we have a new highest?
        highest = std::max(highest, current);

        // do we have a new lowest ?
        lowest = std::min(lowest, current);
    };
    return highestProductOf3;
};

int high3(std::vector<int> &intVector)
{
    // base case
    if (intVector.size() < 2)
    {
        throw std::invalid_argument("More elements required!");
    };

    int highest = std::max(intVector[0], intVector[1]);
    int lowest = std::min(intVector[0], intVector[1]);

    int lowestProductOf2 = intVector[0] * intVector[1];
    int highestProductOf2 = intVector[0] * intVector[1];

    int highestProductOf3 = intVector[0] * intVector[1] * intVector[2];

    for (size_t i = 2; i < intVector.size(); i++)
    {
        /* code */
        int current = intVector[i];

        highestProductOf3 = std::max(std::max(highestProductOf3, current * highestProductOf2), current * lowestProductOf2);

        highestProductOf2 = std::max(std::max(highestProductOf2, current * highest), current * lowest);

        lowestProductOf2 = std::min(std::min(lowestProductOf2, current * highest), current * lowest);

        highest = std::max(highest, current);
        lowest = std::min(lowest, current);
    };

    return highestProductOf3;
};