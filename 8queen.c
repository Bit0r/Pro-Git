#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool b[3][64] = {false};
int n, position[64];


void output() {
    int i, j, queen;
    for (i = 1; i <= n; i++) {
        queen = position[i];
        for (j = 1; j <= n; j++)
            if (j == queen)
                putchar('*');
            else
                putchar('-');
        putchar('\n');
    }
    putchar('\n');
}

void dfs(int step) {
    if (step > n) {
        output();
        return;
    }
    int i = step, j;
    for (j = 1; j <= n; j++) {
        if (b[1][j] == false && b[2][i - j + n] == false &&
            b[3][i + j] == false) {
            position[step] = j;
            b[1][j] = b[2][i - j + n] = b[3][i + j] = true;
            dfs(step + 1);
            b[1][j] = b[2][i - j + n] = b[3][i + j] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}