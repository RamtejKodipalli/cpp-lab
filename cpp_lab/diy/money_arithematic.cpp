#include <iostream>
#include <cmath>
#include <stdexcept>

class Money {
private:
    long long rupees;
    int paise;

    // Helper to normalize paise and rupees (keep paise between 0 and 99)
    void normalize() {
        if (paise >= 100) {
            rupees += paise / 100;
            paise %= 100;
        } else if (paise < 0) {
            // Borrow from rupees
            int borrow = (abs(paise) + 99) / 100;
            rupees -= borrow;
            paise += borrow * 100;
        }
        
        // Handle negative total money bounds safely if needed
        if (rupees < 0) {
            // Optional: Handle negative balances based on system design
        }
    }

public:
    // Constructor
    Money(long long r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    // Overload + operator
    Money operator+(const Money& other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    // Overload - operator
    Money operator-(const Money& other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    // Display method
    void display() const {
        std::cout << "Rs. " << rupees << "." << (paise < 10 ? "0" : "") << paise << std::endl;
    }
};

int main() {
    Money m1(50, 75);
    Money m2(20, 50);

    std::cout << "Amount 1: "; m1.display();
    std::cout << "Amount 2: "; m2.display();

    Money sum = m1 + m2;
    std::cout << "Sum (+ with carry): "; sum.display();

    Money diff = m1 - m2;
    std::cout << "Difference (- with borrow): "; diff.display();

    return 0;
}