/*
Xét đa thức theo biến x (một biến) bậc n có dạng như sau:
P(X) = a1.x^n + a2.x^(n-1) + a3.x^(n-2) + … + aj
Trong đó: n là bậc của đa thức. a1, a2, a3,…, aj là các hệ số tương ứng với từng bậc của đa thức.
a. Xây dựng lớp DaThuc biểu diễn khái niệm đa thức với các thao tác như sau:
- Khởi tạo đa thức có bậc bằng 0
- Khởi tạo đa thức bậc n bất kỳ.
- Tính giá trị đa thức khi biết giá trị của biến x
- Định nghĩa các toán tử: >>, <<, +, -
b. Viết chương trình minh họa các chức năng tương ứng.
*/

#include <iostream>
#include <cmath>
using namespace std;

class DaThuc
{
private:
    int bac;
    double *heSo;

public:
    DaThuc() : bac(0)
    {
        heSo = new double[1];
        heSo[0] = 0;
    }
    DaThuc(int n) : bac(n)
    {
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++)
        {
            heSo[i] = 0;
        }
    }
    DaThuc(const DaThuc &d) : bac(d.bac)
    {
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++)
        {
            heSo[i] = d.heSo[i];
        }
    }
    ~DaThuc()
    {
        delete[] heSo;
    }

    double calculate(double x)
    {
        double result = 0;
        for (int i = 0; i <= bac; i++)
        {
            result += heSo[i] * pow(x, bac - i);
        }
        return result;
    }
    friend DaThuc operator+(const DaThuc &d1, const DaThuc &d2);
    friend DaThuc operator-(const DaThuc &d1, const DaThuc &d2);
    friend istream &operator>>(istream &in, DaThuc &d);
    friend ostream &operator<<(ostream &out, const DaThuc &d);
};

DaThuc operator+(const DaThuc &d1, const DaThuc &d2)
{
    int maxBac = max(d1.bac, d2.bac);
    DaThuc result(maxBac);
    for (int i = 0; i <= maxBac; i++)
    {
        double heSo1 = (i <= d1.bac) ? d1.heSo[d1.bac - i] : 0;
        double heSo2 = (i <= d2.bac) ? d2.heSo[d2.bac - i] : 0;
        result.heSo[maxBac - i] = heSo1 + heSo2;
    }
    return result;
}

DaThuc operator-(const DaThuc &d1, const DaThuc &d2)
{
    int maxBac = max(d1.bac, d2.bac);
    DaThuc result(maxBac);
    for (int i = 0; i <= maxBac; i++)
    {
        double heSo1 = (i <= d1.bac) ? d1.heSo[d1.bac - i] : 0;
        double heSo2 = (i <= d2.bac) ? d2.heSo[d2.bac - i] : 0;
        result.heSo[maxBac - i] = heSo1 - heSo2;
    }
    return result;
}

istream &operator>>(istream &in, DaThuc &d)
{
    cout << "Nhap bac da thuc: ";
    in >> d.bac;
    delete[] d.heSo;
    d.heSo = new double[d.bac + 1];
    for (int i = 0; i <= d.bac; i++)
    {
        cout << "Nhap he so cua x^" << (d.bac - i) << ": ";
        in >> d.heSo[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const DaThuc &d)
{
    for (int i = 0; i <= d.bac; i++)
    {
        if (d.heSo[i] != 0)
        {
            if (i > 0 && d.heSo[i] > 0)
            {
                cout << "+ ";
            }
            cout << d.heSo[i];
            if (d.bac - i > 0)
            {
                cout << "x";
                if (d.bac - i > 1)
                {
                    cout << "^" << (d.bac - i);
                }
            }
            cout << " ";
        }
    }
    return out;
}

int main()
{
    DaThuc d1, d2;
    cout << "Nhap da thuc thu nhat:" << endl;
    cin >> d1;
    cout << "Nhap da thuc thu hai:" << endl;
    cin >> d2;

    cout << "Da thuc thu nhat: " << d1 << endl;
    cout << "Da thuc thu hai: " << d2 << endl;

    DaThuc tong = d1 + d2;
    DaThuc hieu = d1 - d2;

    cout << "Tong hai da thuc: " << tong << endl;
    cout << "Hieu hai da thuc: " << hieu << endl;

    double x;
    cout << "Nhap gia tri x de tinh gia tri da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri da thuc thu nhat tai x = " << x << " la: " << d1.calculate(x) << endl;

    return 0;
}