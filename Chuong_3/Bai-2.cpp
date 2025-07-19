#include <iostream>
using namespace std;

class Animal {
private:
    int age;
    double weight;
    int sex; // 0 = male, 1 = female
public:
    Animal() {}
    Animal(int age, double weight, int sex)
        : age(age), weight(weight), sex(sex) {}
    ~Animal() {}

    void setAge(int age) { this-> age = age; }
    void setWeight(double weight) { this->weight = weight; }
    void setSex(int sex) { this->sex = sex; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    int getSex() const { return sex; }
    void setAnimal(int age, double weight, int sex){
        this->age = age;
        this->weight = weight;
        this->sex = sex;
    }
   
    virtual void actionAn() {
        cout << "Con vat dang an" << endl;
    }
    virtual void printAnimal(){
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
        if (sex == 0)
            cout << "Sex: male" << endl;
        else
            cout << "Sex: female" << endl;
    }

};

class Elephant : public Animal {
private:
    int root; // 0 = châu á, 1 = châu phi
public:
    Elephant() {}
    Elephant(int age, double weight, int sex, int root)
        : Animal(age, weight, sex), root(root) {}
    ~Elephant() {}

    void setAnimal(int age, double weight, int sex, int root) {
        Animal::setAnimal(age, weight, sex);
        this->root = root;
    }

    void printAnimal() override{
        Animal::printAnimal();
        if (root == 0)
            cout << "Root: Châu Á" << endl;
        else
            cout << "Root: Châu Phi" << endl;;
    }
    void actionAn() override{
        cout << "Voi dang an co" << endl;
    }
};

int main() {
    // Test case: Tạo đối tượng Elephant với thông tin ban đầu
    Elephant voi(5, 3000.5, 0, 1);  // Tuổi 5, cân nặng 3000.5, giới tính male (0), nguồn gốc Châu Phi (1)
    
    cout << "Thong tin voi ban dau:" << endl;
    voi.printAnimal();  // Kiểm tra override printAnimal: In age, weight, sex (male), root (Châu Phi)
    voi.actionAn();     // Kiểm tra override actionAn: In "Voi dang an co"
    
    cout << "\nCap nhat thong tin voi:" << endl;
    voi.setAnimal(10, 5000.0, 1, 0);  // Cập nhật: Tuổi 10, cân nặng 5000.0, giới tính female (1), nguồn gốc Châu Á (0)
    
    voi.printAnimal();  // In lại để kiểm tra thay đổi: age=10, weight=5000.0, sex=female, root=Châu Á
    voi.actionAn();     // In lại actionAn (vẫn override)

    return 0;
}