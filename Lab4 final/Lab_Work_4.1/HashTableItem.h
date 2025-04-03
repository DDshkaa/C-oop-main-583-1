#pragma once
#include <string>
using namespace std;

//! \brief Структура для представления элемента хеш-таблицы.
struct HashTableItem
{
    //! \brief Ключ элемента, используемый для хеширования.
    string Key;

    //! \brief Значение, связанное с ключом.
    string Value;

    //! \brief  Указатель на следующий элемент в цепочке.
    HashTableItem* Next;
    
    //! \brief Конструктор для создания нового элемента хеш-таблицы.
    //! \param key Ключ элемента, который будет добавлен в хеш-таблицу.
    //! \param value Значение, связанное с указанным ключом.
    HashTableItem(const string& key, const string& value) : Key(key), Value(value), Next(nullptr) {};
};
