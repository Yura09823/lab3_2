#pragma once
#include "Button.h"

class Window {
private:
    Button button; 
    int x;
    int y;

public:
    Window();
    Window(const Button& btn, int xCoord, int yCoord);
    virtual ~Window();

    void setButton(const Button& btn);
    void setX(int xCoord);
    void setY(int yCoord);

    Button getButton() const;
    int getX() const;
    int getY() const;

    virtual operator string() const;

    friend ostream& operator<<(ostream& out, const Window& w);
    friend istream& operator>>(istream& in, Window& w);
};