/*
Cài đặt lớp số phức để biểu diễn khái niệm số phức (một số phức bao gồm hai thành phần: phần ảo, phần thực).
Cho phép thực hiên các thao tác sau:
- Tạo lập số phức khi biết phần thực và ảo
- Thay đổi phần thực, phần ảo
- Lấy giá trị phần thực, phần ảo
- Nhập số phức
- Xuất số phức
- Công hai số phức.
*/

#include <bits/stdc++.h>
using namespace std;

class cComplex
{
private:
    float real, imagine;

public:
    cComplex()
    {
        real = 0;
        imagine = 0;
    }
    cComplex(float r, float i)
    {
        real = r;
        imagine = i;
    }
    void setReal(float r)
    {
        real = r;
    }
    void setImagine(float i)
    {
        imagine = i;
    }
    float getReal()
    {
        return real;
    }
    float getImagine()
    {
        return imagine;
    }
    void input()
    {
        cout << "Nhap phan thuc: ";
        cin >> real;
        cout << "Nhap phan ao: ";
        cin >> imagine;
    }
    void output()
    {
        cout << real << (imagine >= 0 ? " + " : " - ") << abs(imagine) << "i" << endl;
    }
    cComplex getSum(cComplex c)
    {
        cComplex result;
        result.setReal(this->getReal() + c.getReal());
        result.setImagine(this->getImagine() + c.getImagine());
        return result;
    }
};

int main()
{
    cComplex c1, c2;
    cout << "Nhap so phuc thu nhat:" << endl;
    c1.input();
    cout << "Nhap so phuc thu hai:" << endl;
    c2.input();
    cComplex sum = c1.getSum(c2);
    cout << "Tong hai so phuc: ";
    sum.output();
    return 0;
}
