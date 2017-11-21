#ifndef __BANK_H__


//#define ACCLIMITNUM 100
//#define NAMELIMITNUM 50

/*
class ���� : entity 

class ���� :���� ���� Ŭ����

*/
class acc {
private:
	const static int ACCLIMITNUM = 100;
	const static int NAMELIMITNUM = 50;
	char * name;												//�̸�
	int accNum;													//���¹�ȣ
	int balance;												//�ܾ�

public:
	acc(char * name, int accNum, int balance);					//������ �̸�, ���¹�ȣ , �ܾ�
	acc(acc & acc);												//���� ������
	acc();														//����Ʈ ������		
	~acc();														//�Ҹ���	
	char * GetName() const { return name; };					//�̸� ��������
	int GetAccNum() const { return accNum; };					//���� ��ȣ ��������
	int GetBalance() const { return balance; };					//�ܾ� ��������
	void AdjBalance(int adjBalance);							//�ܾ� ���� �Լ�
	void AdjInfo(char * _name, int _acc_num, int balance);		//���� ���� ���� �Լ�
	virtual void ShowInfo() const ;								//�߰� ��� : ���� ���� ���
							
};

/*
class ���� : entity

class ���� : ���� ���� ���� 

			acc�� ���� Ŭ���� 
*/

class saving_acc : public acc
{
private:
	double interestRatio;

public:
	saving_acc(char * name, int accNum, int balance, double interestRatio);
	virtual void ShowInfo() const;

};

/*
class ���� : entity

class ���� : �ſ� ���� ����

saving_acc�� ���� Ŭ����
*/


namespace CREDITLAEVEL
{
	enum
	{
		A = 1,
		B = 2,
		C = 3
	};
}

class credit_acc : public saving_acc
{
private:
	int CreditLevel;

public:
	credit_acc(char * name, int accNum, int balance, double interestRatio, int CreditLevel);
	virtual void ShowInfo() const;

};


/*
class ���� : contral

class ���� : ���� ��� �Լ�

*/




#define ACCARRLIMIT 100
class acc_handler
{
private:
	acc * accArr[ACCARRLIMIT];						//���� �迭
	int accArrNum;										//���� ����
	

public:
	acc_handler();											//������ 
	~acc_handler();											//�Ҹ���
	int SearchAccArrNum();									//�߰� ��� : ���� �迭 ��ġ �˻�
	void AddAcc(acc * acc);									//�߰� ��� : ���� �迭�� ���� �߰�
	bool Menu();											// ��� : �Ŵ�
	void MakeAcc();											// �⺻ ��� : ���� ����
	void Deposit();											// �⺻ ��� : �Ա�
	void Withdraw();										// �⺻ ��� : ���
	void ShowAllAccInfo() const;							// �⺻ ��� : ��� ���� ���� ���

};

//
//
#endif // !__BANK_H__
//#pragma once
