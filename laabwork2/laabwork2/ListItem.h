//! \brief ��������� ��� ���� ����������� ������
struct Node 
{
    //! \brief ������ ����
    int data; 

    //! \brief ��������� �� ��������� ����
    Node* next;

    //! \brief ��������� �� ���������� ����     
    Node* prev;     
};

//! \brief ��������� ��� ����������� ������
struct List 
{
    //! \brief ��������� �� ������ ����
    Node* head;   
    
    //! \brief ��������� �� ��������� ����
    Node* tail;     
};

