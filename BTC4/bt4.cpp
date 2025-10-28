/*
Xét đa thức theo biến x (đa thức một biến) bậc n có dạng như sau:
P(X) = a1.x^n + a2.x^(n-1) + a3.x^(n-2) + … + aj
Trong đó: n là bậc của đa thức. a1, a2, a3,…, aj là các hệ số tương ứng với từng bậc của đa thức.
a. Xây dựng lớp DaThuc biểu diễn khái niệm đa thức với các thao tác sau:
- Khởi tạo một đa thức có bậc bằng 0 hoặc bậc n.
- Tính giá trị của đa thức khi biết giá trị của x
- Nhập đa thức
- Xuất đa thức
- Cộng hai đa thức
- Trừ hai đa thức
b. Viết chương trình cho phép người dùng nhập vào hai đa thức rồi xuất các đa thức ra màn hình.
Sau đó tính tổng hai đa thức và xuất kết quả ra màn hình.
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
    DaThuc(const DaThuc &other) : bac(other.bac)
    {
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++)
        {
            heSo[i] = other.heSo[i];
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
    void input()
    {
        cout << "Nhap bac da thuc: ";
        cin >> bac;
        delete[] heSo;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++)
        {
            cout << "Nhap he so cua x^" << (bac - i) << ": ";
            cin >> heSo[i];
        }
    }
    void output()
    {
        for (int i = 0; i <= bac; i++)
        {
            if (heSo[i] != 0)
            {
                if (i > 0 && heSo[i] > 0)
                {
                    cout << "+ ";
                }
                cout << heSo[i];
                if (bac - i > 0)
                {
                    cout << "x";
                    if (bac - i > 1)
                    {
                        cout << "^" << (bac - i);
                    }
                }
                cout << " ";
            }
        }
    }
    DaThuc add(const DaThuc &other)
    {
        int maxBac = max(bac, other.bac);
        DaThuc result(maxBac);
        for (int i = 0; i <= maxBac; i++)
        {
            double heSo1 = (i <= bac) ? heSo[bac - i] : 0;
            double heSo2 = (i <= other.bac) ? other.heSo[other.bac - i] : 0;
            result.heSo[maxBac - i] = heSo1 + heSo2;
        }
        return result;
    }
    DaThuc subtract(const DaThuc &other)
    {
        int maxBac = max(bac, other.bac);
        DaThuc result(maxBac);
        for (int i = 0; i <= maxBac; i++)
        {
            double heSo1 = (i <= bac) ? heSo[bac - i] : 0;
            double heSo2 = (i <= other.bac) ? other.heSo[other.bac - i] : 0;
            result.heSo[maxBac - i] = heSo1 - heSo2;
        }
        return result;
    }
};

int main()
{
    DaThuc p1, p2;
    cout << "Nhap da thuc thu nhat:" << endl;
    p1.input();
    cout << "Nhap da thuc thu hai:" << endl;
    p2.input();

    cout << "Da thuc thu nhat: ";
    p1.output();
    cout << endl;

    cout << "Da thuc thu hai: ";
    p2.output();
    cout << endl;

    DaThuc tong = p1.add(p2);
    cout << "Tong hai da thuc: ";
    tong.output();
    cout << endl;

    return 0;
}