//
// Created by Ke Jin on 2/4/18.
//

#ifndef PLAYGROUND_FRACTION_H
#define PLAYGROUND_FRACTION_H

#include <utility>
#include <stdexcept>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    // a and b should be non negative.
    if(a < b) return gcd(b, a);
    while(b){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}


class Fraction {
public:
    int numerator = 0;
    int denominator = 1;
    int sign = 1;
    Fraction(int n, int d, int s): numerator(n), denominator(d), sign(s){};

    Fraction(int k){
        denominator = 1;
        sign = k >= 0 ? 1 : -1;
        numerator = sign * k;
    }

    Fraction() = default;

    Fraction inv() const {
        if(numerator == 0){
            throw runtime_error("The inverse of 0 does not exist!");
        }
        return Fraction(denominator, numerator, sign);
    }

    Fraction negate() const {
        return Fraction(numerator, denominator, -sign);
    }

};

void print(const Fraction& a){
    if(a.denominator == 1){
        cout << (a.sign == 1 ? '+' : '-') << a.numerator;
    }
    else{
        cout << (a.sign == 1 ? '+' : '-') << a.numerator << '/' << a.denominator;
    }
}

bool operator==(const Fraction& a, const Fraction& b){
    return a.numerator == b.numerator && a.denominator == b.denominator;
}

Fraction operator+(const Fraction& a, const Fraction& b){
    int n = a.sign * a.numerator * b.denominator + b.sign * b.numerator * a.denominator;
    int d = a.denominator * b.denominator;
    int s = n >= 0 ? 1 : -1;
    if(s == -1) n = -n;
    int k = gcd(n, d);
    n /= k;
    d /= k;
    return Fraction(n, d, s);
}

Fraction operator-(const Fraction& a, const Fraction& b){
    return a + b.negate();
}

Fraction operator*(const Fraction& a, const Fraction& b){
    int n = a.numerator * b.numerator;
    int d = a.denominator * b.denominator;
    int s = a.sign * b.sign;
    int k = gcd(n, d);
    n /= k;
    d /= k;
    return Fraction(n, d, s);
}

Fraction operator/(const Fraction& a, const Fraction& b){
    if(b.numerator == 0){
        throw runtime_error("Divisor can not be 0!");
    }
    return a * b.inv();
}




#endif //PLAYGROUND_FRACTION_H
