#include<iostream>
#include "Canvas.h"
#include<cmath>

Canvas::Canvas(int width, int height): width(width), height(height) {
    matrix=new char*[height];
    for(int i=0;i<height;i++)
        matrix[i]=new char[width];
    Clear();
}

void Canvas::Clear() {
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            matrix[i][j]=' ';
}

Canvas::~Canvas() {
    for(int i=0;i<height;i++)
        delete[] matrix[i];
    delete[] matrix;
}

void Canvas::Print() {
    for(int i=0;i<height;++i) {
        for(int j=0;j<width;++j) {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<'\n';
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x>0 && x<width && y>0 && y<height)
        matrix[x][y]=ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = std::abs(x2 - x1);
    int dy = -std::abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left, top, right, top, ch);       // Sus
    DrawLine(left, bottom, right, bottom, ch); // Jos
    DrawLine(left, top, left, bottom, ch);     // Stânga
    DrawLine(right, top, right, bottom, ch);   // Dreapta
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i=top;i<=bottom;++i)
        for (int j=left;j<=right;++j)
            SetPoint(j,i,ch);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int i = 0, j = ray;
    int d = 3 - 2 * ray;
    while (j >= i) {
        SetPoint(x + i, y + j, ch);
        SetPoint(x - i, y + j, ch);
        SetPoint(x + i, y - j, ch);
        SetPoint(x - i, y - j, ch);
        SetPoint(x + j, y + i, ch);
        SetPoint(x - j, y + i, ch);
        SetPoint(x + j, y - i, ch);
        SetPoint(x - j, y - i, ch);
        i++;
        if (d > 0) {
            j--;
            d = d + 4 * (i - j) + 10;
        } else {
            d = d + 4 * i + 6;
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = y - ray; i <= y + ray; ++i) {
        for (int j = x - ray; j <= x + ray; ++j) {
            if ((i - y) * (i - y) + (j - x) * (j - x) <= ray * ray) {
                SetPoint(j, i, ch);
            }
        }
    }
}
