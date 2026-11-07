#define _CRT_SECURE_NO_WARNINGS
#include "WindowWithButton.h"
#include <cstring>
#include <sstream>
#include <cstdlib>

using namespace std;

WindowWithButton::WindowWithButton() : Window(), menu(nullptr) {
    setMenu("Default Menu");
}

WindowWithButton::WindowWithButton(const Button& btn, int xCoord, int yCoord, const char* menuText)
    : Window(btn, xCoord, yCoord), menu(nullptr) {
    setMenu(menuText);
}

WindowWithButton::WindowWithButton(const WindowWithButton& other)
    : Window(other), menu(nullptr) {
    setMenu(other.menu);
}

WindowWithButton& WindowWithButton::operator=(const WindowWithButton& other) {
    if (this != &other) {
        Window::operator=(other);
        setMenu(other.menu);
    }
    return *this;
}

WindowWithButton::~WindowWithButton() {
    delete[] menu; 
}

void WindowWithButton::setMenu(const char* menuText) {
    if (!menuText || strlen(menuText) == 0) {
        cerr << "Помилка: Рядок меню не може бути порожнім!" << endl;
        exit(1);
    }
    delete[] menu;
    menu = new char[strlen(menuText) + 1];
    strcpy(menu, menuText);
}

const char* WindowWithButton::getMenu() const {
    return menu;
}

WindowWithButton::operator string() const {
    stringstream ss;
    ss << Window::operator string() << " | Меню: [" << (menu ? menu : "порожньо") << "]";
    return ss.str();
}

void WindowWithButton::print() const {
    cout << static_cast<string>(*this) << endl;
}

ostream& operator<<(ostream& out, const WindowWithButton& w) {
    out << static_cast<string>(w);
    return out;
}

istream& operator>>(istream& in, WindowWithButton& w) {
    in >> static_cast<Window&>(w);

    cout << "Введіть текст меню: ";
    char buffer[256];
    in.ignore(); 
    in.getline(buffer, 256);
    w.setMenu(buffer);

    return in;
}