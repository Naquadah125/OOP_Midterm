#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    ~Point() {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    friend istream& operator>> (istream& is, Point& ccjday){
        is >> ccjday.x >> ccjday.y;
        return is;
    }
};

class Line {
private:
    Point A;
    Point B;
public:
    Line() {}
    Line(Point A, Point B) : A(A), B(B) {}
    ~Line() {}
    Point getA() const { return A; }
    Point getB() const { return B; }
    void setA(Point A) { this->A = A; } 
    void setB(Point B) { this->B = B; }
    void setPoints(int x1, int y1, int x2, int y2){
        Point A(x1, y1);
        Point B(x2, y2);
        this->A = A;
        this->B = B;
    }
    double tinhDoDai() {
        return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
    }
    void print() {
        cout << "Point A: " << "(" << A.getX() << "," << A.getY() << ")" << endl;
        cout << "Point B: " << "(" << B.getX() << "," << B.getY() << ")" << endl;
        cout << "Length: " << tinhDoDai() << endl;
    }
    void xuatPhuongTrinh() {
        // A=yB-yA;
        // B=xA-xB;
        // C=xB*yA - xA*yB;
        // Ax + By + C = 0
        double A = this->B.getY() - this->A.getY();
        double B = this->A.getX() - this->B.getX();
        double C = this->B.getX() * this->A.getX() - this->A.getX() * this->B.getY();
        cout << "Phuong trinh duong thang: " << A << "x + " << B << "y + " << C << " = 0" << endl;
    }
};

int main() {
    // Test case 1: Đường thẳng thông thường qua (0,0) và (2,3)
    Line line1;
    line1.setPoints(0, 0, 2, 3);
    cout << "Test case 1:" << endl;
    line1.print();
    line1.xuatPhuongTrinh();
    cout << endl;

    // Test case 2: Đường thẳng đứng qua (1,1) và (1,5)
    Line line2;
    line2.setPoints(1, 1, 1, 5);
    cout << "Test case 2 (Duong thang dung):" << endl;
    line2.print();
    line2.xuatPhuongTrinh();
    cout << endl;

    // Test case 3: Đường thẳng ngang qua (2,3) và (5,3)
    Line line3;
    line3.setPoints(2, 3, 5, 3);
    cout << "Test case 3 (Duong ngang):" << endl;
    line3.print();
    line3.xuatPhuongTrinh();
    cout << endl;

    // Test case 4: Hai điểm trùng nhau (0,0) và (0,0)
    Line line4;
    line4.setPoints(0, 0, 0, 0);
    cout << "Test case 4 (Loi):" << endl;
    line4.print();
    line4.xuatPhuongTrinh();

    return 0;
}