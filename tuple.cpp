#include <string>
#include <array>

#include "common.h"

template <typename T> class Tuple {
    private:
        T x, y, z;
    public:
        Tuple(T nX, T nY, T nZ);
        T get(int16 element_num);
        std::array<T, 3> content();
        bool equals(Tuple<T>* t1, Tuple<T>* t2);
        void replace(int16 element_num, T value);
        void display();
        void sort();
};

template <typename T> Tuple<T>::Tuple(T nX, T nY, T nZ) {
    this -> x = nX;
    this -> y = nY;
    this -> z = nZ;
}

template <typename T> T Tuple<T>::get(int16 element_num) {
    if(element_num == 0) 
        return this -> x;
    if(element_num == 1) 
        return this -> y;
    if(element_num == 2) 
        return this -> z;
    else 
        return 0;
}

template <typename T> std::array<T, 3> Tuple<T>::content() {
    std::array<T, 3> f {this -> x, this -> y, this -> z};
    return f;
}

template <typename T> bool Tuple<T>::equals(Tuple<T>* t1, Tuple<T>* t2) {
    if(t1 -> x == t2 -> x && t1 -> y == t2 -> y && t1 -> z == t2 -> z) 
        return true;
    else
        return false;
}

template <typename T> void Tuple<T>::replace(int16 element_num, T value) {
    if(element_num == 0) 
        this -> x = value;
    if(element_num == 1) 
        this -> y = value;
    if(element_num == 2) 
        this -> z = value;
    else 
        print("invalid index");
}

template <typename T> void Tuple<T>::display() {
    std::cout << this -> x << ", " << this -> y << ", " << this -> z << std::endl;
}

template <typename T> void Tuple<T>::sort() {
    T temp;
    if(this -> x > this -> y) {
        temp = this -> x;
        this -> x = this -> y;
        this -> y = temp;
    }

    if(this -> y > this -> z) {
        temp = this -> y;
        this -> y = this -> z;
        this -> z = temp;
    }

    if(this -> x > this -> y) {
        temp = this -> x;
        this -> x = this -> y;
        this -> y = temp;
    }
}

int main() {
    Tuple<int16> *a1 = new Tuple<int16>(1231, 2213, 420);
    Tuple<int16> *a2 = new Tuple<int16>(1231, 2213, 420);
    std::cout << a1 -> equals(a1, a2) << std::endl;
    std::array<int16, 3> arr = a1 -> content();
    for(int i = 0; i < 3; i++) {
        std::cout << arr[i] << std::endl;
    }
}
