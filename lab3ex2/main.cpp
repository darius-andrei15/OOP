#include <iostream>
#include "Canvas.h"
int main() {

    Canvas c(50,50);
    c.DrawCircle(15, 30, 8, '@');
    c.FillCircle(35, 30, 6, '.');
    c.DrawRect(2, 2, 20, 10, '#');
    c.FillRect(4, 4, 18, 8, '-');
    c.SetPoint(25, 25, 'X');
    c.Print();
    c.Clear();
    return 0;
}
