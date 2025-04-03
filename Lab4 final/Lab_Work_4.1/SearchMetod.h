#pragma once
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//! \brief Получает целочисленный ввод от пользователя.
//! \param prompt Сообщение, которое будет выведено на экран для запроса ввода у пользователя.
//! \return Введенное пользователем целое число.
int GetIntInput(const string& prompt);


//! \brief Получает строковый ввод от пользователя.
//! \param text Сообщение, которое будет выведено на экран для запроса ввода у пользователя.
//! \return Введенная пользователем строка.
string GetStringInput(const string& text);