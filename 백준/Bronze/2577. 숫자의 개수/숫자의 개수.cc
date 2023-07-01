#include <iostream>
#include <string>

class NumberCounter {
//접근제어
private:
    int count[10];
    int A, B, C;

public:
    //생성자 + 이니셜라이징
    NumberCounter(int a, int b, int c) : A(a), B(b), C(c) {
        // 배열을 초기화합니다.
        for (int i = 0; i < 10; i++) {
            count[i] = 0;
        }
    }

    void countDigits() {
        int result = A * B * C;
        //나온 결과를 문자열로 저장
        std::string resultString = std::to_string(result);
        for (char c : resultString) {
            int digit = c - '0';
            count[digit]++;
        }
    }

    void printCount() {
        for (int i = 0; i < 10; i++) {
            std::cout << count[i] << std::endl;
        }
    }
};

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    NumberCounter counter(A, B, C);
    counter.countDigits();
    counter.printCount();

    return 0;
}
