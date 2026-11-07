#pragma once
#include <iostream>
#include <string>

using namespace std;

class Button {
private:
    int width;
    int height;

public:
    Button();
    Button(int w, int h);

    void setWidth(int w);
    void setHeight(int h);

    int getWidth() const;
    int getHeight() const;

    operator string() const;

    friend ostream& operator<<(ostream& out, const Button& b);
    friend istream& operator>>(istream& in, Button& b);
};