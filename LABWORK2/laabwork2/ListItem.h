//! \brief ��������� ��� ���� ����������� ������
struct Node 
{
    //! \brief ������ ����
    int Data; 

    //! \brief ��������� �� ��������� ����
    Node* Next;

    //! \brief ��������� �� ���������� ����     
    Node* Prev;     
};

//! \brief ��������� ��� ����������� ������
struct List 
{
    //! \brief ��������� �� ������ ����
    Node* Head;   
    
    //! \brief ��������� �� ��������� ����
    Node* Tail;
};

