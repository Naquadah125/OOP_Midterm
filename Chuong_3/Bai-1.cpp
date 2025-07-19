#include <iostream>
#include <cmath>
using namespace std;

class TamGiac {
private:
    double AB;
    double AC;
    double BC;
public:
    TamGiac() {}
    TamGiac(double AB, double AC, double BC)
        : AB(AB), AC(AC), BC(BC) {}
    ~TamGiac() {}

    void setAB(double AB) { this->AB = AB; }
    void setAC(double AC) { this->AC = AC; }
    void setBC(double BC) { this->BC = BC; }
    double getAB() const { return AB; }
    double getAC() const { return AC; }
    double getBC() const { return BC; }

    virtual double perimeter() = 0;
    virtual double area() = 0;
};

class TamGiacDeu : public TamGiac {
public:
    TamGiacDeu() {}
    TamGiacDeu(double AB)
        : TamGiac(AB, AB, AB) {}
    ~TamGiacDeu() {}

    double perimeter() override {
        return 3 * getAB();
    }
    double area() override {
        return (sqrt(3)/4) * getAB() * getAB();
    }
};

int main() {
    TamGiacDeu tg(5);
    cout << "Chu vi: " << tg.perimeter() << endl; 
    cout << "Dien tich: " << tg.area() << endl; 
    return 0;
}