#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::toupper;
using std::vector;

void c4_21() {
    vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8};
    for (auto &i : vi) {
        i = i % 2 ? 2 * i : i;
        cout << i << " ";
    }
    cout << endl;
}

void show_bit(unsigned long u) {
    unsigned len = (sizeof u) * 8;
    int s[len];
    for (int i = 0; i < len; ++i) {
        s[i] = u % 2;
        u /= 2;
    }
    
    for (int i = len - 1; i >= 0; --i) {
        if (i % 8 == 7)
            cout << " ";
        cout << s[i];
    }
    cout << endl;
}

void c4_26() {
    bool status;
    unsigned quizl = 0;
    quizl |= 1u << 27; // 第27位置1
    show_bit(quizl);

    quizl &= ~(1u << 27); // 第27位置0
    show_bit(quizl);
    status = quizl & (1u << 27); // 检测第27位
    cout << status << endl;
}

int main() {
    // c4_21();
    c4_26();

    return 0;
}