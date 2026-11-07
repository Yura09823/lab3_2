#include <iostream>
#include <Windows.h>
#include "WindowWithButton.h"

using namespace std;

Window processWindow(Window w) {
    cout << "Обробляється об'єкт базового класу: " << string(w) << endl;
    w.setX(w.getX() + 10);
    w.setY(w.getY() + 10);
    return w;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Button btn(50, 25);
    cout << "Кнопка: " << string(btn) << endl;

    Window baseWindow(btn, 100, 150);
    cout << "Базове вікно: " << baseWindow << endl;

    WindowWithButton advancedWindow(btn, 200, 300, "Файл | Редагувати | Довідка");
    cout << "Розширене вікно: ";
    advancedWindow.print();

    Window returnedWindow = processWindow(advancedWindow);
    cout << "Повернено модифікований базовий об'єкт: " << returnedWindow << endl;

    WindowWithButton* arr = new WindowWithButton[2];
    arr[0] = WindowWithButton(Button(120, 40), 10, 10, "Головне меню");
    arr[1] = WindowWithButton(Button(80, 30), 50, 50, "Налаштування");

    for (int i = 0; i < 2; i++) {
        cout << "Масив [" << i << "]: " << arr[i] << endl;
    }
    delete[] arr;

    WindowWithButton customWindow;
    cout << "Створення вікна з клавіатури:" << endl;
    cin >> customWindow;
    cout << "\nВи ввели: " << customWindow << endl;

    return 0;
}