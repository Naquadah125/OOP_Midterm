#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Point2D {
private:
    int x;
    int y;
public:
    Point2D() {}
    Point2D(int x, int y) : x(x), y(y) {}
    ~Point2D() {}

    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    friend istream& operator>> (istream& input, Point2D& ccjday) {
        cout << "\nNhap toa do x: ";
        input >> ccjday.x;
        cout << "Nhap toa do y: ";
        input >> ccjday.y;
        return input;
    }
    friend ostream& operator<< (ostream& output, const Point2D& ccjday) {
        output << ccjday.x << " " << ccjday.y;
        return output;
    }
};

class Triangle {
private:
    Point2D A;
    Point2D B;
    Point2D C;
public:
    Triangle() {}
    Triangle(Point2D A, Point2D B, Point2D C) : A(A), B(B), C(C) {}
    ~Triangle() {}

    Point2D getA() const { return A; }
    Point2D getB() const { return B; }
    Point2D getC() const { return C; }
    void setA(Point2D A) { this->A = A; }
    void setB(Point2D B) { this->B = B; }
    void setC(Point2D C) { this->C = C; }

    void set(int x1, int y1, int x2, int y2, int x3, int y3) {
        Point2D A(x1, y1);   this->A = A;
        Point2D B(x2, y2);   this->B = B;
        Point2D C(x3, y3);   this->C = C;
    }
    double tinhChuVi() {
        double AB = sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2));
        double BC = sqrt(pow(B.getX() - C.getX(), 2) + pow(B.getY() - C.getY(), 2));
        double CA = sqrt(pow(C.getX() - A.getX(), 2) + pow(C.getY() - A.getY(), 2));
        return AB + BC + CA;
    }
    double tinhDienTich() {
        double AB = sqrt(pow(A.getX() - B.getX(), 2) + pow(A.getY() - B.getY(), 2));
        double BC = sqrt(pow(B.getX() - C.getX(), 2) + pow(B.getY() - C.getY(), 2));
        double CA = sqrt(pow(C.getX() - A.getX(), 2) + pow(C.getY() - A.getY(), 2));
        double p = (AB + BC + CA) / 2;
        return sqrt(p * (p - AB) * (p - BC) * (p - CA));
    }
    void print() {
        cout << "A: " << A << endl;
        cout << "B: " << B << endl;
        cout << "C: " << C << endl;
        cout << "Chu vi: " << tinhChuVi() << endl;
        cout << "Dien tich: " << tinhDienTich() << endl;
    }
};

int main() {
    // Test case 1: Input động từ người dùng (sử dụng operator>>)
    Triangle triangle1;
    Point2D A1, B1, C1;
    cout << "Test case 1: Nhap tam giac tu ban phim" << endl;
    cout << "Nhap toa do dinh A: ";
    cin >> A1;
    cout << "Nhap toa do dinh B: ";
    cin >> B1;
    cout << "Nhap toa do dinh C: ";
    cin >> C1;
    triangle1.setA(A1);
    triangle1.setB(B1);
    triangle1.setC(C1);
    triangle1.print();
    cout << endl;

    // Test case 2: Tam giac thuong (cứng, diem (0,0), (3,0), (0,4) - vuong 3-4-5)
    Triangle triangle2;
    triangle2.set(0, 0, 3, 0, 0, 4);
    cout << "Test case 2: Tam giac thuong (vuong)" << endl;
    triangle2.print();
    cout << endl;

    // Test case 3: Tam giac deu gan dung (cứng, diem (0,0), (2,0), (1,1) - gan deu nếu y=sqrt(3)~1.732, nhung dung int nen gan)
    Triangle triangle3;
    triangle3.set(0, 0, 2, 0, 1, 1);
    cout << "Test case 3: Tam giac deu gan dung" << endl;
    triangle3.print();
    cout << endl;

    // Test case 4: Cac diem thang hang (cứng, diem (0,0), (1,1), (2,2) - dien tich=0)
    Triangle triangle4;
    triangle4.set(0, 0, 1, 1, 2, 2);
    cout << "Test case 4: Khong phai tam giac (thang hang)" << endl;
    triangle4.print();

    return 0;
}