/*
Viết chương trình nhập vào tọa độ 2 điểm trong mặt phẳng Oxy. Tính khoảng cách giữa chúng và xuất kết quả.
*/
#include <bits/stdc++.h>
using namespace std;

class cPoint
{
private:
    float x, y;

public:
    void input()
    {
        cout << "Nhap toa do diem (x, y): ";
        cin >> x >> y;
    }
    float getDistance(cPoint d)
    {
        return sqrt(pow(this->x - d.x, 2) + pow(this->y - d.y, 2));
    }
};

int main()
{
    cPoint d1, d2;
    d1.input();
    d2.input();
    cout << "Khoang cach giua hai diem: " << d1.getDistance(d2) << endl;
    return 0;
}