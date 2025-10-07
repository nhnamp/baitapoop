/*
Viết chương trình nhập tọa độ tâm và bán kính của đường tròn. Tính diện tích và chu vi của đường tròn.
*/

#include <bits/stdc++.h>
using namespace std;

class cCircle
{
private:
    float x, y, r;

public:
    void input()
    {
        cout << "Nhap toa do tam (x, y): ";
        cin >> x >> y;
        cout << "Nhap ban kinh: ";
        cin >> r;
    }

    float getArea()
    {
        return 3.14 * r * r;
    }

    float getCircumference()
    {
        return 2 * 3.14 * r;
    }

    void output()
    {
        cout << "Toa do tam: (" << x << ", " << y << ")" << endl;
        cout << "Ban kinh: " << r << endl;
        cout << "Dien tich: " << fixed << setprecision(2) << getArea() << endl;
        cout << "Chu vi: " << fixed << setprecision(2) << getCircumference() << endl;
    }
};

int main()
{
    cCircle dt;
    dt.input();
    dt.output();
    return 0;
}