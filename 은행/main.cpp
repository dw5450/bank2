#include <iostream>
#include"Bank.h"
using namespace std;


int main()
{
	////���� �ڵ� ���α׷� // ���� ���α׷��� ��� �������� ���θ� ������,  ����� ��� menu ȣ��
	acc_handler accHandle;

	bool Do_bank = true;
	while (Do_bank) {
		cout << "���� ���α׷��� ���� �Ͻðڽ��ϱ�?" << endl;
		cout << " ���� : Y     ���� : N" << endl;
		char select;

		cin >> select;

		if (select == 'Y' || select == 'y' || select == '��') {
			system("cls");
			Do_bank = accHandle.Menu();
		}
		else if (select == 'N' || select == 'n' || select == '��') {
			Do_bank = false;
		}
		else {
			cout << " �߸��� �Է��Դϴ�" << endl;
		}
	}

}
