/***
 *
 * Write a function getProductsOfAllIntsExceptIndex()
 * that takes a vector of integers and return a vector of the products
 *
 * you have a vector of integers, and for each index you want to find the product
 * of every integer except the integer at that index.
 *
 */

#include <vector>
#include <stdexcept>

std::vector<int> getProductsOfAllIntsExceptIndex(std::vector<int> &intVector)
{
    if (intVector.size() < 2)
    {
        throw std::invalid_argument("Getting the product of numbers at other indices requries at least 2 numbers");
    }

    // we make an array with the length of the input array to hold the products
    std::vector<int> productsOfAllIntsExceptAtIndex(intVector.size());

    // for each integer, we find the product of all the integers
    // before it, storing the total product so far each time
    int productSoFar = 1;
    for (size_t i = 0; i < intVector.size(); ++i)
    {
        productsOfAllIntsExceptAtIndex[i] = productSoFar;
        productSoFar *= intVector[i];
    };

    // for each integer, we find the product of all the integers
    // after uit. since each index in products already has the
    // product of all the integers before it, now we're storing
    // the total product of all other integers

    productSoFar = 1;
    for (size_t i = intVector.size(); i > 0; --i)
    {
        size_t j = i - 1;
        productsOfAllIntsExceptAtIndex[j] *= productSoFar;
        productSoFar *= intVector[j];
    };

    return productsOfAllIntsExceptAtIndex;
};

//[1,2,3,5]

std::vector<int> allButIndex(std::vector<int> &intVector)
{
    // base case
    if (intVector.size() < 2)
    {
        throw std::invalid_argument("more elements required");
    };

    std::vector<int> products(intVector.size());

    int productSoFar = 1;

    for (size_t i = 1; i < intVector.size(); ++i)
    {
        products[i] = productSoFar;
        productSoFar *= intVector[i];
    };

    productSoFar = 1;

    for (size_t i = intVector.size(); i > 0; --i)
    {
        size_t j = i - 1;

        products[j] *= productSoFar;
        productSoFar *= intVector[j];
    };

    return products;
}