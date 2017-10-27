#include<iostream>
#include<Windows.h>
#include"Bank.h"
using namespace std;



// 계좌 클래스 

//생성자 이름, 계좌번호 , 잔액
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
//디폴트 생성자		
acc::acc()
{
	name = NULL;
}

//계좌 정보 입력 함수 , 이름,계좌번호,잔액 입력
void acc::enter_info(char * _name, int _acc_num, int _balance) {

	if (name == NULL) 
		name = new char[strlen(_name) + 1];
	
	strcpy_s(name, strlen(_name) + 1, _name);

	acc_num = _acc_num;
	balance = _balance;

}

//잔액 조정 함수
void acc::adj_balance(int adj_balance) { balance = adj_balance; }

//추가 기능 : 계좌 정보 출력 , 이름 계좌번호 잔액 출력
void acc::show_info() const {
	cout << endl;
	cout << "이름 : " << name << endl;
	cout << "계좌 번호 : " << acc_num << endl;
	cout << "잔액 : " << balance << endl;
	cout << endl;

}

//소멸자		네임 삭제
acc::~acc()
{
	delete[]name;
}




//은행 클래스

//생성자 , 가능한 총 계좌수
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

//소멸자
bank::~bank()
{
	delete[] acc_arr;
}

//은행 핸들 프로그램 // 은행 프로그램을 계속 진행할지 여부를 물어줌,  진행시 계속 menu 호출
void bank::handle()
{
	bool Do_bank = true;
	while (Do_bank) {
		cout << "은행 프로그램을 실행 하시겠습니까?" << endl;
		cout << " 진행 : Y     종료 : N" << endl;
		char select;

		cin >> select;

		if (select == 'Y' || select == 'y' || select =='ㅛ') {
			system("cls");
			Do_bank = menu();
		}
		else if (select == 'N' || select == 'n' || select =='ㅜ' ){
			Do_bank = false;
		}
		else {
			cout << " 잘못된 입력입니다" << endl;
		}
	}
}

// 매뉴 : 매뉴 계좌 생성, 입금, 출금, 전체 계좌 조회, 프로그램 종료 ,프로그램 종료시 return false
bool bank::menu(){						
	int select = 0;

	cout << "원하시는 기능을 선택 해 주세요 " << endl;
	cout << "계좌 생성	: 1 " << endl;
	cout << "입     금	: 2 " << endl;
	cout << "출     금	: 3" << endl;
	cout << "전체 계좌 조회	: 4 " << endl;
	cout << "프로그램 종료 : 5" << endl;

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
		cout << "잘못된 입력입니다. " << endl;
	}

	return true;
}

////추가 기능 : 계좌 정보 검색 , * return 값으로 계좌 배열 위치 반환, num_of_acc일시 해당 계좌 존재 x // 추후 수정 필요
int bank::search_acc(){

	int search_acc_num;
	int finded_acc_arr_num;

	cout << "찾으실 계좌의 번호를 입력해 주세요" << endl;
	cin >> search_acc_num;

	
	for (finded_acc_arr_num = 0; finded_acc_arr_num < cur_num_of_acc; finded_acc_arr_num++){
		if (acc_arr[finded_acc_arr_num].return_acc_num()  == search_acc_num) {
			break;
		}
	}

	if (finded_acc_arr_num == num_of_acc){
		cout << "해당 된 계좌 번호가 없습니다" << endl;
	}

	return finded_acc_arr_num;

}

//계좌 생성
void bank::make_acc()
{

	if (cur_num_of_acc < num_of_acc) {
		char name[40];
		int acc_num;
		int balance;
		cout << "이름 입력 " << endl;
		cin >> name;

		cout << "계좌번호 입력 " << endl;
		cin >> acc_num;

		cout << "잔액 입력" << endl;
		cin >> balance;

		acc_arr[cur_num_of_acc].enter_info(name, acc_num, balance);

		cur_num_of_acc++;

		cout << "계좌가 생성 되었습니다" << endl;
	}
	else {
		cout << "계좌를 생성 할 수 없습니다" << endl;
	}
	cout << endl;
}

// 기본 기능 : 입금
void bank::deposit()
{
	int search_num = num_of_acc;
	char q_con = 'y';
	while (search_num == num_of_acc){
		cout << "계좌 번호를 조회 하시겠습니까?" << endl;
		cout << "진행 : Y     종료 : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == 'ㅛ') {
			search_num = search_acc();

			if (search_num != num_of_acc) {
				cout << "입금할 금액을 입력해 주세요 " << endl;
				int deposit_money;
				cin >> deposit_money;
				int adj_money = acc_arr[search_num].return_balance() + deposit_money;
				acc_arr[search_num].adj_balance(adj_money);		//입금하기

				cout << "입금이 완료되었습니다." << endl;
			}
			else {cout << " 잘못된 입력입니다" << endl;}
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == 'ㅜ') {
			cout << "입금을 종료합니다";
			search_num = num_of_acc;
			break;
		}
		else {cout << " 잘못된 입력입니다" << endl;}
	}

}

//출금	
void bank::withdraw()
{
	int search_num = num_of_acc;
	char q_con = 'y';
	while (search_num == num_of_acc) {
		cout << "계좌 번호를 조회 하시겠습니까?" << endl;
		cout << "진행 : Y     종료 : N" << endl;
		cin >> q_con;

		if (q_con == 'Y' || q_con == 'y' || q_con == 'ㅛ') {
			search_num = search_acc();

			if (search_num != num_of_acc) {
				cout << "출금할 금액을 입력해 주세요 " << endl;
				int deposit_money;
				cin >> deposit_money;
				int adj_money = acc_arr[search_num].return_balance() - deposit_money;
				acc_arr[search_num].adj_balance(adj_money);		//입금하기

				cout << "출금이 완료되었습니다." << endl;
			}
			else { cout << " 잘못된 입력입니다" << endl; }
		}
		else if (q_con == 'N' || q_con == 'n' || q_con == 'ㅜ') {
			cout << "출금을 종료합니다";
			search_num = num_of_acc;
			break;
		}
		else { cout << " 잘못된 입력입니다" << endl; }
	}

}// 기본 기능 : 출금, 마이너스 통장 가능

//모든 정보 조회
void bank::show_all_acc_info()const
{
	for (int i = 0; i < cur_num_of_acc; i++) {
		acc_arr[i].show_info();
	}
}// 기본 기능 : 모든 계좌 정보 출력