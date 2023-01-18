#include <iostream>
#include <algorithm>
using namespace std;

const int n = 8; // length of S1 and S2
const int match = 2;
const int mismatch_scr = -1;
const int penalty = -2;

string S1, S2; // input strings
int dp[n+1][n+1]; // alignment matrix
string align1, align2; // aligned sequences

void printAlignment() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"The tracepath of sequences:"<<endl;
    cout << align1 << endl;
    cout << align2 << endl;
}


void globalAlignment() {
    for (int i = 0; i <= n; i++) {
        dp[i][0] = penalty * i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = penalty * j;
    }

    // fill rest of the matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int diagonal = dp[i-1][j-1] + (S1[i-1] == S2[j-1] ? match : mismatch_scr);
            int left = dp[i][j-1] + penalty;
            int up = dp[i-1][j] + penalty;
            dp[i][j] = max(max(left, up), diagonal);
        }
    }

    // traceback
    int i = n, j = n;
    while (i > 0 || j > 0) {
        // vertical
        if (i > 0 && dp[i][j] == dp[i-1][j] + penalty) {
            align1 = S1[i-1] + align1;
            align2 = "-" + align2;
            i--;
        }
        // horizontal
        else if (j > 0 && dp[i][j] == dp[i][j-1] + penalty) {
            align1 = "-" + align1;
            align2 = S2[j-1] + align2;
            j--;
        }
        //diagonal  
        else {
            align1 = S1[i-1] + align1;
            align2 = S2[j-1] + align2;
            i--;
            j--;
        }
    }
}

int main() 
{
    cin >> S1 >> S2;
    globalAlignment();
    cout<<"The alignment matrix:"<<endl;
    printAlignment();
    return 0;
}
