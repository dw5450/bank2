#ifndef __BANK_H__


//#define ACCLIMITNUM 100
//#define NAMELIMITNUM 50


class acc {
private:
	const static int ACCLIMITNUM = 100;
	const static int NAMELIMITNUM = 50;
	char * name;
	int acc_num;
	int balance;

public:
	acc(char * _name, int _acc_num, int _balance);				//������ �̸�, ���¹�ȣ , �ܾ�
	acc(acc & _acc);											//���� ������
	acc();														//����Ʈ ������		
	~acc();														//�Ҹ���	
	char * return_name() const { return name; };
	int return_acc_num() const { return acc_num; };
	int return_balance() const { return balance; };
	void adj_balance(int adj_balance);							//�ܾ� ���� �Լ�
	void enter_info(char * _name, int _acc_num, int balance);	//���� ���� �Է� �Լ�
	void show_info() const ;											//�߰� ��� : ���� ���� ���
							
};

class nomal_acc : acc
{
private:
	double interest_ratio;

public:
	nomal_acc(char * _name, int _acc_num, int _balance, )acc()

};



class bank
{
private:
	acc * acc_arr;							//���� �迭
	int num_of_acc;							//������ ������ ��
	int cur_num_of_acc;						//���� ���¼�

public:
	bank(int _num_of_acc);								//������ 
	bank(bank&_bank);
	bank();												//����Ʈ ������
	~bank();											//�Ҹ���
	acc * return_acc_arr() const { return acc_arr; };
	int return_num_of_acc() const {return num_of_acc;};
	int return_cur_num_of_acc() const { return cur_num_of_acc; }
	void handle();				//�ڵ� �Լ�
	bool menu();				// ��� : �Ŵ�
	int search_acc();			//�߰� ��� : ���� ���� �˻�
	void make_acc();			// �⺻ ��� : ���� ����
	void deposit();				// �⺻ ��� : �Ա�
	void withdraw();			// �⺻ ��� : ���
	void show_all_acc_info() const;	// �⺻ ��� : ��� ���� ���� ���

};

//
//
#endif // !__BANK_H__
//#pragma once
