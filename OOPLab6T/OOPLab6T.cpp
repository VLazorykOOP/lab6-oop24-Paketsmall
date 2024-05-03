#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

//no virtual
class Base {
protected:
    int dat;
public:
    Base()
        :dat(1) {}
    Base(int d)
        :dat(d) {}
    static size_t getSize() { return sizeof(Base); }
    virtual ~Base() {}
};

class D1 : protected Base {
protected:
    int d1;
public:
    D1()
        :d1(1) {}
    D1(int d)
        :d1(d) {}
    D1(int d, int dt)
        :d1(dt), Base(d) {}
    static size_t getSize() { return sizeof(D1); }
};
class D2 : protected Base {
protected:
    int d2;
public:
    D2()
        :d2(1) {}
    D2(int d)
        :d2(d) {}
    D2(int d, int dt)
        :d2(dt), Base(d) {}
    static size_t getSize() { return sizeof(D2); }
};

class D3 : protected Base {
protected:
    int d3;
public:
    D3()
        :d3(1) {}
    D3(int d)
        :d3(d) {}
    D3(int d, int dt)
        :d3(dt), Base(d) {}
    static size_t getSize() { return sizeof(D3); }
};

class D12 : protected D1, D2 {
protected:
    int d12;
public:
    D12()
        :d12(1) {}
    D12(int d)
        :d12(d) {}
    D12(int d, int d1, int dt)
        :d12(dt), D1(d), D2(d1) {}
    static size_t getSize() { return sizeof(D12); }
};

class D12D : protected D12 {
protected:
    int d12d;
public:
    D12D()
        :d12d(1) {}
    D12D(int d)
        :d12d(d) {}
    D12D(int d, int dt)
        :d12d(dt), D12(d) {}
    static size_t getSize() { return sizeof(D12D); }
};

class R : protected D1, D12, D3 {
protected:
    int r;
public:
    R()
        :r(1) {}
    R(int d)
        :r(d) {}
    R(int d1, int d12, int d3, int dt)
        :r(dt), D1(d1), D12(d12), D3(d3) {}
    void showDat() {
        cout << "R: " << sizeof(R) << endl;
        cout << "Size of D1 (from R): " << D1::getSize() << endl;
        cout << "Size of D1 (from D12): " << D12::D1::getSize() << endl;
        cout << "Size of D12: " << D12::getSize() << endl;
        cout << "Size of D3: " << D3::getSize() << endl;
        cout << "Size of Base: " << Base::getSize() << endl;
    }
};


//virtual

class D1V : virtual protected Base {
protected:
    int d1;
public:
    D1V()
        :d1(1) {}
    D1V(int d)
        :d1(d) {}
    static size_t getSize() { return sizeof(Base); }
};

class D2V : virtual protected Base {
protected:
    int d2;
public:
    D2V()
        :d2(1) {}
    D2V(int d)
        :d2(d) {}
    D2V(int d, int dt)
        :d2(dt), Base(d) {}
    static size_t getSize() { return sizeof(D2); }
};

class D3V : virtual protected Base {
protected:
    int d3;
public:
    D3V()
        :d3(1) {}
    D3V(int d)
        :d3(d) {}
    D3V(int d, int dt)
        :d3(dt), Base(d) {}
    static size_t getSize() { return sizeof(D3); }
};

class D12V : virtual protected D1, D2 {
protected:
    int d12;
public:
    D12V()
        :d12(1) {}
    D12V(int d)
        :d12(d) {}
    D12V(int d, int d1, int dt)
        :d12(dt), D1(d), D2(d1) {}
    static size_t getSize() { return sizeof(D12); }
};

class D12DV : virtual protected D12 {
protected:
    int d12d;
public:
    D12DV()
        :d12d(1) {}
    D12DV(int d)
        :d12d(d) {}
    D12DV(int d, int dt)
        :d12d(dt), D12(d) {}
    static size_t getSize() { return sizeof(D12D); }
};

class RV : virtual protected D1, D12, D3 {
protected:
    int r;
public:
    RV()
        :r(1) {}
    RV(int d)
        :r(d) {}
    RV(int d1, int d12, int d3, int dt)
        :r(dt), D1(d1), D12(d12), D3(d3) {}
    void showDat() {
        cout << "R: " << sizeof(R) << endl;
        cout << "Size of D1 (from R): " << D1::getSize() << endl;
        cout << "Size of D1 (from D12): " << D12::D1::getSize() << endl;
        cout << "Size of D12: " << D12::getSize() << endl;
        cout << "Size of D3: " << D3::getSize() << endl;
        cout << "Size of Base: " << Base::getSize() << endl;
    }
};


int main() {
    R r;
    r.showDat();

    RV rv;
    rv.showDat();

    return 0;
}

 













#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

class Quadrangle {
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
};


class Square : public Quadrangle {
private:
    float side;
public:
    Square(float s)
        : side(s) {}
    float area() const override {
        return side * side;
    }
    float perimeter() const override {
        return 4 * side;
    }
};

class Rectangle : public Quadrangle {
private:
    float length;
    float width;
public:
    Rectangle(float l, float w)
        : length(l), width(w) {}

    float area() const override {
        return length * width;
    }
    float perimeter() const override {
        return 2 * (length + width);
    }
};


class Parallelogram : public Quadrangle {
private:
    float base;
    float height;
public:
    Parallelogram(float b, float h)
        : base(b), height(h) {}

    float area() const override {
        return base * height;
    }
    float perimeter() const override {
        return 2 * (base + height);
    }
};


class Trapezoid : public Quadrangle {
private:
    float base1;
    float base2;
    float height;
public:
    Trapezoid(float b1, float b2, float h)
        : base1(b1), base2(b2), height(h) {}

    float area() const override {
        return ((base1 + base2) / 2) * height;
    }
    float perimeter() const override {
        if (base1 == base2) {
            return 2 * base1 + 2 * sqrt(pow((base2 - base1) / 2, 2) + pow(height, 2));
        }
        else {
            cout << "Неможливо обчислити периметр. Основи трапеції різні." << endl;
            return -1;
        }
    }
};

int main() {
    Square sq(5);
    Rectangle rect(4, 6);
    Parallelogram par(5, 7);
    cout << "Площа квадрата: " << sq.area() << endl;
    cout << "Периметр квадрата: " << sq.perimeter() << endl;

    cout << "Площа прямокутника: " << rect.area() << endl;
    cout << "Периметр прямокутника: " << rect.perimeter() << endl;

    cout << "Площа паралелограма: " << par.area() << endl;
    cout << "Периметр паралелограма: " << par.perimeter() << endl;

    return 0;
}


















#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& newName, int newAge)
        : name(newName), age(newAge) {}
    virtual ~Person() {}

    virtual void display() const {
        cout << "Person: " << name << ", Age: " << age << endl;
    }
};

class Father : virtual public Person {
public:
    Father(const string& newName, int newAge)
        : Person(newName, newAge) {}
    virtual ~Father() {}

    virtual void display() const override {
        cout << "Father: " << name << ", Age: " << age << endl;
    }
};

class Mother : virtual public Person {
public:
    Mother(const string& newName, int newAge)
        : Person(newName, newAge) {}
    virtual ~Mother() {}

    virtual void display() const override {
        cout << "Mother: " << name << ", Age: " << age << endl;
    }
};

class Son : public Father, public Mother {
public:
    Son(const string& newName, int newAge)
        : Person(newName, newAge), Father(newName, newAge), Mother(newName, newAge) {}
    virtual ~Son() {}

    virtual void display() const override {
        cout << "Son: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Son Kolya("Kolya", 25);
    Kolya.display();

    return 0;
}

