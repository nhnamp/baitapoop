/*
Định nghĩa lớp cHocSinh gồm các thuộc tính: mã, họ tên, giới tính, năm sinh, điểm trung bình và các phương thức cần thiết.
Viết chương trình cho phép người dùng nhập thông tin 2 học sinh.
- Cho biết học sinh nào có điểm trung bình cao hơn.
- Cho biết học sinh nào có tuổi nhỏ hơn
*/

#include <bits/stdc++.h>
using namespace std;

class cHocSinh
{
private:
    string id, name, gender;
    int birthYear;
    float gpa;

public:
    void input()
    {
        cout << "Nhap ma hoc sinh: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, name);
        cout << "Nhap gioi tinh: ";
        getline(cin, gender);
        cout << "Nhap nam sinh: ";
        cin >> birthYear;
        cout << "Nhap diem trung binh: ";
        cin >> gpa;
    }
    void output()
    {
        cout << "Ma hoc sinh: " << id << endl;
        cout << "Ho ten: " << name << endl;
        cout << "Gioi tinh: " << gender << endl;
        cout << "Nam sinh: " << birthYear << endl;
        cout << "Diem trung binh: " << fixed << setprecision(2) << gpa << endl;
    }
    float getGPA()
    {
        return gpa;
    }
    int getAge(int currentYear = 2025)
    {
        return currentYear - birthYear;
    }
};

int main()
{
    cHocSinh hs1, hs2;
    cout << "Nhap thong tin hoc sinh thu nhat:" << endl;
    hs1.input();
    cout << "Nhap thong tin hoc sinh thu hai:" << endl;
    hs2.input();
    cout << "Hoc sinh co diem trung binh cao hon:" << endl;
    if (hs1.getGPA() > hs2.getGPA())
    {
        hs1.output();
    }
    else if (hs1.getGPA() < hs2.getGPA())
    {
        hs2.output();
    }
    else
    {
        cout << "Hai hoc sinh co diem trung binh bang nhau." << endl;
    }
    cout << "Hoc sinh co tuoi nho hon:" << endl;
    if (hs1.getAge() < hs2.getAge())
    {
        hs1.output();
    }
    else if (hs1.getAge() > hs2.getAge())
    {
        hs2.output();
    }
    else
    {
        cout << "Hai hoc sinh bang tuoi." << endl;
    }
}