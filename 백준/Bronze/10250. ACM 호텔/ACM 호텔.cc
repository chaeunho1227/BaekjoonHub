#include <iostream>

class HotelManager {
private:
    int H; 
    int W; 

public:
    HotelManager(int h, int w) : H(h), W(w) {}

    int calculateRoomNumber(int N) {
        int floor = N % H;
        int room = N / H + 1;

        if (floor == 0) {
            floor = H;
            room -= 1;
        }

        return floor * 100 + room;
    }
};

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int H, W, N;
        std::cin >> H >> W >> N;

        HotelManager manager(H, W);
        int roomNumber = manager.calculateRoomNumber(N);

        std::cout << roomNumber << std::endl;
    }

    return 0;
}
