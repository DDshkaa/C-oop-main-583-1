//! \brief ��������� ��� ���� ����������� ������
struct ListItem
{
	//! \brief ������ ����
	int Data;

	//! \brief ��������� �� ��������� ����
	ListItem* Next = nullptr;

	//! \brief ��������� �� ���������� ����     
	ListItem* Prev = nullptr;
};
