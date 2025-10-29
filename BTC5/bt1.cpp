/*
Cài đặt lớp số phức để biểu diễn khái niệm số phức, cho phép quan điểm một số thực như một số phức đặc biệt (phần ảo bằng 0).
Định nghĩa các phép toán +, -, *, /, ==, <<, >> trên số phức.
Định nghĩa các thao tác cần thiết cho lớp số phức: cong, tru, nhan, chia
*/

#include <iostream>

using namespace std;

class SoPhuc
{
private:
    double thuc;
    double ao;

public:
    SoPhuc() : thuc(0), ao(0) {}
    SoPhuc(double t, double a) : thuc(t), ao(a) {}

    double getThuc() const { return thuc; }
    double getAo() const { return ao; }
    void setThuc(double t) { thuc = t; }
    void setAo(double a) { ao = a; }

    friend SoPhuc operator+(const SoPhuc &a, const SoPhuc &b);
    friend SoPhuc operator-(const SoPhuc &a, const SoPhuc &b);
    friend SoPhuc operator*(const SoPhuc &a, const SoPhuc &b);
    friend SoPhuc operator/(const SoPhuc &a, const SoPhuc &b);
    friend bool operator==(const SoPhuc &a, const SoPhuc &b);
    friend istream &operator>>(istream &in, SoPhuc &sp);
    friend ostream &operator<<(ostream &out, const SoPhuc &sp);
};

SoPhuc operator+(const SoPhuc &a, const SoPhuc &b)
{
    return SoPhuc(a.thuc + b.thuc, a.ao + b.ao);
}

SoPhuc operator-(const SoPhuc &a, const SoPhuc &b)
{
    return SoPhuc(a.thuc - b.thuc, a.ao - b.ao);
}

SoPhuc operator*(const SoPhuc &a, const SoPhuc &b)
{
    double newThuc = a.thuc * b.thuc - a.ao * b.ao;
    double newAo = a.thuc * b.ao + a.ao * b.thuc;
    return SoPhuc(newThuc, newAo);
}

SoPhuc operator/(const SoPhuc &a, const SoPhuc &b)
{
    double mauSo = b.thuc * b.thuc + b.ao * b.ao;
    double newThuc = (a.thuc * b.thuc + a.ao * b.ao) / mauSo;
    double newAo = (a.ao * b.thuc - a.thuc * b.ao) / mauSo;
    return SoPhuc(newThuc, newAo);
}

bool operator==(const SoPhuc &a, const SoPhuc &b)
{
    return (a.thuc == b.thuc) && (a.ao == b.ao);
}

istream &operator>>(istream &in, SoPhuc &sp)
{
    cout << "Phan thuc: ";
    in >> sp.thuc;
    cout << "Phan ao: ";
    in >> sp.ao;
    return in;
}

ostream &operator<<(ostream &out, const SoPhuc &sp)
{
    out << sp.thuc;
    if (sp.ao >= 0)
        out << " + " << sp.ao << "i";
    else
        out << " - " << -sp.ao << "i";
    return out;
}

int main()
{
    SoPhuc sp1, sp2;
    cout << "Nhap so phuc thu nhat: ";
    cin >> sp1;
    cout << "Nhap so phuc thu hai: ";
    cin >> sp2;

    cout << "So phuc thu nhat: " << sp1 << endl;
    cout << "So phuc thu hai: " << sp2 << endl;

    cout << "Tong: " << (sp1 + sp2) << endl;
    cout << "Hieu: " << (sp1 - sp2) << endl;
    cout << "Tich: " << (sp1 * sp2) << endl;
    cout << "Thuong: " << (sp1 / sp2) << endl;

    if (sp1 == sp2)
        cout << "Hai so phuc bang nhau" << endl;
    else
        cout << "Hai so phuc khong bang nhau" << endl;

    return 0;
}