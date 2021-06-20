#include "polynomial.h"
#include <iostream>
#include <map>
using namespace std;
Polynomial::Polynomial(int A[], int size) {
    for (int i = 0; i < size; i++) {
        coefficients.insert_back(A[i]);
    }
    size_ = size;
}
Polynomial* Polynomial::add(Polynomial* rhs) {
    int new_size = 0;
    if (size_ !=  rhs->size_) {
        int smaller_size = 0;
        DoublyLinkedList* pointer = NULL;
        if (size_ > rhs->size_) {
            new_size = size_;
            smaller_size = rhs->size_;
            pointer = &coefficients;
        }
        else {
            new_size = rhs->size_;
            smaller_size = size_;
            pointer = &(rhs->coefficients);
        }
        int new_coefficients[new_size];
        for (int i = 0; i < smaller_size; i++) {
            new_coefficients[i] = coefficients.select(i) + rhs->coefficients.select(i);
        }
        for (int j = smaller_size; j < new_size; j++) {
            new_coefficients[j] = pointer->select(j);
        }
        Polynomial * new_poly = new Polynomial(new_coefficients,new_size);
        return new_poly;
    }
    else {
        new_size = size_;
        int new_coefficients[new_size];
        for (int i = 0; i < size_; i++) {
            new_coefficients[i] = coefficients.select(i) + rhs->coefficients.select(i);
        }
        Polynomial* new_poly = new Polynomial(new_coefficients,new_size);
        return new_poly;
    }
}
Polynomial* Polynomial::sub(Polynomial* rhs) {
    int new_size = 0;
    if (size_ !=  rhs->size_) {
        int smaller_size = 0;
        DoublyLinkedList* pointer = NULL;
        if (size_ > rhs->size_) {
            new_size = size_;
            smaller_size = rhs->size_;
            pointer = &coefficients;
        }
        else {
            new_size = rhs->size_;
            smaller_size = size_;
            pointer = &(rhs->coefficients);
        }
        int new_coefficients[new_size];
        for (int i = 0; i < smaller_size; i++) {
            new_coefficients[i] = coefficients.select(i) - rhs->coefficients.select(i);
        }
        for (int j = smaller_size; j < new_size; j++) {
            if (new_size = rhs->size_) { //reverse sign
                new_coefficients[j] = -pointer->select(j);
            }
            else { //no need to reverse sign because *this is longer than *rhs
                new_coefficients[j] = pointer->select(j);
            }
        }
        Polynomial * new_poly = new Polynomial(new_coefficients,new_size);
        return new_poly;
    }
    else {
        new_size = size_;
        int new_coefficients[new_size];
        for (int i = 0; i < size_; i++) {
            new_coefficients[i] = coefficients.select(i) - rhs->coefficients.select(i);
        }
        Polynomial* new_poly = new Polynomial(new_coefficients,new_size);
        return new_poly;
    }
}
Polynomial* Polynomial::mul(Polynomial* rhs) {
    int new_size = (size_ - 1) + (rhs->size_ - 1) + 1;
    int new_coefficients[new_size];
    cout << endl;
    for (int i = 0; i < new_size; i++) {
        new_coefficients[i] = 0;
    }
    for (int i = size_ - 1; i >= 0; i--) {
        for (int j = rhs->size_ - 1; j >= 0; j--) {
            if (coefficients.select(i) == 0 || rhs->coefficients.select(j) == 0) {

                continue;
            }
            if (new_coefficients[i + j] != 0) {
                new_coefficients[i + j] += coefficients.select(i) * rhs->coefficients.select(j);
            } else {
                new_coefficients[i + j] = coefficients.select(i) * rhs->coefficients.select(j);
            }
        }
    }
    Polynomial *new_poly = new Polynomial(new_coefficients, new_size);
    return new_poly;

}
void Polynomial::print() {
    cout << "The Polynomial is: " << endl;
    for (int i = size_-1; i >= 0; i--) {
        bool plus = true;
        for (int j = i-1; j >= 0; j--) {
            if (coefficients.select(j) != 0) {
                plus = false;
            }
        }
        if (coefficients.select(i) > 0) {
            if (i == 0) {
                cout << coefficients.select(i) << "x^" << i;
            }
            else if (plus == true) {
                cout << coefficients.select(i) << "x^" << i;
            }
            else {
                cout << coefficients.select(i) << "x^" << i << " + ";
            }
        }
        else if (coefficients.select(i) < 0 ) {
            if (i == 0) {
                cout << "(" << coefficients.select(i) << ")x^" << i;
            }
            else if (plus == true) {
                cout << "(" << coefficients.select(i) << ")x^" << i;
            }
            else {
                cout << "(" << coefficients.select(i) << ")x^" << i << " + ";
            }
        }
        else {
            continue;
        }
    }
    cout << endl;
}