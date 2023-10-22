#include <iostream>

int main() {
    int matrix[5][5];
    for (int i(0); i < 5; i++) {
        int f(0), s(0), th(0), fo(0), fi(0);
        std::cin >> f >> s >> th >> fo >> fi;
        matrix[i][0] = f;
        matrix[i][1] = s;
        matrix[i][2] = th;
        matrix[i][3] = fo;
        matrix[i][4] = fi;
    }
    for (int i(0); i < 5; i++) {
        for (int j(0); j < 5; j++) {
            if (matrix[i][j] == 1) {
                std::cout << abs(i - 2) + abs(j - 2);
                break;
            }
        }
    }
}