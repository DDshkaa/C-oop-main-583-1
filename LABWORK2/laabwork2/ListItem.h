//! \brief Структура для узла двусвязного списка
struct Node 
{
    //! \brief Данные узла
    int Data; 

    //! \brief Указатель на следующий узел
    Node* Next;

    //! \brief Указатель на предыдущий узел     
    Node* Prev;     
};

//! \brief Структура для двусвязного списка
struct List 
{
    //! \brief Указатель на первый узел
    Node* Head;   
    
    //! \brief Указатель на последний узел
    Node* Tail;
};

