#include <iostream>
using namespace std;

class Mang{
private:
    int arr[100];
    int size;
public:
    Mang() : size(0) {}
    Mang(int arr[], int size){
        if (size < 0 || size > 100) {
            this->size = 0;
            return;
        }
        this->size = size;
        for (int i = 0; i < size; i++){
            this->arr[i] = arr[i];
        }
    }
    ~Mang() {}

    int getSize() { return size; }
    int getElementAtIndex(int index){
        return arr[index]; 
    }

    friend istream& operator>> (istream& input, Mang& mang){
        cout << "Nhap kich thuoc mang: ";
        input >> mang.size;

        for (int i = 0; i < mang.size; i++){
            cout << "Nhap element tai index " << i << ": ";
            input >> mang.arr[i];
        }
        return input;
    }
    friend ostream& operator<< (ostream& output, const Mang& mang){
        for (int i = 0; i < mang.size; i++){
            output << "Gia tri tai index " << i << ": " << mang.arr[i] << endl;
        }
        return output;
    }

    void addElementAt(int value, int index){
        for (int i = size; i > index; i--){ // chạy từ size(cuối) đến index
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }
    void deleteElementAt(int index){
        for (int i = index; i < size - 1; i++){ // chạy từ index -> size
            arr[i] = arr[i + 1];
        }
        size--;
    }
    void sortArray(){
        for (int i = 0; i < size; i++){
            for (int j = i + 1; j < size; j++){
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }
    int findMin(){
        int min = arr[0];
        for (int i = 1; i < size; i++){
            if (min > arr[i]){
                min = arr[i];
            }
        }
        return min;
    }
    int findMax(){
        int max = arr[0];
        for (int i = 1; i < size; i++){
            if (max < arr[i]){
                max = arr[i];
            }
        }
        return max;
    }
    int sumArr(){
        int sum = 0;
        for (int i = 0; i < size; i++){
            sum += arr[i];
        }
        return sum;
    }

}; 

int main() {
    // Test Case 1: Kiểm tra constructor mặc định và mảng rỗng
    cout << "Test Case 1: Mang rong\n";
    Mang m1;
    cout << "Kich thuoc: " << m1.getSize() << endl; // Kỳ vọng: 0
    cout << m1; // Kỳ vọng: "Mang rong!"
    cout << "Min: " << m1.findMin() << endl; // Kỳ vọng: Thông báo mảng rỗng, trả về 0
    cout << "Max: " << m1.findMax() << endl; // Kỳ vọng: Thông báo mảng rỗng, trả về 0
    cout << "Tong: " << m1.sumArr() << endl; // Kỳ vọng: Thông báo mảng rỗng, trả về 0
    cout << "------------------------\n";

    // Test Case 2: Kiểm tra constructor với tham số
    cout << "Test Case 2: Constructor voi tham so\n";
    int arr1[] = {5, 3, 8, 1};
    Mang m2(arr1, 4);
    cout << "Mang sau khi khoi tao: \n" << m2; // Kỳ vọng: 5, 3, 8, 1
    cout << "Kich thuoc: " << m2.getSize() << endl; // Kỳ vọng: 4
    cout << "------------------------\n";

    // Test Case 3: Kiểm tra nhập/xuất mảng
    cout << "Test Case 3: Nhap/xuat mang\n";
    Mang m3;
    cin >> m3; // Nhập size = 3, phần tử: 2, 4, 6
    cout << "Mang sau khi nhap: \n" << m3 ; // Kỳ vọng: 2, 4, 6
    cout << "------------------------\n";

    // Test Case 4: Kiểm tra addElementAt
    cout << "Test Case 4: Them phan tu\n";
    Mang m4;
    m4.addElementAt(1, 0); // Thêm 1 vào vị trí 0
    m4.addElementAt(2, 1); // Thêm 2 vào vị trí 1
    m4.addElementAt(3, 1); // Thêm 3 vào vị trí 1
    cout << "Mang sau khi them: \n" << m4; // Kỳ vọng: 1, 3, 2
    cout << "------------------------\n";

    // Test Case 5: Kiểm tra deleteElementAt
    cout << "Test Case 5: Xoa phan tu\n";
    cout << "Mang truoc khi xoa: \n" << m4; // Kỳ vọng: 1, 3, 2
    m4.deleteElementAt(1); // Xóa phần tử tại index 1 (3)
    cout << "Mang sau khi xoa tai vi tri 1: \n" << m4; // Kỳ vọng: 1, 2
    m4.deleteElementAt(0); // Xóa phần tử tại index 0 (1)
    cout << "Mang sau khi xoa tai vi tri 0: \n" << m4; // Kỳ vọng: 2
    cout << "------------------------\n";

    // Test Case 6: Kiểm tra sortArray
    cout << "Test Case 6: Sap xep mang\n";
    int arr3[] = {4, 2, 5, 1, 3};
    Mang m5(arr3, 5);
    cout << "Mang truoc khi sap xep: \n" << m5; // Kỳ vọng: 4, 2, 5, 1, 3
    m5.sortArray();
    cout << "Mang sau khi sap xep: \n" << m5; // Kỳ vọng: 1, 2, 3, 4, 5
    cout << "------------------------\n";

    // Test Case 7: Kiểm tra findMin, findMax, sumArr
    cout << "Test Case 7: Min, Max, Tong\n";
    cout << "Mang: \n" << m5; // Kỳ vọng: 1, 2, 3, 4, 5
    cout << "Min: " << m5.findMin() << endl; // Kỳ vọng: 1
    cout << "Max: " << m5.findMax() << endl; // Kỳ vọng: 5
    cout << "Tong: " << m5.sumArr() << endl; // Kỳ vọng: 15
    cout << "------------------------\n";

    // Test Case 8: Kiểm tra getElementAtIndex
    cout << "Test Case 8: Truy cap phan tu\n";
    cout << "Gia tri tai index 2: " << m5.getElementAtIndex(2) << endl; // Kỳ vọng: 3
    cout << "Gia tri tai index -1: " << m5.getElementAtIndex(-1) << endl; // Kỳ vọng: Thông báo lỗi, trả về 0
    cout << "Gia tri tai index 10: " << m5.getElementAtIndex(10) << endl; // Kỳ vọng: Thông báo lỗi, trả về 0
    cout << "------------------------\n";

    // Test Case 9: Kiểm tra trường hợp mảng đầy
    cout << "Test Case 9: Mang day\n";
    Mang m7;
    for (int i = 0; i < 100; i++) {
        m7.addElementAt(i, i);
    }
    cout << "Kich thuoc sau khi them 100 phan tu: " << m7.getSize() << endl; // Kỳ vọng: 100

    return 0;
}