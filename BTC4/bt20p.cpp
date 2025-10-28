/*
Cài đặt lớp Đơn thức biểu diễn khái niệm đơn thức (P(x) = ax^b) cho phép thực hiện các yêu cầu sau:
1. Tạo lập đơn thức
2. Nhập thông tin cho đơn thức, thay đổi thông tin đơn thức
3. Xuất đơn thức ra màn hình
4. Tính giá trị của đơn thức khi biết x
5. Tính đạo hàm của đơn thức
6. Tính tổng hai đơn thức (hai đơn thức cùng bậc)
Viết chương trình cho phép nhập vào 2 đơn thức, tính tổng hai đơn thức và xuất kế quả ra màn hình.
*/

#include <iostream>
#include <cmath>
using namespace std;

class DonThuc
{
private:
    double heSo;
    int soMu;

public:
    DonThuc() : heSo(0), soMu(0) {}
    DonThuc(double h, int s) : heSo(h), soMu(s) {}
    DonThuc(const DonThuc &other) : heSo(other.heSo), soMu(other.soMu) {}

    void input()
    {
        cout << "Nhap he so: ";
        cin >> heSo;
        cout << "Nhap so mu: ";
        cin >> soMu;
    }
    void update()
    {
        cout << "Ban muon cap nhat he so hay so mu? (1: he so, 2: so mu, 3: ca hai): ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Nhap he so moi: ";
            cin >> heSo;
        }
        else if (choice == 2)
        {
            cout << "Nhap so mu moi: ";
            cin >> soMu;
        }
        else if (choice == 3)
        {
            cout << "Nhap he so moi: ";
            cin >> heSo;
            cout << "Nhap so mu moi: ";
            cin >> soMu;
        }
    }
    void output()
    {
        if (heSo == 0)
        {
            cout << "0";
            return;
        }
        if (soMu == 0)
        {
            cout << heSo;
        }
        else if (soMu == 1)
        {
            cout << heSo << "x";
        }
        else
        {
            cout << heSo << "x^" << soMu;
        }
    }
    double calculate(double x)
    {
        return heSo * pow(x, soMu);
    }
    DonThuc derivative()
    {
        if (soMu == 0)
        {
            return DonThuc(0, 0);
        }
        return DonThuc(heSo * soMu, soMu - 1);
    }
    DonThuc add(const DonThuc &other)
    {
        if (soMu != other.soMu)
        {
            cout << "Khong the tinh tong hai don thuc khac bac" << endl;
            return DonThuc(0, 0);
        }
        return DonThuc(heSo + other.heSo, soMu);
    }
};

int main()
{
    DonThuc dt1, dt2;
    cout << "Nhap don thuc thu nhat:" << endl;
    dt1.input();
    cout << "Nhap don thuc thu hai:" << endl;
    dt2.input();

    DonThuc tong = dt1.add(dt2);
    cout << "Tong hai don thuc: ";
    tong.output();
    cout << endl;
    return 0;
}