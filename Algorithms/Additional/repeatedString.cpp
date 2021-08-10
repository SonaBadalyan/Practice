// There is a string, s, of lowercase English letters that is repeated infinitely many times. 
// Given an integer, n, find and print the number of letter a's in the first n letters of the infinite string.

#include <iostream>
#include <string>
#include <algorithm>

long repeatedString(std::string s, long n) 
{
    if ( 1 == s.size() && 'a' == s[0])
        return n;
    else if (1 == s.size() && 'a' != s[0])
        return 0;

    long count = 0; // std::count(s.begin(), s.end(), 'a');

    for (int i = 0; i < s.size(); ++i)
    {
        if ('a' == s.at(i))
        {
            ++count;
        }
    }

    count = count * n / s.size();

    long reminder =  n % s.size();

    // count += std::count(s.begin(), s.begin() + reminder, 'a');

    for (int i = 0; i != reminder; ++i)
    {
        if ('a' == s.at(i))
        {
            ++count;
        }
    }

    return count;
}

int main()
{
    std::string s = "aab";
    long n = 10;

    std::cout << repeatedString(s, n) << std::endl;
    
    return 0;
}