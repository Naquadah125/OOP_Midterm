#include <iostream>
#include <string>
using namespace std;

class Ngay {
private:
    int ngay;
    int thang;
    int nam;

    static int getDaysInMonth(int thang, int nam) {
        switch (thang) {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                // Kiem tra nam nhuan
                if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
                    return 29;
                return 28;
            default:
                return 31;
        }
    }
public:
    Ngay() : ngay(0), thang(0), nam(1000) {}
    Ngay(int ngay, int thang, int nam)
        : ngay(ngay), thang(thang), nam(nam) {}
    ~Ngay() {}

    void setNgay(int ngay) { this->ngay = ngay; }
    void setThang(int thang) { this->thang = thang; }
    void setNam(int nam) { this->nam = nam; }
    int getNgay() { return ngay; }
    int getThang() { return thang; }
    int getNam() { return nam; }

    friend istream& operator>> (istream& input, Ngay& ngay){
        bool valid = false;
        while (!valid){
            cout << "Nhap ngay: ";
            input >> ngay.ngay;
            cout << "Nhap thang: ";
            input >> ngay.thang;
            cout << "Nhap nam: ";
            input >> ngay.nam;

            if (ngay.ngay < 1 || ngay.ngay > getDaysInMonth(ngay.thang, ngay.nam)){
                cout << "xin vui long nhap lai: \n";
                continue;
            }
            if (ngay.thang < 1 || ngay.thang > 12){
                cout << "xin vui long nhap lai: \n";
                continue;
            }
            if (ngay.nam < 1000){
                cout << "xin vui long nhap lai: \n";
                continue;
            }

            valid = true;
        }
        return input;
    }
    friend ostream& operator<< (ostream& output, const Ngay& ngay){
        string ngayStr = to_string(ngay.ngay);
        string thangStr = to_string(ngay.thang);
        string namStr = to_string(ngay.nam);

        if (ngayStr.length() == 1)
            ngayStr = "0" + ngayStr;
        if (thangStr.length() == 1)
            thangStr = "0" + thangStr;
        if (namStr.length() == 1)
            namStr = "0" + namStr;

        output << ngayStr + "/" + thangStr + "/" + namStr << endl;
        return output;
    }
    friend Ngay operator+(const Ngay& date, int inputNgay){
        Ngay ccjday = date;
        ccjday.ngay += inputNgay;

        // Coi nếu số ngày có lố không
        if  (ccjday.ngay > getDaysInMonth(ccjday.thang, ccjday.nam)){
            ccjday.ngay -= getDaysInMonth(ccjday.thang, ccjday.nam);
            ccjday.thang++;
            if (ccjday.thang > 12){
                ccjday.thang = 1;
                ccjday.nam++;
            }
        }
        return ccjday;
    }
    friend Ngay operator-(const Ngay& date, int inputNgay){
        Ngay ccjday = date;
        ccjday.ngay -= inputNgay;

        // Coi nếu số ngày có âm không
        while (ccjday.ngay < 1){
            ccjday.thang--;
            if (ccjday.thang < 1){
                ccjday.thang = 12;
                ccjday.nam--;
            }
            ccjday.ngay += + getDaysInMonth(ccjday.thang, ccjday.nam);
        }

        return ccjday;
    }
    friend Ngay operator++(Ngay& date, int){ 
        Ngay old = date;
        date = date + 1;
        return old;
    }
    friend Ngay operator--(Ngay& date, int){  
        Ngay old = date;
        date = date - 1;
        return old;
    }
    friend bool operator<(const Ngay& dateLeft, const Ngay& dateRight){
        if (dateLeft.nam < dateRight.nam)
            return true;
        else if (dateLeft.nam > dateRight.nam)
            return false;

        if (dateLeft.thang < dateRight.thang)
            return true;
        else if (dateLeft.thang > dateRight.thang)
            return false;

        if (dateLeft.ngay < dateRight.ngay)
            return true;
        else
            return false;
    }
    friend bool operator>(const Ngay& dateLeft, const Ngay& dateRight){
        if (dateLeft.nam > dateRight.nam)
            return true;
        else if (dateLeft.nam < dateRight.nam)
            return false;

        if (dateLeft.thang > dateRight.thang)
            return true;
        else if (dateLeft.thang < dateRight.thang)
            return false;

        if (dateLeft.ngay > dateRight.ngay)
            return true;
        else
            return false;
    }
    Ngay nextDay(){
        return *this + 1;
    }
    Ngay nextDayByK(int k){
        return *this + k;
    }
    int distanceBetween2(Ngay Date2){
        Ngay Date1 = *this;
        int count = 0;

        if (Date1 < Date2){
            while (Date1 < Date2){
                Date1++;
                count++;
            }
        }
        else {
            while (Date1 > Date2){
                Date1--;
                count++;
            }
        }

        return count;
    }
    Ngay maxNgay(Ngay Date2){
        Ngay Date1 = *this;
        if (Date1 > Date2)
            return Date1;
        else
            return Date2;
        
    }

}; 

int main() {
    // Test case 1: Kiểm tra constructor, getter/setter, và operator<< (xuất định dạng)
    Ngay date1(15, 7, 2025);  // Ngày bình thường
    cout << "Test 1: Xuat ngay binh thuong: " << date1;  // Mong doi: 15/07/2025
    
    Ngay date2;  // Constructor mac dinh
    date2.setNgay(28);
    date2.setThang(2);
    date2.setNam(2024);  // Nam nhuan
    cout << "Test 1: Xuat sau set: " << date2;  // Mong doi: 28/02/2024
    cout << "Getter: Ngay = " << date2.getNgay() << ", Thang = " << date2.getThang() << ", Nam = " << date2.getNam() << endl;  // Mong doi: 28, 2, 2024

    // Test case 2: Kiểm tra operator+ (cong ngay, xu ly vuot thang/nam)
    Ngay date3(31, 12, 2025);
    Ngay next1 = date3 + 1;  // Vuot nam
    cout << "Test 2: 31/12/2025 + 1 = " << next1;  // Mong doi: 01/01/2026
    
    Ngay next2 = date2 + 1;  // Nam nhuan, thang 2 co 29 ngay
    cout << "Test 2: 28/02/2024 + 1 = " << next2;  // Mong doi: 29/02/2024
    
    Ngay next3 = date2 + 2;  // Vuot thang 2
    cout << "Test 2: 28/02/2024 + 2 = " << next3;  // Mong doi: 01/03/2024

    // Test case 3: Kiểm tra operator- (tru ngay, xu ly am va vuot thang/nam)
    Ngay prev1 = date1 - 5;  // Tru trong thang
    cout << "Test 3: 15/07/2025 - 5 = " << prev1;  // Mong doi: 10/07/2025
    
    Ngay prev2 = Ngay(1, 1, 2025) - 1;  // Vuot nam nguoc
    cout << "Test 3: 01/01/2025 - 1 = " << prev2;  // Mong doi: 31/12/2024
    
    Ngay prev3 = Ngay(1, 3, 2024) - 1;  // Nam nhuan, thang 3 tru ve thang 2
    cout << "Test 3: 01/03/2024 - 1 = " << prev3;  // Mong doi: 29/02/2024

    // Test case 4: Kiểm tra operator++ va -- (tang/giam 1 ngay, tuong tu +1 va -1)
    Ngay inc = Ngay(31, 7, 2025);
    inc++;  // Vuot thang
    cout << "Test 4: 31/07/2025 ++ = " << inc;  // Mong doi: 01/08/2025 

    Ngay dec = Ngay(1, 8, 2025);
    dec--;  // Vuot thang nguoc
    cout << "Test 4: 01/08/2025 -- = " << dec;  // Mong doi: 31/07/2025

    // Test case 5: Kiểm tra operator< va > (so sanh ngay)
    Ngay d1(15, 7, 2025), d2(16, 7, 2025), d3(15, 8, 2025), d4(15, 7, 2026);
    cout << "Test 5: 15/07/2025 < 16/07/2025? " << (d1 < d2 ? "Dung" : "Sai") << endl;  // Mong doi: Dung
    cout << "Test 5: 15/07/2025 > 15/08/2025? " << (d1 > d3 ? "Dung" : "Sai") << endl;  // Mong doi: Sai
    cout << "Test 5: 15/07/2025 < 15/07/2026? " << (d1 < d4 ? "Dung" : "Sai") << endl;  // Mong doi: Dung

    // Test case 6: Kiểm tra nextDay va nextDayByK (dung +)
    cout << "Test 6: nextDay cua 31/12/2025: " << date3.nextDay();  // Mong doi: 01/01/2026
    cout << "Test 6: nextDayByK(10) cua 20/07/2025: " << Ngay(20, 7, 2025).nextDayByK(10);  // Mong doi: 30/07/2025

    // Test case 7: Kiểm tra distanceBetween2 (khoang cach, dung vong lap ++/-- va < >)
    int dist1 = d1.distanceBetween2(d2);  // Khoang cach nho
    cout << "Test 7: Khoang cach 15/07/2025 va 16/07/2025: " << dist1 << endl;  // Mong doi: 1
    
    int dist2 = Ngay(1, 1, 2025).distanceBetween2(Ngay(31, 12, 2024));  // Vuot nam nguoc
    cout << "Test 7: Khoang cach 01/01/2025 va 31/12/2024: " << dist2 << endl;  // Mong doi: 1
    
    int dist3 = Ngay(1, 3, 2024).distanceBetween2(Ngay(1, 2, 2024));  // Nam nhuan, thang 2 co 29 ngay
    cout << "Test 7: Khoang cach 01/03/2024 va 01/02/2024: " << dist3 << endl;  // Mong doi: 29 (thang 2 day du)

    // Test case 8: Kiểm tra maxNgay (tim ngay lon hon, dung >)
    Ngay max1 = d1.maxNgay(d4);
    cout << "Test 8: Max giua 15/07/2025 va 15/07/2026: " << max1;  // Mong doi: 15/07/2026
    
    Ngay max2 = d2.maxNgay(d1);
    cout << "Test 8: Max giua 16/07/2025 va 15/07/2025: " << max2;  // Mong doi: 16/07/2025

    // Test case 9: Kiểm tra operator>> (nhap tu ban phim, test thu cong)
    Ngay inputDate;
    cout << "Test 9: Nhap ngay thu cong: " << endl;
    cin >> inputDate;
    cout << "Ngay vua nhap: " << inputDate;

    return 0;
}