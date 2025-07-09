#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/**
 * Naive String Matching Algorithm
 * Time Complexity: O(n*m) where n is text length and m is pattern length
 * @param text - The text to search in
 * @param pattern - The pattern to search for
 */
void naive(const string& text, const string& pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        cout << "Empty pattern.\n";
        return;
    }

    if (n < m) {
        cout << "Pattern is longer than text. Pattern not found.\n";
        return;
    }

    bool found = false;

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found.\n";
}

/**
 * Construct Longest Proper Prefix which is also Suffix (LPS) array
 * Helper function for KMP algorithm
 * @param pattern - The pattern string
 * @param lps - Vector to store the LPS values
 */

void construct_lps(const string& pattern, vector<int>& lps)
{
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

/**
 * Knuth-Morris-Pratt (KMP) Algorithm
 * Time Complexity: O(n+m) where n is text length and m is pattern length
 * @param text - The text to search in
 * @param pattern - The pattern to search for
 */
void kmp(const string& text, const string& pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        cout << "Empty pattern.\n";
        return;
    }

    if (n < m) {
        cout << "Pattern is longer than text. Pattern not found.\n";
        return;
    }

    vector<int> lps(m);
    construct_lps(pattern, lps);
    bool found = false;

    int i = 0, j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        cout << "Pattern not found.\n";
}

/**
 * Rabin-Karp Algorithm
 * Time Complexity: O(n+m) average case, O(n*m) worst case
 * @param text - The text to search in
 * @param pattern - The pattern to search for
 */
void rabin_karp(const string& text, const string& pattern)
{
    const int d = 256;     // Total possible ASCII characters
    const int q = 101;     // A prime number to mod hash values

    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        cout << "Empty pattern.\n";
        return;
    }

    if (n < m) {
        cout << "Pattern is longer than text. Pattern not found.\n";
        return;
    }

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int t = 0, p = 0;

    // Calculate initial hash values
    for (int i = 0; i < m; i++)
    {
        t = (d * t + (unsigned char)text[i]) % q;
        p = (d * p + (unsigned char)pattern[i]) % q;
    }

    bool found = false;

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++)
    {
        // If hash values match, do character-by-character check
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern found at index " << i << endl;
                found = true;
            }
        }

        // Calculate hash for next window
        if (i < n - m)
        {
            t = (d * (t - (unsigned char)text[i] * h) + (unsigned char)text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }

    if (!found)
        cout << "Pattern not found.\n";
}

const int ASCII_SIZE = 256; // Changed to 256 to handle full extended ASCII

/**
 * Construct Transition Table for Automata-based algorithm
 * @param pattern - The pattern string
 * @param tt - 2D vector to store the transition table
 */
void construct_transition_table(const string& pattern, vector<vector<int>>& tt)
{
    int m = pattern.length();
    
    // Initialize first row
    for (int c = 0; c < ASCII_SIZE; c++) {
        tt[0][c] = 0;
    }
    
    // Set the first character transition
    tt[0][(unsigned char)pattern[0]] = 1;
    
    // Fill the rest of the table
    int lps = 0; // longest prefix suffix
    for (int i = 1; i <= m; i++) {
        // Copy values from row at index lps
        for (int c = 0; c < ASCII_SIZE; c++) {
            tt[i][c] = tt[lps][c];
        }
        
        // Update the entry for the current character (if not beyond pattern length)
        if (i < m) {
            tt[i][(unsigned char)pattern[i]] = i + 1;
            // Update lps for next iteration
            lps = tt[lps][(unsigned char)pattern[i]];
        }
    }
}

/**
 * Automata-based String Matching Algorithm
 * Time Complexity: O(n) for search after O(m*k) preprocessing,
 * where k is the alphabet size
 * @param text - The text to search in
 * @param pattern - The pattern to search for
 */
void automata(const string& text, const string& pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        cout << "Empty pattern.\n";
        return;
    }

    if (n < m) {
        cout << "Pattern is longer than text. Pattern not found.\n";
        return;
    }

    vector<vector<int>> tt(m + 1, vector<int>(ASCII_SIZE, 0));
    construct_transition_table(pattern, tt);

    int state = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        state = tt[state][(unsigned char)text[i]];
        if (state == m)
        {
            cout << "Pattern found at index " << i - m + 1 << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found.\n";
}

/**
 * Main function
 */
int main()
{
    string text, pattern;
    
    // Take input for text and pattern
    cout << "Enter the text from which to search: ";
    getline(cin, text);

    cout << "Enter the pattern:id  ";
    getline(cin, pattern);

    // Input validation
    if (text.empty()) {
        cout << "Error: Text cannot be empty.\n";
        return 1;
    }

    int choice;
    cout << "\nSelect the approach for string matching:\n";
    cout << "1. Naive Algorithm\n";
    cout << "2. KMP Algorithm\n";
    cout << "3. Rabin-Karp Algorithm\n";
    cout << "4. Automata Algorithm\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "\nResults:\n";
    cout << "--------\n";
    
    switch (choice)
    {
    case 1:
        naive(text, pattern);
        break;
    case 2:
        kmp(text, pattern);
        break;
    case 3:
        rabin_karp(text, pattern);
        break;
    case 4:
        automata(text, pattern);
        break;
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}