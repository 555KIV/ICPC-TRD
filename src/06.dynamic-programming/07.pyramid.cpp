#include <iostream>
#include <vector>

int pyramid(int n) {
    int m = 0, result = 0;
    std::vector<std::vector<int>> mass(n + 1, std::vector<int>(n + 1, 0));
    mass[0][0] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (j > i) continue;
            for (int m = 0; m < j; m++) {
                mass[i][j] += mass[i - j][m];
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        result += mass[n][i];
    }

    return result;
}


