#pragma once
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//! \brief �������� ������������� ���� �� ������������.
//! \param prompt ���������, ������� ����� �������� �� ����� ��� ������� ����� � ������������.
//! \return ��������� ������������� ����� �����.
int GetIntInput(const string& prompt);


//! \brief �������� ��������� ���� �� ������������.
//! \param text ���������, ������� ����� �������� �� ����� ��� ������� ����� � ������������.
//! \return ��������� ������������� ������.
string GetStringInput(const string& text);