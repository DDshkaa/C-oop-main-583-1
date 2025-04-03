#pragma once
#include "HashTable.h"
#include "HashTableItem.h"

//! \brief Структура, представляющая словарь, реализованная с помощью хэш-таблицы.
struct Dictionary
{
	//! \brief Указатель на хеш-таблицу, используемую для хранения данных.
	HashTable* HashTable;
};


//! \brief Создает новый словарь.
Dictionary* CreateDictionary();

//! \brief Вставляет новую пару "ключ-значение" в словарь.
//! \param dictionary Указатель на словарь, в который будет добавлена пара.
//! \param key Ключ, по которому будет осуществляться доступ к значению.
//! \param value Значение, связанное с указанным ключом.
void Insert(Dictionary* dictionary, const string& key, const string& value);

//! \brief Находит значение по указанному ключу.
//! \param dictionary Указатель на словарь, в котором нужно выполнить поиск.
//! \param key Ключ, по которому выполняется поиск значения.
//! \return Значение, связанное с указанным ключом или пустая строка, если ключ не найден.
string Find(Dictionary* dictionary, const string& key);

//! \brief Удаляет пару "ключ-значение" из словаря
//! \param dictionary Указатель на словарь, из которого нужно удалить пару.
//! \param key Ключ, который нужно удалить из словаря.
void Remove(Dictionary* dictionary, const string& key);

//! \brief Освобождает память, занятую словарем.
//! \param dictionary Указатель на словарь, который нужно удалить.
void DeleteDictionary(Dictionary* dictionary);
