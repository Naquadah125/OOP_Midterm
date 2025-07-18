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
        numSum.b = this->b + num2.b;
        return numSum;
    }
    Math operator-(Math num2){
        Math numSum;
        numSum.a = this->a - num2.a;
        numSum.b = this->b - num2.b;
        return numSum;
    }
    Math operator*(Math num2){
        Math numSum;
        numSum.a = this->a * num2.a;
        numSum.b = this->b * num2.b;
        return numSum;
    }
    void signChange(){
        a = -a;
        b = -b;
    }
};

int main() {
    // Test case 1: Kiểm tra constructor và toán tử xuất
    cout << "Test case 1: Constructor và toán tử xuất" << endl;
    Math m1(3, 2); // 3 + 2*sqrt(7)
    cout << "m1 = " << m1 << endl; // Mong đợi: 3 + 2*sqrt(7)

    Math m2(0, 5); // 5*sqrt(7)
    cout << "m2 = " << m2 << endl; // Mong đợi: 5sqrt(7)

    Math m3(4, 0); // 4
    cout << "m3 = " << m3 << endl; // Mong đợi: 4

    Math m4(2, -3); // 2 - 3*sqrt(7)
    cout << "m4 = " << m4 << endl; // Mong đợi: 2 - 3*sqrt(7)

    // Test case 2: Kiểm tra toán tử nhập
    cout << "\nTest case 2: Toán tử nhập" << endl;
    Math m5;
    cout << "Nhập a và b cho m5 (ví dụ: 1 2): ";
    cin >> m5;
    cout << "m5 = " << m5 << endl; // Mong đợi: Phụ thuộc vào đầu vào

    // Test case 3: Kiểm tra toán tử cộng
    cout << "\nTest case 3: Toán tử cộng" << endl;
    Math m6(1, 2);
    Math m7(3, 4);
    Math sum = m6 + m7;
    cout << "m6 + m7 = " << sum << endl; // Mong đợi: 4 + 6*sqrt(7), nhưng code hiện tại cho kết quả sai do nhân sqrt(7)

    // Test case 4: Kiểm tra toán tử trừ
    cout << "\nTest case 4: Toán tử trừ" << endl;
    Math diff = m6 - m7;
    cout << "m6 - m7 = " << diff << endl; // Mong đợi: -2 - 2*sqrt(7), nhưng code hiện tại cho kết quả sai do nhân sqrt(7)

    // Test case 5: Kiểm tra toán tử nhân
    cout << "\nTest case 5: Toán tử nhân" << endl;
    Math prod = m6 * m7;
    cout << "m6 * m7 = " << prod << endl; // Mong đợi: (1*3 + 2*4*7) + (1*4 + 2*3)*sqrt(7) = 59 + 10*sqrt(7), nhưng code hiện tại cho kết quả sai

    // Test case 6: Kiểm tra hàm signChange
    cout << "\nTest case 6: Hàm signChange" << endl;
    Math m8(5, 3);
    cout << "m8 trước khi đổi dấu: " << m8 << endl; // Mong đợi: 5 + 3*sqrt(7)
    m8.signChange();
    cout << "m8 sau khi đổi dấu: " << m8 << endl; // Mong đợi: -5 - 3*sqrt(7)

    return 0;
}