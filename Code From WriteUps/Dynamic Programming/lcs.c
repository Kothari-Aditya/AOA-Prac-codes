#include <stdio.h>
#include <string.h>

void compute_LCS(char A[], char B[], int m, int n, int c[100][100], char d[100][100]) {
    int i, j;

    // Initialize first row and column of c and d
    for (i = 0; i <= m; i++) {
        c[i][0] = 0;
        strcpy(d[i], "");
    }
    for (j = 0; j <= n; j++) {
        c[0][j] = 0;
        strcpy(d[0] + j, "");
    }

    // Fill the DP tables
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                d[i][j] = '\\';  // '\\' represents the diagonal direction '↖'
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                d[i][j] = '|';  // '|' represents the upward direction '↑'
            } else {
                c[i][j] = c[i][j - 1];
                d[i][j] = '-';  // '-' represents the leftward direction '←'
            }
        }
    }
}

void print_LCS(char A[], int m, int n, char d[100][100]) {
    int i = m, j = n;
    char LCS[100];
    int k = 0;

    while (i > 0 && j > 0) {
        if (d[i][j] == '\\') {
            LCS[k++] = A[i - 1];
            i--;
            j--;
        } else if (d[i][j] == '|') {
            i--;
        } else {
            j--;
        }
    }
    LCS[k] = '\0';

    // Reverse the LCS string
    for (int l = 0; l < k / 2; l++) {
        char temp = LCS[l];
        LCS[l] = LCS[k - l - 1];
        LCS[k - l - 1] = temp;
    }

    printf("LCS: %s\n", LCS);

    int len = strlen(LCS);

    printf("LCS length is %d\n",len);
}

int main() {
    char A[] = "AGGTAB";
    char B[] = "GXTXAYB";
    int m = strlen(A);
    int n = strlen(B);
    int c[100][100];
    char d[100][100];

    compute_LCS(A, B, m, n, c, d);

    // Print the c table
    printf("c table:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print the d table
    printf("d table:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%c ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    print_LCS(A, m, n, d);

    return 0;
}