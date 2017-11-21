#include<iostream>
#include<Windows.h>
#include"Bank.h"
using namespace std;



//����  ���� Ŭ���� 

//������ �̸�, ���¹�ȣ , �ܾ�
acc::acc(char * name, int accNum, int balance) : accNum(accNum), balance(balance)
{
	this ->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}


acc::acc(acc & acc) :accNum(acc.accNum), balance(acc.balance)
{
	name = new char[strlen(acc.name) + 1];
	strcpy_s(name, strlen(acc.name) + 1, acc.name);
}
//����Ʈ ������		
acc::acc()
{
	name = NULL;
}

//���� ���� �Է� �Լ� , �̸�,���¹�ȣ,�ܾ� �Է�
void acc::AdjInfo(char * name, int accNum, int balance) {

	if (name == NULL) 
		name = new char[strlen(name) + 1];
	
	strcpy_s(name, strlen(name) + 1, name);

	accNum = accNum;
	balance = balance;

}

//�ܾ� ���� �Լ�
void acc::AdjBalance(int abalance) { this->balance = balance; }

//�߰� ��� : ���� ���� ��� , �̸� ���¹�ȣ �ܾ� ���
void acc::ShowInfo() const {
	cout << "�̸� : " << name << endl;
	cout << "���� ��ȣ : " << accNum << endl;
	cout << "�ܾ� : " << balance << endl;
}

//�Ҹ���		���� ����
acc::~acc()
{
	delete[]name;
}








//saving_acc Ŭ����

//saving_acc ������
saving_acc::saving_acc(char * name, int accNum , int balance, double interestRatio) 
	: acc(name, accNum, balance), interestRatio(interestRatio) {}

void saving_acc::ShowInfo() const 
{
	acc::ShowInfo();
	cout << "���� ���� : " << interestRatio << endl;
}










//credit_accŬ����

credit_acc::credit_acc(char * name, int accNum, int balance, double interestRatio, int CreditLevel)
	: saving_acc(name, accNum, balance, interestRatio), CreditLevel(CreditLevel) {}

void credit_acc::ShowInfo() const
{
	saving_acc::ShowInfo();
	cout << "�ſ� ��� : " << CreditLevel << endl;
}
//
////���� Ŭ����







/*
class ���� : contral

class ���� : ���� ��� �Լ�

*/



//������
acc_handler::acc_handler() : accArrNum(0) {}


//�Ҹ���
acc_handler::~acc_handler()
{
	for (int i = 0; i< accArrNum; i++)
	{
		delete[] accArr[i];
	}
}

//���� �迭 ��ġ �˻� 
int acc_handler::SearchAccArrNum()
{
	int SearchAccNum;
	cout << "ã���� ���� ��ȣ�� �Է��� �ּ���" << endl;
	cin >> SearchAccNum;

	for (int i = 0; i < accArrNum; i++){
		if (accArr[i]->GetAccNum() == SearchAccNum) {
			return i;
		}}

	return -1;
}

//���� �߰�
void acc_handler::AddAcc(acc * acc)
{
	accArr[accArrNum++] = acc;
}


//�޴� �Լ�
bool acc_handler::Menu(){
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
		MakeAcc();
	}
	else if (select == 2){
		Deposit();
	}
	else if (select == 3) {
		Withdraw();

	}
	else if (select == 4) {
		ShowAllAccInfo();
	}
	else if (select == 5){
		return false;
	}

	else {
		cout << "�߸��� �Է��Դϴ�. " << endl;
	}

	return true;
}

//���� ����
void acc_handler::MakeAcc()
{
	int choiceAccType;
	char name[100];
	int accNum;
	int balance;
	double interestRatio;
	int CreditLevel;

	cout << "[���� ���� ����]" << endl;
	cout << " 1. ���뿹�ݰ���    2. �ſ뿹�ݰ���" << endl;
	cout << "���� : ";
	cin >> choiceAccType;

	if (choiceAccType == 1)
	{
		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "��			�� : ";	cin >> name;
		cout << "��	��	��	ȣ :";	cin >> accNum;
		cout << "��			�� : ";	cin >> balance;
		cout << "��	��	 ��	�� :";	cin >> interestRatio;
		saving_acc * savingAcc = new saving_acc(name, accNum, balance, interestRatio);
		AddAcc(savingAcc);
	}

	else if(choiceAccType == 2)
	{
		cout << "[�ſ뿹�ݰ��� ����]" << endl;
		cout << "��			�� : ";		cin >> name;
		cout << "��	��	��	ȣ :";		cin >> accNum;
		cout << "��			�� : ";		cin >> balance;
		cout << "��	��	 ��	�� :";		cin >> interestRatio;
		cout << "��	��	��	��"			<< endl;
		cout << "(1toA, 2toB, 3toC) : "; cin >> CreditLevel;
		credit_acc * creditAcc = new credit_acc(name, accNum, balance, interestRatio, CreditLevel);
		AddAcc(creditAcc);
	}

	
	else
	{
		cout << "�߸��� �Է� �Դϴ�";
	}


}


//�Ա�
void acc_handler::Deposit()
{
	int accArrNum = SearchAccArrNum();

	if (accArrNum != -1)
	{
		int depositMoney;
		cout << "�Ա��Ͻ� �ݾ��� �Է� �� �ּ��� : ";	 cin >> depositMoney;
		accArr[accArrNum]->AdjBalance(accArr[accArrNum]->GetBalance() + depositMoney);				//�Ա�
	}
	else
		cout << "�߸��� �Է��Դϴ�" << endl;
}

//���
void acc_handler::Withdraw()
{
	int accArrNum = SearchAccArrNum();

	if (accArrNum != -1)
	{
		int withdrawMoney;
		cout << "����Ͻ� �ݾ��� �Է� �� �ּ��� : ";	 cin >> withdrawMoney;
		accArr[accArrNum]->AdjBalance(accArr[accArrNum]->GetBalance() - withdrawMoney);				//�Ա�
	}
	else
		cout << "�߸��� �Է��Դϴ�" << endl;
}


//��� ���� ���� ��� 
void acc_handler::ShowAllAccInfo() const
{
	for (int i = 0; i < accArrNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}



