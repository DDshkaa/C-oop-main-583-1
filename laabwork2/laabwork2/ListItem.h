//! \brief Структура для узла двусвязного списка
struct Node 
{
    //! \brief Данные узла
    int data; 

    //! \brief Указатель на следующий узел
    Node* next;

    //! \brief Указатель на предыдущий узел     
    Node* prev;     
};

//! \brief Структура для двусвязного списка
struct List 
{
    //! \brief Указатель на первый узел
    Node* head;   
    
    //! \brief Указатель на последний узел
    Node* tail;     
};

