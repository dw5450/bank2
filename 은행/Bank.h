#ifndef __BANK_H__


#define ACCLIMITNUM 100
#define NAMELIMITNUM 50


class acc {
private:
	char * name;
	int acc_num;
	int balance;

public:
	acc(char * _name, int _acc_num, int _balance);				//생성자 이름, 계좌번호 , 잔액
	acc();														//디폴트 생성자		
	~acc();														//소멸자	
	char * return_name() { return name; };					
	int return_acc_num() { return acc_num; };
	int return_balance() { return balance; };
	void adj_balance(int adj_balance);
	void enter_info(char * _name, int _acc_num, int balance);	//계좌 정보 입력 함수
	void show_info();											//추가 기능 : 계좌 정보 출력
							
};



class bank
{
private:
	acc * acc_arr;							//계좌 배열
	int num_of_acc;							//가능한 계좌의 수
	int cur_num_of_acc;						//현재 계좌수

public:
	bank(int _num_of_acc);								//생성자 
	bank();												//디폴트 생성자
	~bank();											//소멸자
	acc * return_acc_arr() { return acc_arr; };
	int return_num_of_acc() {return num_of_acc;};
	int return_cur_num_of_acc() { return cur_num_of_acc; }
	void handle();				//핸들 함수
	bool menu();				// 기능 : 매뉴
	int search_acc();			//추가 기능 : 계좌 정보 검색
	void make_acc();			// 기본 기능 : 계좌 생성
	void deposit();				// 기본 기능 : 입금
	void withdraw();			// 기본 기능 : 출금
	void show_all_acc_info();		// 기본 기능 : 모든 계좌 정보 출력

};

//
//
#endif // !__BANK_H__
//#pragma once
