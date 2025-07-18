#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> stack;
public:
    Stack() {}
    Stack(vector<int> stack)
        : stack(stack) {}
    ~Stack() {}

    void setStack(vector<int> stack) { this->stack = stack; }
    vector<int> getStack() { return stack; }

    void pushMultipleStack(){
        int value;
        stack.clear(); // Xóa stack hiện tại
        cout << "Nhập các giá trị stack: ";
        while (cin >> value){ 
            if (value == -1) // -1 để dừng
                break;
            stack.push_back(value);
        }
    }
    void displayAllStack(){
        for (int i = stack.size() - 1; i >= 0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    int countStackElement(){
        return stack.size();
    }
    void pushOneStack(int value){
        stack.push_back(value);
    }
    int popOneStack(){
        int value = stack.back();
        stack.pop_back();
        return value;
    }
    void emptyStack(){
        stack.clear();
    }
    friend istream& operator>>(istream& input, Stack& stack){
        int value;
        stack.stack.clear(); // Xóa stack hiện tại
        cout << "Nhập các giá trị stack: ";
        while (input >> value) {
            if (value == -1) 
                break;
            stack.stack.push_back(value);
        }
        return input;
    }
    friend ostream& operator<< (ostream& output, Stack& stack){
        for (int i = stack.stack.size() - 1; i >= 0; i--){
            cout << stack.stack[i] << " ";
        }
        cout << endl;
        return output;
    }
};

int main() {
    Stack s;

    // Test case 1: Kiểm tra khởi tạo Stack rỗng và emptyStack
    cout << "Test case 1: Stack rỗng và emptyStack" << endl;
    cout << "Số phần tử ban đầu: " << s.countStackElement() << endl; // Dự kiến: 0
    s.pushOneStack(5);
    s.emptyStack();
    cout << "Số phần tử sau khi empty: " << s.countStackElement() << endl; // Dự kiến: 0
    cout << "--------------------" << endl;

    // Test case 2: Kiểm tra pushOneStack và displayAllStack
    cout << "Test case 2: pushOneStack và displayAllStack" << endl;
    s.pushOneStack(1);
    s.pushOneStack(2);
    s.pushOneStack(3);
    cout << "Stack sau khi push 1, 2, 3: ";
    s.displayAllStack(); // Dự kiến: 3 2 1
    cout << "Số phần tử: " << s.countStackElement() << endl; // Dự kiến: 3
    cout << "--------------------" << endl;

    // Test case 3: Kiểm tra popOneStack
    cout << "Test case 3: popOneStack" << endl;
    int popped = s.popOneStack();
    cout << "Phần tử pop: " << popped << endl; // Dự kiến: 3
    cout << "Stack sau khi pop: ";
    s.displayAllStack(); // Dự kiến: 2 1
    cout << "Số phần tử: " << s.countStackElement() << endl; // Dự kiến: 2
    cout << "--------------------" << endl;

    // Test case 4: Kiểm tra pushMultipleStack
    cout << "Test case 4: pushMultipleStack (Nhập: 4 5 6 -1)" << endl;
    s.pushMultipleStack(); // Nhập thủ công: 4 5 6 -1
    cout << "Stack sau khi push multiple: ";
    s.displayAllStack(); // Dự kiến: 6 5 4
    cout << "Số phần tử: " << s.countStackElement() << endl; // Dự kiến: 3
    cout << "--------------------" << endl;

    // Test case 5: Kiểm tra toán tử >> và <<
    cout << "Test case 5: Toán tử >> và << (Nhập: 7 8 9 -1)" << endl;
    cin >> s; // Nhập thủ công: 7 8 9 -1
    cout << "Stack sau khi dùng toán tử >>: ";
    cout << s; // Dự kiến: 9 8 7
    cout << "Số phần tử: " << s.countStackElement() << endl; // Dự kiến: 3
    cout << "--------------------" << endl;

    // Test case 6: Kiểm tra setStack và getStack
    cout << "Test case 6: setStack và getStack" << endl;
    vector<int> newStack = {10, 11, 12};
    s.setStack(newStack);
    cout << "Stack sau khi set: ";
    s.displayAllStack(); // Dự kiến: 12 11 10
    vector<int> retrievedStack = s.getStack();
    cout << "Lấy stack bằng getStack: ";
    for (int i = retrievedStack.size() - 1; i >= 0; i--) {
        cout << retrievedStack[i] << " ";
    }
    cout << endl; // Dự kiến: 12 11 10
    cout << "--------------------" << endl;

    return 0;
}