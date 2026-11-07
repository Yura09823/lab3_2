#pragma once
#include "Window.h"

class WindowWithButton : public Window {
private:
    char* menu; 

public:
    WindowWithButton();
    WindowWithButton(const Button& btn, int xCoord, int yCoord, const char* menuText);
    WindowWithButton(const WindowWithButton& other); // конструктор копіювання
    WindowWithButton& operator=(const WindowWithButton& other); // присвоєння
    ~WindowWithButton() override;

    void setMenu(const char* menuText);
    const char* getMenu() const;

    operator string() const override;
    void print() const; 

    friend ostream& operator<<(ostream& out, const WindowWithButton& w);
    friend istream& operator>>(istream& in, WindowWithButton& w);
};