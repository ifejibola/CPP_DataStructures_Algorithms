

/**
 *
 *  Write an efficient function that takes stockPrices and returns the best profit
 *  I could have made from one purchase and one sale of one share of Apple stock yesterday.
 *
 */

#include <vector>
#include <stdexcept>
int getMaxProfit(const std::vector<int> &stockPrices)
{
    // base case
    if (stockPrices.size() < 2)
    {
        throw std::invalid_argument("vector requires more elements");
    };

    int minPrice = stockPrices[0];
    int maxProfit = stockPrices[1] - stockPrices[0];

    for (int i = 0; i < stockPrices.size(); ++i)
    {
        int currentPrice = stockPrices[i];

        int potentialProfit = currentPrice - minPrice;

        maxProfit = std::max(maxProfit, potentialProfit);
        minPrice = std::min(minPrice, currentPrice);
    };
    return maxProfit;
    // o(n) time and o(1) space;
};

int bestPrice(std::vector<int> &stockPrices)
{
    // base case
    if (stockPrices.size() < 2)
    {
        throw std::invalid_argument("Size > 2 Vector requried!");
    };

    int minProfit = stockPrices[0];
    int maxProfit = stockPrices[1] - stockPrices[0];

    for (size_t i = 1; i < stockPrices.size(); ++i)
    {
        int currentPrice = stockPrices[i];

        int potentialProfit = currentPrice - minProfit;

        maxProfit = std::max(maxProfit, potentialProfit);

        minProfit = std::min(minProfit, currentPrice);
    }

    return maxProfit;
};

// [5]
//     [9999, 10000]
//     [7, 6, 4, 3, 1]