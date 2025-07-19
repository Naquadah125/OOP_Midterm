#include <iostream>
using namespace std;

class Mang1C {
private:
    int soPT;
    int data[100];
public:
    Mang1C() : soPT(-1) {}
    Mang1C(int soPT, int data[]) {
        this->soPT = soPT;
        for (int i = 0; i < soPT; i++) {
            this->data[i] = data[i];
        }
    }
    ~Mang1C() {}

    int getSoPT() const { return soPT; }
    void setSoPT(int soPT) { this->soPT = soPT; }
    void setData(int value, int index){
        data[index] = value;
    }
    void setDataArray(int data[], int soPT){
        for (int i = 0; i < soPT; i++){
            this->data[i] = data[i];
        }
    }
    int getSoPt() { return soPT; }
    int getData(int index){
        return data[index];
    }

    virtual void input() {
        cout << "Nhap kich thuoc mang: ";
        cin >> soPT;
        for (int i = 0; i < soPT; i++){
            cout << "Nhap gia tri cua mang tai " << i << ": ";
            cin >> data[i];
        }
        cout << endl;
    }
    virtual void print() {
        cout << "Kich thuoc mang: " << soPT << endl;
        for (int i = 0; i < soPT; i++){
            cout << "tai vi tri " << i << ": " << data[i] << endl;
        }
        cout << endl;
    }
};
class Stack : public Mang1C {
public:
    Stack() : Mang1C() {}
    Stack(int soPT, int data[])
        : Mang1C(soPT, data) {}
    ~Stack() {}

    int isEmpty(){
        if (getSoPT() == -1){
            return -1;
        }
        else
            return getSoPT();
    }

    void push(int data){
        int newSoPT = getSoPT();
        if (newSoPT == -1)
            newSoPT = 0;

        setSoPT(newSoPT + 1); // thêm 1 phần tử
        setData(data, newSoPT);
    }
    int pop(){
        int newSoPT = getSoPT();
        if (newSoPT <= 0)
            return -1;

        int newData = getData(newSoPT - 1);
        setSoPT(newSoPT - 1);
        return newData;
    }
};
class Binary : public Mang1C {
public:
    Binary() : Mang1C() {}
    Binary(int soPT, int data[])
        : Mang1C(soPT, data) {}
    ~Binary() {}

    void doiNhiPhan(int n){
        if (n < 0) {
            cout << "Khong xu ly so am!";
            return;
        }
        if (n > 1) {
            doiNhiPhan(n / 2);
        }
        cout << n % 2;
    }
};

int main() {
    // Test case 1: Kiểm tra lớp Mang1C cơ bản (khởi tạo và print)
    int arrData[] = {5, 10, 15};
    Mang1C mang(3, arrData);
    cout << "Test Mang1C co du lieu ban dau:" << endl;
    mang.print();  // Mong đợi: Kich thuoc mang: 3, in cac gia tri 5, 10, 15

    // Test case 2: Kiểm tra input() từ Mang1C
    Mang1C mang2;
    cout << "Test input cho Mang1C:" << endl;
    mang2.input();  // Nhập từ người dùng, ví dụ nhập soPT=2, gia tri 20 25
    mang2.print();  // Mong đợi: In theo input

    // Test case 3: Kiểm tra Stack (push, pop, isEmpty)
    Stack stack;
    cout << "Test Stack rong:" << endl;
    cout << "isEmpty: " << stack.isEmpty() << endl;  // Mong đợi: -1 (rong)
    cout << "Pop tren stack rong: " << stack.pop() << endl;  // Mong đợi: -1

    stack.push(100);
    stack.push(200);
    stack.push(300);
    cout << "Sau push 100, 200, 300:" << endl;
    stack.print();  // Mong đợi: Kich thuoc 3, gia tri 100, 200, 300
    cout << "isEmpty: " << stack.isEmpty() << endl;  // Mong đợi: 3 (khong rong)

    cout << "Pop: " << stack.pop() << endl;  // Mong đợi: 300
    cout << "Pop: " << stack.pop() << endl;  // Mong đợi: 200
    stack.print();  // Mong đợi: Kich thuoc 1, gia tri 100

    // Test case 4: Kiểm tra Binary (doiNhiPhan)
    Binary binary;
    cout << "Test doiNhiPhan voi n=13: ";
    binary.doiNhiPhan(13);  // Mong đợi: In 1101
    cout << endl;

    cout << "Test doiNhiPhan voi n=0: ";
    binary.doiNhiPhan(0);  // Mong đợi: In 0
    cout << endl;

    cout << "Test doiNhiPhan voi n=1: ";
    binary.doiNhiPhan(1);  // Mong đợi: In 1
    cout << endl;

    return 0;
}