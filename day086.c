// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

// Input:
// - First line: an integer n

// Output:
// - Print the integer square root of n

// Examples:
// Input:
// 64

// Output:
// 8

// Input:
// 20

// Output:
// 4

// Input:
// 1

// Output:
// 1

// Explanation:
// Binary Search is applied on the range 0 to n. At each step, the middle value is squared and compared with n. If mid * mid equals n, mid is the square root. If mid * mid is less than n, search continues in the right half; otherwise, in the left half. The final answer is the largest integer whose square does not exceed n.
#include <stdio.h>

int mySqrt(int n)
{
    if (n < 2)
        return n;

    int low = 1, high = n / 2;
    int ans = 1;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n)
        {
            return (int)mid;
        }
        else if (square < n)
        {
            ans = (int)mid;
            low = (int)mid + 1;
        }
        else
        {
            high = (int)mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    printf("%d\n", mySqrt(n));

    return 0;
}