//
// Created by Darius on 3/4/2026.
//

#ifndef LABORATOR3EX2_CANVAS_H
#define LABORATOR3EX2_CANVAS_H


class Canvas
{
private:
        int width;
        int height;
        char**matrix;
public:
    Canvas(int width,int height);
    ~Canvas();
    Canvas(const Canvas& other) = delete;

    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};


#endif //LABORATOR3EX2_CANVAS_H
