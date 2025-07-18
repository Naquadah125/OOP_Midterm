#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

class DaThuc {
private:
    int n; // Số nguyên biểu diễn lũy thừa cao nhất của x
    vector<double> data;
public:
    DaThuc() {}
    DaThuc(int n, vector<double> data) : n(n), data(data) {}
    ~DaThuc() {}

    void setN(int n) { this->n = n; }
    void setData(vector<double>& data) { this->data = data; }
    int getN() const { return n; }
    vector<double> getData() const { return data; }

    void input(){
        cout << "Nhap bac cua da thuc: ";
        cin >> n;
        data.resize(n + 1);
        for (int i = n; i >= 0; i--) {
            cout << "Nhap he so cho x^" << i << ": ";
            cin >> data[i];
        }
    }
    void print(){
        cout << "Da thuc bac " << n << ": ";
        for (int i = n; i >= 0; i--) {
            if (i == n) {
                cout << data[i] << "x^" << i;
            } 
            else if (data[i] >= 0) {
                cout << " + " << data[i] << "x^" << i;
            } 
            else {
                cout << " - " << -data[i] << "x^" << i;
            }
        }
    }
    friend istream& operator>> (istream& input, DaThuc& dt) {
        cout << "Nhap bac cua da thuc: ";
        input >> dt.n;
        dt.data.resize(dt.n + 1);
        for (int i = dt.n; i >= 0; i--) {
            cout << "Nhap he so cho x^" << i << ": ";
            input >> dt.data[i];
        }
        return input;
    }
    friend ostream& operator<< (ostream& output, const DaThuc& dt) {
        output << "Da thuc bac " << dt.n << ": ";
        for (int i = dt.n; i >= 0; i--) {
            if (i == dt.n) {
                cout << dt.data[i] << "x^" << i;
            } 
            else if (dt.data[i] >= 0) {
                cout << " + " << dt.data[i] << "x^" << i;
            } 
            else {
                cout << " - " << -dt.data[i] << "x^" << i;
            }
        }
        return output;
    }
    double sumDaThucX(double x){
        double sum = 0;
        for (int i = 0; i <= n; i++){ // Tính giá trị của đa thức tại x
            sum += data[i] * pow(x, i);
        }
        return sum;
    }
    double derivativeDaThucX(double x) {
        double sum = 0;
        for (int i = 1; i <= n; i++) { // Bắt đầu từ 1 vì đạo hàm của hằng số là 0
            sum += i * data[i] * pow(x, i - 1);
        }
        return sum;
    }
    double integralDaThucX(double x) {
        double sum = 0;
        for (int i = 0; i <= n; i++) { // Tính tích phân từ 0 đến x
            sum += data[i] * pow(x, i + 1) / (i + 1);
        }
        return sum;
    }
    friend DaThuc operator+(DaThuc& dt1, DaThuc& dt2) {
        int maxN = max(dt1.n, dt2.n);
        vector<double> resultData(maxN + 1, 0);
        for (int i = 0; i <= maxN; i++) {
            if (i <= dt1.n) 
                resultData[i] += dt1.data[i];
            if (i <= dt2.n) 
                resultData[i] += dt2.data[i];
        }
        return DaThuc(maxN, resultData);
    }
    friend DaThuc operator-(DaThuc& dt1, DaThuc& dt2){
        int maxN = max(dt1.n, dt2.n);
        vector<double> resultData(maxN + 1, 0);
        for (int i = 0; i <= maxN; i++) { 
            if (i <= dt1.n) 
                resultData[i] += dt1.data[i];
            if (i <= dt2.n) 
                resultData[i] -= dt2.data[i];
        }
        return DaThuc(maxN, resultData);
    }
    friend DaThuc operator--(DaThuc& dt, int) {
        for (int i = 0; i <= dt.getN(); i++) {
            dt.data[i] -= 1.0;
        }
        return dt;
    }
    friend DaThuc operator++(DaThuc& dt, int) {
        for (int i = 0; i <= dt.getN(); i++) {
            dt.data[i] += 1.0;
        }
        return dt;
    }
};

int main() {
    // Test 1: Kiểm tra nhập/xuất đa thức
    cout << "Test 1: Nhap va xuat da thuc\n";
    DaThuc dt1;
    dt1.setN(2);
    vector<double> data1 = {1, 2, 3}; // Đa thức: 3x^2 + 2x + 1
    dt1.setData(data1);
    
    cout << "Da thuc dt1: ";
    dt1.print();
    cout << endl;

    // Test 2: Kiểm tra toán tử nhập
    cout << "\nTest 2: Toan tu nhap >>\n";
    DaThuc dt2;
    cout << "Nhap da thuc dt2:\n";
    cin >> dt2;
    cout << "Da thuc dt2 vua nhap: " << dt2 << endl;

    // Test 3: Kiểm tra tính giá trị đa thức tại x
    cout << "\nTest 3: Tinh gia tri da thuc tai x = 2\n";
    double result = dt1.sumDaThucX(2); // Đa thức 3x^2 + 2x + 1 tại x = 2
    assert(abs(result - 17) < 1e-9); // 3*4 + 2*2 + 1 = 17
    cout << "Gia tri dt1 tai x = 2: " << result << " (Du kien: 17)\n";

    // Test 4: Kiểm tra đạo hàm
    cout << "\nTest 4: Tinh dao ham tai x = 2\n";
    double derivative = dt1.derivativeDaThucX(2); // Đạo hàm: 6x + 2, tại x = 2
    assert(abs(derivative - 14) < 1e-9); // 6*2 + 2 = 14
    cout << "Dao ham dt1 tai x = 2: " << derivative << " (Du kien: 14)\n";

    // Test 5: Kiểm tra tích phân
    cout << "\nTest 5: Tinh tich phan tu 0 den x = 2\n";
    double integral = dt1.integralDaThucX(2); // Tích phân: x^3 + x^2 + x, tại x = 2
    assert(abs(integral - (8 + 4 + 2)) < 1e-9); // 8 + 4 + 2 = 14
    cout << "Tich phan dt1 tu 0 den x = 2: " << integral << " (Du kien: 14)\n";

    // Test 6: Kiểm tra toán tử cộng
    cout << "\nTest 6: Cong hai da thuc\n";
    DaThuc dt3(2, {1, 2, 3}); // 3x^2 + 2x + 1
    DaThuc dt4(2, {2, 1, 1}); // x^2 + x + 2
    DaThuc sum = dt3 + dt4; // Kết quả: 4x^2 + 3x + 3
    vector<double> expectedSum = {3, 3, 4};
    for (int i = 0; i <= sum.getN(); i++) {
        assert(abs(sum.getData()[i] - expectedSum[i]) < 1e-9);
    }
    cout << "Tong dt3 + dt4: ";
    sum.print();
    cout << endl;

    // Test 7: Kiểm tra toán tử trừ
    cout << "\nTest 7: Tru hai da thuc\n";
    DaThuc diff = dt3 - dt4; // Kết quả: 2x^2 + x - 1
    vector<double> expectedDiff = {-1, 1, 2};
    for (int i = 0; i <= diff.getN(); i++) {
        assert(abs(diff.getData()[i] - expectedDiff[i]) < 1e-9);
    }
    cout << "Hieu dt3 - dt4: ";
    diff.print();
    cout << endl;

    // Test 8: Kiểm tra toán tử ++
    cout << "\nTest 8: Toan tu ++ (tang he so)\n";
    DaThuc dt5(2, {1, 2, 3});
    dt5++; // Tăng mỗi hệ số lên 1: 4x^2 + 3x + 2
    vector<double> expectedInc = {2, 3, 4};
    for (int i = 0; i <= dt5.getN(); i++) {
        assert(abs(dt5.getData()[i] - expectedInc[i]) < 1e-9);
    }
    cout << "Da thuc dt5 sau khi ++: ";
    dt5.print();
    cout << endl;

    // Test 9: Kiểm tra toán tử --
    cout << "\nTest 9: Toan tu -- (giam he so)\n";
    DaThuc dt6(2, {1, 2, 3});
    dt6--; // Giảm mỗi hệ số đi 1: 2x^2 + x + 0
    vector<double> expectedDec = {0, 1, 2};
    for (int i = 0; i <= dt6.getN(); i++) {
        assert(abs(dt6.getData()[i] - expectedDec[i]) < 1e-9);
    }
    cout << "Da thuc dt6 sau khi --: ";
    dt6.print();
    cout << endl;
    return 0;
}