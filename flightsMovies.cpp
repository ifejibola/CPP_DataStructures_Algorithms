
/**
 *
 * Write a function that takes :
 *      an integer :flightLength (in min)
 *      a vector of int : movieLengths (in min)
 *      returns a bool indicating : whether there are two number in movieLengths,
 *          whose sum equals flightLength
 *
 */

#include <vector>
#include <unordered_set>
bool findMovies(int flightLength, std::vector<int> &movieLengths)
{
    std::unordered_set<int> moviesSeen;

    for (int firstMovie : movieLengths)
    {
        int secondMovieFound = flightLength - firstMovie;

        if (moviesSeen.find(secondMovieFound) != moviesSeen.end())
        {
            return true;
        };
        moviesSeen.insert(firstMovie);
    };
    return false;
};

bool findTwo(std::vector<int> &movieLengths, int flightLength)
{

    // base case
    if (movieLengths.size() < 2 || movieLengths.empty())
    {
        throw std::invalid_argument("more elemnts required");
    };

    // keep track of movie lengths seen.
    std::unordered_set<int> moviesSeen;

    for (int firstMovie : movieLengths)
    {
        // find second movie
        int secondMovieFound = flightLength - firstMovie;

        if (moviesSeen.find(secondMovieFound) != moviesSeen.end())
        {
            return true;
        };

        moviesSeen.insert(firstMovie);
    };
    return false;
};
