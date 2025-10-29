/*
Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung bình, xếp loại và xuất kết quả.
*/

#include <bits/stdc++.h>
using namespace std;

class cStudent
{
private:
    string name;
    float math, literature;
    float average;

public:
    void input()
    {
        cout << "Nhap ho ten: ";
        getline(cin, name);
        cout << "Nhap diem toan: ";
        cin >> math;
        cout << "Nhap diem van: ";
        cin >> literature;
    }
    void getAverage()
    {
        average = (math + literature) / 2;
    }
    void getClassification()
    {
        if (average >= 9)
            cout << "Xep loai: Xuat sac" << endl;
        else if (average >= 8)
            cout << "Xep loai: Gioi" << endl;
        else if (average >= 6.5)
            cout << "Xep loai: Kha" << endl;
        else if (average >= 5)
            cout << "Xep loai: Trung binh" << endl;
        else
            cout << "Xep loai: Yeu" << endl;
    }
    void output()
    {
        cout << "Ho ten: " << name << endl;
        cout << "Diem toan: " << math << endl;
        cout << "Diem van: " << literature << endl;
        cout << "Diem trung binh: " << fixed << setprecision(2) << average << endl;
        getClassification();
    }
};

int main()
{
    cStudent hs;
    hs.input();
    hs.getAverage();
    hs.output();
    return 0;
}