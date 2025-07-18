#include <iostream>
using namespace std;

class Math{
private:
    int a;
    int b;
public:
    Math() {}
    Math(int a, int b)
        : a(a), b(b) {}
    ~Math() {}

    friend istream& operator>>(istream& input, Math& m){
        input >> m.a >> m.b;
        return input;
    }
    friend ostream& operator<<(ostream& output, const Math& m){
        if (m.a == 0){
            output << m.b << "sqrt(7)" << endl;
            return output;
        }
        if (m.b == 0){
            output << m.a << endl;
            return output;
        }
        if (m.b > 0){
            output << m.a << " + " << m.b << "*sqrt(7)";
            return output;
        }
        else if(m.b < 0){
            output << m.a << " - " << m.b << "*sqrt(7)";
            return output;
        }
    }
    Math operator+(Math num2){
        Math numSum;
        numSum.a = this->a + num2.a;
        numSum.b = (this->b + num2.b) * sqrt(7);
        return numSum;
    }
    Math operator-(Math num2){
        Math numSum;
        numSum.a = this->a - num2.a;
        numSum.b = (this->b - num2.b) * sqrt(7);
        return numSum;
    }
    Math operator*(Math num2){
        Math numSum;
        numSum.a = this->a * num2.a;
        numSum.b = (this->b * num2.b) * sqrt(7);
        return numSum;
    }
    void signChange(){
        a = -a;
        b = -b;
    }

};