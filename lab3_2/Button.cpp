#include "Button.h"
#include <sstream>
#include <cstdlib>

using namespace std;

Button::Button() {
    setWidth(10);
    setHeight(10);
}

Button::Button(int w, int h) {
    setWidth(w);
    setHeight(h);
}

void Button::setWidth(int w) {
    if (w <= 0) {
        cerr << "Помилка: Ширина кнопки має бути більшою за 0!" << endl;
        exit(1);
    }
    width = w;
}

void Button::setHeight(int h) {
    if (h <= 0) {
        cerr << "Помилка: Висота кнопки має бути більшою за 0!" << endl;
        exit(1);
    }
    height = h;
}

int Button::getWidth() const { return width; }
int Button::getHeight() const { return height; }

Button::operator string() const {
    stringstream ss;
    ss << "[Кнопка: " << width << "x" << height << "]";
    return ss.str();
}

ostream& operator<<(ostream& out, const Button& b) {
    out << static_cast<string>(b);
    return out;
}

istream& operator>>(istream& in, Button& b) {
    int w, h;
    cout << "Введіть ширину кнопки: ";
    in >> w;
    cout << "Введіть висоту кнопки: ";
    in >> h;
    b.setWidth(w);
    b.setHeight(h);
    return in;
}