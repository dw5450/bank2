#include<iostream>
#include<Windows.h>
#include"Bank.h"
using namespace std;



// ���� Ŭ���� 

//������ �̸�, ���¹�ȣ , �ܾ�
acc::acc(char * _name, int _acc_num, int _balance) : acc_num(_acc_num), balance(_balance)
{
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}


acc::acc(acc & _acc) :acc_num(_acc.acc_num), balance(_acc.balance)
{
	name = new char[strlen(_acc.name) + 1];
	strcpy_s(name, strlen(_acc.name) + 1, _acc.name);
}
//����Ʈ ������		
acc::acc()
{
	name = NULL;
}

//���� ���� �Է� �Լ� , �̸�,���¹�ȣ,�ܾ� �Է�
void acc::enter_info(char * _name, int _acc_num, int _balance) {

	if (name == NULL) 
		name = new char[strlen(_name) + 1];
	
	strcpy_s(name, strlen(_name) + 1, _name);

	acc_num = _acc_num;
	balance = _balance;

}

//�ܾ� ���� �Լ�
void acc::adj_balance(int adj_balance) { balance = adj_balance; }

//�߰� ��� : ���� ���� ��� , �̸� ���¹�ȣ �ܾ� ���
void acc::show_info() const {
	cout << endl;
	cout << "�̸� : " << name << endl;
	cout << "���� ��ȣ : " << acc_num << endl;
	cout << "�ܾ� : " << balance << endl;
	cout << endl;

}

//�Ҹ���		���� ����
acc::~acc()
{
	delete[]name;
}




//���� Ŭ����

//������ , ������ �� ���¼�
bank::bank(int _num_of_acc) : num_of_acc(_num_of_acc), cur_num_of_acc(0)
{
	acc_arr = new acc[num_of_acc];
}

bank::bank(bank & _bank) : num_of_acc(_bank.num_of_acc), cur_num_of_acc(_bank.cur_num_of_acc)
{
	for (int i = 0; i < cur_num_of_acc; i++)
	{
		acc_arr[i] = _bank.acc_arr[i];
	}
}

//�Ҹ���
bank::~bank()
{
	delete[] acc_arr;
}

//���� �ڵ� ���α׷� // ���� ���α׷��� ��� �������� ���θ� ������,  ����� ��� menu ȣ��
void bank::handle()
{
	bool Do_bank = true;
	while (Do_bank) {
		cout << "���� ���α׷��� ���� �Ͻðڽ��ϱ�?" << endl;
		cout << " ���� : Y     ���� : N" << endl;
		char select;

		cin >> select;

		if (select == 'Y' || select == 'y' || select =='��') {
			system("cls");
			Do_bank = menu();
		}
		else if (select == 'N' || select == 'n' || select =='��' ){
			Do_bank = false;
		}
		else {
			cout << " �߸��� �Է��Դϴ�" << endl;
		}
	}
}

// �Ŵ� : �Ŵ� ���� ����, �Ա�, ���, ��ü ���� ��ȸ, ���α׷� ���� ,���α׷� ����� return false
bool bank::menu(){						
	int select = 0;

	cout << "���Ͻô� ����� ���� �� �ּ��� " << endl;
	cout << "���� ����	: 1 " << endl;
	cout << "��     ��	: 2 " << endl;
	cout << "��     ��	: 3" << endl;
	cout << "��ü ���� ��ȸ	: 4 " << endl;
	cout << "���α׷� ���� : 5" << endl;

	cin >> select;

	system("cls");

	if (select == 1) {
		make_acc();
	}
	else if (select == 2){
		deposit();
	}
	else if (select == 3) {
		withdraw();

	}
	else if (select == 4) {
		show_all_acc_info();
	}
	else if (select == 5){
		return false;
	}

	else {
		cout << "�߸��� �Է��Դϴ�. " << endl;
	}

	return true;
}

////�߰� ��� : ���� ���� �˻� , * return ������ ���� �迭 ��ġ ��ȯ, num_of_acc�Ͻ� �ش� ���� ���� x // ���� ���� �ʿ�
int bank::search_acc(){

	int search_acc_num;
	int finded_acc_arr_num;

	cout << "ã���� ������ ��ȣ�� �Է��� �ּ���" << endl;
	cin >> search_acc_num;

	
	for (finded_acc_arr_num = 0; finded_acc_arr_num < cur_num_of_acc; finded_acc_arr_num++){
		if (acc_arr[finded_acc_arr_num].return_acc_num()  == search_acc_num) {
			break;
		}
	}

	if (finded_acc_arr_num == num_of_acc){
		cout << "�ش� �� ���� ��ȣ�� �����ϴ�" << endl;
	}

	return finded_acc_arr_num;

}

//���� ����
void bank::make_acc()
{

	if (cur_num_of_acc < num_of_acc) {
		char name[40];
		int acc_num;
		int balance;
		cout << "�̸� �Է� " << endl;
		cin >> name;

		cout << "���¹�ȣ �Է� " << endl;
		cin >> acc_num;

		cout << "�ܾ� �Է�" << endl;
		cin >> balance;

		acc_arr[cur_num_of_acc].enter_info(name, acc_num, balance);

		cur_num_of_acc++;

		cout << "���°� ���� �Ǿ����ϴ�" << endl;
	}
	else {
		cout << "���¸� ���� �� �� �����ϴ�" << endl;
	}
	cout << endl;
}

// �⺻ ��� : �Ա�
void bank::deposit()
{
	int search_num = num_of_acc;
	char q_con = 'y';
	while (search_num == num_of_acc){
		cout << "���� ��ȣ�� ��ȸ �Ͻðڽ��ϱ�?" << endl;
		cout << "���� : Y     ���� : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == '��') {
			search_num = search_acc();

			if (search_num != num_of_acc) {
				cout << "�Ա��� �ݾ��� �Է��� �ּ��� " << endl;
				int deposit_money;
				cin >> deposit_money;
				int adj_money = acc_arr[search_num].return_balance() + deposit_money;
				acc_arr[search_num].adj_balance(adj_money);		//�Ա��ϱ�

				cout << "�Ա��� �Ϸ�Ǿ����ϴ�." << endl;
			}
			else {cout << " �߸��� �Է��Դϴ�" << endl;}
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == '��') {
			cout << "�Ա��� �����մϴ�";
			search_num = num_of_acc;
			break;
		}
		else {cout << " �߸��� �Է��Դϴ�" << endl;}
	}

}

//���	
void bank::withdraw()
{
	int search_num = num_of_acc;
	char q_con = 'y';
	while (search_num == num_of_acc) {
		cout << "���� ��ȣ�� ��ȸ �Ͻðڽ��ϱ�?" << endl;
		cout << "���� : Y     ���� : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == '��') {
			search_num = search_acc();

			if (search_num != num_of_acc) {
				cout << "����� �ݾ��� �Է��� �ּ��� " << endl;
				int deposit_money;
				cin >> deposit_money;
				int adj_money = acc_arr[search_num].return_balance() - deposit_money;
				acc_arr[search_num].adj_balance(adj_money);		//�Ա��ϱ�

				cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
			}
			else { cout << " �߸��� �Է��Դϴ�" << endl; }
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == '��') {
			cout << "����� �����մϴ�";
			search_num = num_of_acc;
			break;
		}
		else { cout << " �߸��� �Է��Դϴ�" << endl; }
	}

}// �⺻ ��� : ���, ���̳ʽ� ���� ����

//��� ���� ��ȸ
void bank::show_all_acc_info()const
{
	for (int i = 0; i < cur_num_of_acc; i++) {
		acc_arr[i].show_info();
	}
}// �⺻ ��� : ��� ���� ���� ���