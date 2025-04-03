#pragma once
#include "HashTableItem.h"
#include <string>

//! \brief Структура для представления хеш - таблицы.
struct HashTable
{
    //! \brief Указатель на массив указателей на элементы хеш-таблицы.
    HashTableItem** HashTable;

    //! \brief Общая емкость хеш-таблицы 
    int Capacity;

    //! \brief Текущий размер хеш-таблицы
    int CurrentSize;

    //! \brief Указатель на таблицу Пирсона, используемую для хеширования.
    int* PearsonTable;
};

//! \brief Начальный размер хеш-таблицы.
const int InitialSize = 8;

//! \brief Фактор заполняемости для роста хеш-таблицы.
const float factorial = 0.7;

//! \brief Фактор роста хеш-таблицы.
const int GrowthFactor = 2;

//! \brief Создает таблицу Пирсона для указанной емкости.
//! \param capacity Емкость хеш-таблицы, для которой создается таблица Пирсона.
//! \return Указатель на созданную таблицу Пирсона.
int* MakePearsonTable(int capacity);

//! \brief Вычисляет хеш-код для заданного ключа.
//! \param hashTable Ссылка на хеш-таблицу, в которой будет выполнено вычисление хеш-кода.
//! \param key Ключ, для которого необходимо вычислить хеш-код.
//! \param baseNum Базовое число для вычисления хеш-кода (по умолчанию 31).
//! \return Вычисленный хеш-код.
int GetHashCode(HashTable& hashTable, const std::string& key, int baseNum = 31);

//! \brief Создает новую хеш-таблицу.
//! \return Указатель на созданную хеш-таблицу.
HashTable* CreateHashTable();

//! \brief Перехеширует элементы в хеш-таблице.
//! \param hashTable Указатель на хеш-таблицу, которую необходимо перехешировать.
void Rehash(HashTable* hashTable);

//! \brief Добавляет элемент в хеш-таблицу.
//! \param hashTable Указатель на хеш-таблицу, в которую будет добавлен элемент.
//! \param key Ключ элемента, который нужно добавить.
//! \param value Значение элемента, которое нужно добавить.
void Add(HashTable* hashTable, const string& key, const string& value);

//! \brief Ищет значение по ключу в хеш-таблице.
//! \param hashTable Ссылка на хеш-таблицу, в которой будет выполнен поиск.
//! \param key Ключ элемента, который нужно найти.
//! \return Значение, связанное с ключом. Если ключ не найден, возвращает пустую строку.
string Search(HashTable& hashTable, const std::string& key);

//! \brief Удаляет элемент из хеш-таблицы по ключу.
//! \param hashTable Указатель на хеш-таблицу, из которой будет удален элемент.
//! \param key Ключ элемента, который нужно удалить.
void DeleteItem(HashTable* hashTable, const string& key);

//! \brief Освобождает память, занятую хеш-таблицей.
//! \param hashTable Указатель на хеш-таблицу, которую нужно удалить.
void DeleteHashTable(HashTable* hashTable);