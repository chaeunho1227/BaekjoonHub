#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cout << i << '\n';
    }

    return 0;
}