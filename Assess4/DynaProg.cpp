// Longest Common Subsequence

// #include <iostream>
// #include <algorithm>
// using namespace std;

// // Recursive function to find the longest common subsequence (LCS)
// int recursiveLCS(const string &X, const string &Y, int m, int n) {
//     // Base case: If either string is empty, LCS length is 0
//     if (m == 0 || n == 0)
//         return 0;
    
//     // If last characters of both strings are equal
//     if (X[m - 1] == Y[n - 1])
//         return 1 + recursiveLCS(X, Y, m - 1, n - 1);
//     else
//         // Return the maximum LCS by excluding the last character of either X or Y
//         return max(recursiveLCS(X, Y, m, n - 1), recursiveLCS(X, Y, m - 1, n));
// }

// int main() {
//     string X = "ABCBDAB", Y = "BDCAB";
    
//     // Calculate the length of LCS using the recursive approach
//     int lcsLength = recursiveLCS(X, Y, X.size(), Y.size());
    
//     // Output the result
//     cout << "Length of LCS (Recursive): " << lcsLength << endl;
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Function to print the dp table
// void printDPTable(const vector<vector<int>> &dp) {
//     cout << "DP Table (c-table):" << endl;
//     for (const auto &row : dp) {
//         for (int val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// // Function to print the longest common subsequence
// void printLCS(const string &X, const string &Y, const vector<vector<int>> &dp) {
//     int m = X.size(), n = Y.size();
//     string lcs;
//     int i = m, j = n;

//     while (i > 0 && j > 0) {
//         if (X[i - 1] == Y[j - 1]) {
//             lcs.push_back(X[i - 1]);
//             i--;
//             j--;
//         } else if (dp[i - 1][j] > dp[i][j - 1]) {
//             i--;
//         } else {
//             j--;
//         }
//     }
    
//     reverse(lcs.begin(), lcs.end());
//     cout << "LCS: " << lcs << endl;
// }

// // Bottom-up dynamic programming LCS function
// int bottomUpLCS(const string &X, const string &Y) {
//     int m = X.size(), n = Y.size();
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//     // Fill dp table using bottom-up approach
//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (X[i - 1] == Y[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }

//     // Print the dp table
//     printDPTable(dp);

//     // Print the LCS
//     printLCS(X, Y, dp);

//     return dp[m][n];
// }

// int main() {
//     string X = "ABCBDAB", Y = "BDCAB";
//     int lcsLength = bottomUpLCS(X, Y);
//     cout << "Length of LCS (Bottom-up DP): " << lcsLength << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Function to print the memoization table
// void printMemoTable(const vector<vector<int>> &memo) {
//     cout << "Memoization Table:" << endl;
//     for (const auto &row : memo) {
//         for (int val : row) {
//             if (val == -1)
//                 cout << "- ";
//             else
//                 cout << val << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// // Top-down memoized LCS function
// int memoizedLCS(const string &X, const string &Y, int m, int n, vector<vector<int>> &memo) {
//     if (m == 0 || n == 0)
//         return 0;
    
//     if (memo[m][n] != -1)
//         return memo[m][n];
    
//     if (X[m - 1] == Y[n - 1])
//         memo[m][n] = 1 + memoizedLCS(X, Y, m - 1, n - 1, memo);
//     else
//         memo[m][n] = max(memoizedLCS(X, Y, m, n - 1, memo), memoizedLCS(X, Y, m - 1, n, memo));
    
//     return memo[m][n];
// }

// int main() {
//     string X = "ABCBDAB", Y = "BDCAB";
//     int m = X.size(), n = Y.size();
    
//     // Initialize the memoization table with -1
//     vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    
//     // Compute the LCS using top-down memoization
//     int lcsLength = memoizedLCS(X, Y, m, n, memo);
    
//     // Print the memoization table
//     printMemoTable(memo);
    
//     // Print the length of the LCS
//     cout << "Length of LCS (Memoized DP): " << lcsLength << endl;
    
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Function to print the current state of the dp array
// void printDPTable(const vector<int> &dp, int step) {
//     cout << "Step " << step << " - DP Array: ";
//     for (int val : dp) {
//         cout << val << " ";
//     }
//     cout << endl;
// }

// // Bottom-up dynamic programming LCS function using one table
// int oneTableLCS(const string &X, const string &Y) {
//     int m = X.size(), n = Y.size();
//     vector<int> dp(n + 1, 0); // Using a single 1D array for the DP table
//     int step = 0; // Step counter for tracking updates

//     // Fill dp table using bottom-up approach with a single array
//     for (int i = 1; i <= m; ++i) {
//         int prev = 0; // Variable to store dp[i-1][j-1] equivalent
//         for (int j = 1; j <= n; ++j) {
//             int temp = dp[j]; // Save current dp[j] before it gets updated
//             if (X[i - 1] == Y[j - 1])
//                 dp[j] = prev + 1;
//             else
//                 dp[j] = max(dp[j], dp[j - 1]);
//             prev = temp; // Update prev for the next column
//         }
//         // Print the dp array after processing each row of X
//         printDPTable(dp, ++step);
//     }
//     return dp[n];
// }

// int main() {
//     string X = "ABCBDAB", Y = "BDCAB";
//     int lcsLength = oneTableLCS(X, Y);
//     cout << "Length of LCS (One Table DP): " << lcsLength << endl;
//     return 0;
// }

// Rod Cutting problem

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
//     vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    
//     for (int i = 0; i <= n; i++) {
//         for (int w = 0; w <= W; w++) {
//             if (i == 0 || w == 0)
//                 dp[i][w] = 0;
//             else if (wt[i - 1] <= w)
//                 dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
//             else
//                 dp[i][w] = dp[i - 1][w];
//         }
//     }
    
//     return dp[n][W];
// }

// int main() {
//     int n = 3;
//     vector<int> val = {60, 100, 120};
//     vector<int> wt = {10, 20, 30};
//     int W = 50;
    
//     cout << "Maximum value: " << knapsack(W, wt, val, n) << endl;
    
//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// int fiba(int n, vector<int>& dp) {
//     if (n == 1) return 0;
//     if (n == 2) return 1;
//     if (n == 3) return 2;
    
//     if (dp[n] != -1) return dp[n];  // Return the cached result if already computed
    
//     dp[n] = fiba(n - 1, dp) + fiba(n - 2, dp) + fiba(n - 3, dp);  // Recursive call
//     return dp[n];
// }

// int main() {
//     int n;
//     cin >> n;
    
//     vector<int> dp(n + 1, -1);  // Initialize dp table with -1 (uncomputed values)
    
//     cout << "fiba(" << n << "): " << fiba(n, dp) << endl;
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int rodCuttingBruteForce(int n, vector<int>& price) {
//     if (n == 0) return 0; // Base case: no rod left

//     int maxRevenue = 0;
    
//     // Try cutting the rod at each length and recursively calculate revenue
//     for (int i = 1; i <= n; i++) {
//         maxRevenue = max(maxRevenue, price[i - 1] + rodCuttingBruteForce(n - i, price));
//     }
    
//     return maxRevenue;
// }

// int main() {
//     vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // Prices for rod lengths 1, 2, ..., 8
//     int n;

//     cout << "Enter length of rod: ";
//     cin >> n;

//     cout << "Maximum revenue: " << rodCuttingBruteForce(n, price) << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int rodCuttingDP(int n, vector<int>& price, vector<int>& dp) {
//     if (n == 0) return 0; // Base case: no rod left
    
//     if (dp[n] != -1) return dp[n]; // If already computed, return memoized result

//     int maxRevenue = 0;

//     // Try cutting the rod at each length and recursively calculate revenue
//     for (int i = 1; i <= n; i++) {
//         maxRevenue = max(maxRevenue, price[i - 1] + rodCuttingDP(n - i, price, dp));
//     }

//     dp[n] = maxRevenue; // Memoize the result for the current length
//     return dp[n];
// }

// int main() {
//     vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // Prices for rod lengths 1 to 8
//     int n;

//     cout << "Enter the length of the rod: ";
//     cin >> n;

//     vector<int> dp(n + 1, -1); // DP array to store the maximum revenue for each length

//     cout << "Maximum revenue: " << rodCuttingDP(n, price, dp) << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int rodCuttingBottomUp(int n, vector<int>& price) {
    vector<int> dp(n + 1, 0); // dp[i] represents the maximum revenue for a rod of length i
    
    // Fill dp array using bottom-up approach
    for (int i = 1; i <= n; i++) {
        int maxRevenue = 0;
        // Try all possible cuts for length i
        for (int j = 1; j <= i; j++) {
            maxRevenue = max(maxRevenue, price[j - 1] + dp[i - j]);
        }
        dp[i] = maxRevenue; // Store the maximum revenue for rod of length i
    }

    return dp[n]; // The maximum revenue for rod of length n
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // Prices for rod lengths 1 to 8
    int n;

    cout << "Enter the length of the rod: ";
    cin >> n;

    cout << "Maximum revenue: " << rodCuttingBottomUp(n, price) << endl;

    return 0;
}



