#include <iostream>
#include "Sales_item.h"

void c1_4() {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
            << " is " << v1 * v2 << std::endl;

    int sum = 0, i = 50;
    while (i <= 100) {
        sum += i;
        ++i;
    }
    std::cout << "50 - 100 sum: " << sum << std::endl;

    while (i >= 90) {
        std::cout << i << " ";
        --i;
    }

    sum = 0;
    while (std::cin >> i) {
        //std::cout << i << " ";
        sum += i;
    }
    std::cout << " sum: " << sum << std::endl;
}

int c1_6() {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    // c1_4();
    c1_6();

    return 0;
}