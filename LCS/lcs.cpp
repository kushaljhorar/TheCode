#include<iostream>
using namespace std;

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

/**LCS - longest common subsequence
 * Complexity - O(mn)
 */
void findLCS(char *x, char *y, int m, int n) {
    int l[m + 1][n + 1];

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                l[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                l[i][j] = 1 + l[i - 1][j - 1];
            } else {
                l[i][j] = max(l[i - 1][j] , l[i][j - 1]);
            }
        }
    }

    int index = l[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;

    while(i > 0 && j > 0) {
        if(x[i - 1] == y[j - 1]) {
            lcs[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        } else if(l[i - 1][j] > l[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout<<"Length of LCS: "<<l[m][n]<<endl;
    cout<<"LCS of "<<x<<" & "<<y<<": "<<lcs<<endl;
}

int main() {
    char x[] = "ABCDGH";
    char y[] = "AEDFHR";
    int m = strlen(x);
    int n = strlen(y);
    findLCS(x, y, m, n);
    return 0;
}
