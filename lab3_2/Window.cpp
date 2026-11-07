#include "Window.h"
#include <sstream>
#include <cstdlib>

using namespace std;

Window::Window() {
    setButton(Button());
    setX(0);
    setY(0);
}

Window::Window(const Button& btn, int xCoord, int yCoord) {
    setButton(btn);
    setX(xCoord);
    setY(yCoord);
}

Window::~Window() {}

void Window::setButton(const Button& btn) {
    button = btn;
}

void Window::setX(int xCoord) {
    if (xCoord < 0) {
        cerr << "Помилка: Координата X вікна не може бути від'ємною!" << endl;
        exit(1);
    }
    x = xCoord;
}

void Window::setY(int yCoord) {
    if (yCoord < 0) {
        cerr << "Помилка: Координата Y вікна не може бути від'ємною!" << endl;
        exit(1);
    }
    y = yCoord;
}

Button Window::getButton() const { return button; }
int Window::getX() const { return x; }
int Window::getY() const { return y; }

Window::operator string() const {
    stringstream ss;
    ss << "Вікно на координатах (" << x << ", " << y << ") містить " << string(button);
    return ss.str();
}

ostream& operator<<(ostream& out, const Window& w) {
    out << static_cast<string>(w);
    return out;
}

istream& operator>>(istream& in, Window& w) {
    Button btn;
    int newX, newY;
    in >> btn;
    cout << "Введіть координату X вікна: ";
    in >> newX;
    cout << "Введіть координату Y вікна: ";
    in >> newY;

    w.setButton(btn);
    w.setX(newX);
    w.setY(newY);
    return in;
}