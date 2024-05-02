#include <stdio.h>
#include <string.h>

// Function to compute the Longest Prefix Suffix (LPS) array for the pattern
void computeLPSArray(char* pat, int M, int* lps);

// Function to perform pattern search using the Knuth-Morris-Pratt (KMP) algorithm
void KMPSearch(char* pat, char* txt) {
    int M = strlen(pat); // Length of the pattern
    int N = strlen(txt); // Length of the text

    int lps[M]; // LPS array for the pattern
    computeLPSArray(pat, M, lps); // Compute the LPS array

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < N) {
        if (pat[j] == txt[i]) { // If characters match, move both indices
            j++;
            i++;
        }

        if (j == M) { // If pattern fully matches
            printf("Found pattern at index %d\n", i - j); // Print the starting index of the pattern
            j = lps[j - 1]; // Move j to the end of the prefix that matches the suffix
        } else if (i < N && pat[j] != txt[i]) { // If characters don't match
            if (j != 0)
                j = lps[j - 1]; // Move j to the previous LPS value
            else
                i = i + 1; // Move i to the next position in the text
        }
    }
}

// Function to compute the Longest Prefix Suffix (LPS) array for the pattern
void computeLPSArray(char* pat, int M, int* lps) {
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // First element of LPS array is always 0
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len; // Set LPS value for current index
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1]; // Move len to the previous LPS value
            else
                lps[i++] = 0; // Set LPS value as 0
        }
    }
}

int main() {
    char txt[] = "ABABDABACDABABCABAB"; // Text to search within
    char pat[] = "ABABCABAB"; // Pattern to search for
    KMPSearch(pat, txt); // Perform KMP search
    return 0;
}
