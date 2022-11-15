/**
 *
 *  Write a function to merge our vectors of orders into one sorted vector
 *
 */

#include <vector>

std::vector<int> slowerMerge(std::vector<int> &vector1, std::vector<int> &vector2)
{
    std::vector<int> combinedVector;

    combinedVector.insert(combinedVector.end(), vector1.cbegin(), vector1.cend());

    combinedVector.insert(combinedVector.end(), vector2.cbegin(), vector2.cbegin());

    std::sort(combinedVector.begin(), combinedVector.end());

    return combinedVector;

    // complexity o(n lg n)
};

std::vector<int> mergeVector(std::vector<int> &myVector, std::vector<int> &alicesVector)
{
    std::vector<int> mergedVector(myVector.size() + alicesVector.size());

    // keep track of the current indexes
    size_t currentIndexVector = 0;
    size_t currentAliceIndex = 0;
    size_t currentMergedIndex = 0;

    // traverse the length of the merged vector
    while (currentMergedIndex < mergedVector.size())
    {
        // short circuit
        bool isMyVectorExhausted = currentIndexVector >= myVector.size();
        bool isMyAliceExhausted = currentAliceIndex >= alicesVector.size();

        if (!isMyVectorExhausted && (isMyAliceExhausted || (myVector[currentIndexVector] < alicesVector[currentAliceIndex])))
        {
            mergedVector[currentIndexVector] = myVector[currentIndexVector];
            ++currentIndexVector;
        }
        else
        {
            mergedVector[currentMergedIndex] = alicesVector[currentAliceIndex];
            ++currentAliceIndex;
        };
        ++currentMergedIndex;
    };
    return mergedVector;
};

std::vector<int> proMerge(std::vector<int> &myVector, std::vector<int> &alicesVector)
{

    std::vector<int> mergedVector(myVector.size() + alicesVector.size());

    // keep track of indexes
    int currentVectorIndex = 0;
    int currentAliceIndex = 0;
    int currentMergedIndex = 0;

    while (currentMergedIndex < mergedVector.size())
    {
        bool isMyVectorExhausted = currentVectorIndex >= myVector.size();
        bool isMyAliceExhausted = currentAliceIndex >= alicesVector.size();

        if (!isMyVectorExhausted && (isMyAliceExhausted || myVector[currentVectorIndex] < alicesVector[currentAliceIndex]))
        {
            mergedVector[currentMergedIndex] = myVector[currentVectorIndex];
            ++currentVectorIndex;
        }
        else
        {
            mergedVector[currentAliceIndex] = alicesVector[currentAliceIndex];
            ++currentAliceIndex;
        };

        ++currentMergedIndex;
    };

    return mergedVector;
};