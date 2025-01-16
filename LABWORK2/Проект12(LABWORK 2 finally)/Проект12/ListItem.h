//! \brief Структура для узла двусвязного списка
struct ListItem
{
	//! \brief Данные узла
	int Data;

	//! \brief Указатель на следующий узел
	ListItem* Next = nullptr;

	//! \brief Указатель на предыдущий узел     
	ListItem* Prev = nullptr;
};
