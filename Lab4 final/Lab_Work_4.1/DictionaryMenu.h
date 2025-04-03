#pragma once
#include "Dictionary.h"

//! \brief ќтображает элементы словар€.
//! \param dictionary ”казатель на экземпл€р Dictionary, который будет отображен.
void DisplayDictionary(const Dictionary* dictionary);

//! \brief ћеню дл€ работы со словарЄм.
//! \param dictionary ”казатель на экземпл€р Dictionary, с которым будет работать меню.
void DictionaryMenu(Dictionary* dictionary);