#include<iostream>
#include<Windows.h>
#include"Bank.h"
using namespace std;



//기초  계좌 클래스 

//생성자 이름, 계좌번호 , 잔액
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
//디폴트 생성자		
acc::acc()
{
	name = NULL;
}

//계좌 정보 입력 함수 , 이름,계좌번호,잔액 입력
void acc::AdjInfo(char * name, int accNum, int balance) {

	if (name == NULL) 
		name = new char[strlen(name) + 1];
	
	strcpy_s(name, strlen(name) + 1, name);

	accNum = accNum;
	balance = balance;

}

//잔액 조정 함수
void acc::AdjBalance(int abalance) { this->balance = balance; }

//추가 기능 : 계좌 정보 출력 , 이름 계좌번호 잔액 출력
void acc::ShowInfo() const {
	cout << "이름 : " << name << endl;
	cout << "계좌 번호 : " << accNum << endl;
	cout << "잔액 : " << balance << endl;
}

//소멸자		네임 삭제
acc::~acc()
{
	delete[]name;
}








//saving_acc 클레스

//saving_acc 생성자
saving_acc::saving_acc(char * name, int accNum , int balance, double interestRatio) 
	: acc(name, accNum, balance), interestRatio(interestRatio) {}

void saving_acc::ShowInfo() const 
{
	acc::ShowInfo();
	cout << "이자 비율 : " << interestRatio << endl;
}










//credit_acc클레스

credit_acc::credit_acc(char * name, int accNum, int balance, double interestRatio, int CreditLevel)
	: saving_acc(name, accNum, balance, interestRatio), CreditLevel(CreditLevel) {}

void credit_acc::ShowInfo() const
{
	saving_acc::ShowInfo();
	cout << "신용 등급 : " << CreditLevel << endl;
}
//
////은행 클래스







/*
class 유형 : contral

class 설명 : 은행 기능 함수

*/



//생성자
acc_handler::acc_handler() : accArrNum(0) {}


//소멸자
acc_handler::~acc_handler()
{
	for (int i = 0; i< accArrNum; i++)
	{
		delete[] accArr[i];
	}
}

//계좌 배열 위치 검색 
int acc_handler::SearchAccArrNum()
{
	int SearchAccNum;
	cout << "찾으실 계좌 번호를 입력해 주세요" << endl;
	cin >> SearchAccNum;

	for (int i = 0; i < accArrNum; i++){
		if (accArr[i]->GetAccNum() == SearchAccNum) {
			return i;
		}}

	return -1;
}

//계좌 추가
void acc_handler::AddAcc(acc * acc)
{
	accArr[accArrNum++] = acc;
}


//메뉴 함수
bool acc_handler::Menu(){
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
		cout << "잘못된 입력입니다. " << endl;
	}

	return true;
}

//계좌 생성
void acc_handler::MakeAcc()
{
	int choiceAccType;
	char name[100];
	int accNum;
	int balance;
	double interestRatio;
	int CreditLevel;

	cout << "[계좌 종류 선택]" << endl;
	cout << " 1. 보통예금계좌    2. 신용예금계좌" << endl;
	cout << "선택 : ";
	cin >> choiceAccType;

	if (choiceAccType == 1)
	{
		cout << "[보통예금계좌 생성]" << endl;
		cout << "이			름 : ";	cin >> name;
		cout << "계	좌	번	호 :";	cin >> accNum;
		cout << "잔			액 : ";	cin >> balance;
		cout << "이	자	 비	율 :";	cin >> interestRatio;
		saving_acc * savingAcc = new saving_acc(name, accNum, balance, interestRatio);
		AddAcc(savingAcc);
	}

	else if(choiceAccType == 2)
	{
		cout << "[신용예금계좌 생성]" << endl;
		cout << "이			름 : ";		cin >> name;
		cout << "계	좌	번	호 :";		cin >> accNum;
		cout << "잔			액 : ";		cin >> balance;
		cout << "이	자	 비	율 :";		cin >> interestRatio;
		cout << "신	용	등	급"			<< endl;
		cout << "(1toA, 2toB, 3toC) : "; cin >> CreditLevel;
		credit_acc * creditAcc = new credit_acc(name, accNum, balance, interestRatio, CreditLevel);
		AddAcc(creditAcc);
	}

	
	else
	{
		cout << "잘못된 입력 입니다";
	}


}


//입금
void acc_handler::Deposit()
{
	int accArrNum = SearchAccArrNum();

	if (accArrNum != -1)
	{
		int depositMoney;
		cout << "입금하실 금액을 입력 해 주세요 : ";	 cin >> depositMoney;
		accArr[accArrNum]->AdjBalance(accArr[accArrNum]->GetBalance() + depositMoney);				//입금
	}
	else
		cout << "잘못된 입력입니다" << endl;
}

//출금
void acc_handler::Withdraw()
{
	int accArrNum = SearchAccArrNum();

	if (accArrNum != -1)
	{
		int withdrawMoney;
		cout << "출금하실 금액을 입력 해 주세요 : ";	 cin >> withdrawMoney;
		accArr[accArrNum]->AdjBalance(accArr[accArrNum]->GetBalance() - withdrawMoney);				//입금
	}
	else
		cout << "잘못된 입력입니다" << endl;
}


//모든 계좌 정보 출력 
void acc_handler::ShowAllAccInfo() const
{
	for (int i = 0; i < accArrNum; i++)
	{
		accArr[i]->ShowInfo();
	}
}



