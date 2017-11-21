#ifndef __BANK_H__


//#define ACCLIMITNUM 100
//#define NAMELIMITNUM 50

/*
class 유형 : entity 

class 설명 :기초 계좌 클레스

*/
class acc {
private:
	const static int ACCLIMITNUM = 100;
	const static int NAMELIMITNUM = 50;
	char * name;												//이름
	int accNum;													//계좌번호
	int balance;												//잔액

public:
	acc(char * name, int accNum, int balance);					//생성자 이름, 계좌번호 , 잔액
	acc(acc & acc);												//복사 생성자
	acc();														//디폴트 생성자		
	~acc();														//소멸자	
	char * GetName() const { return name; };					//이름 가져오기
	int GetAccNum() const { return accNum; };					//계좌 번호 가져오기
	int GetBalance() const { return balance; };					//잔액 가져오기
	void AdjBalance(int adjBalance);							//잔액 조정 함수
	void AdjInfo(char * _name, int _acc_num, int balance);		//계좌 정보 조정 함수
	virtual void ShowInfo() const ;								//추가 기능 : 계좌 정보 출력
							
};

/*
class 유형 : entity

class 설명 : 보통 예금 계좌 

			acc의 유도 클레스 
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
class 유형 : entity

class 설명 : 신용 예금 계좌

saving_acc의 유도 클레스
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
class 유형 : contral

class 설명 : 은행 기능 함수

*/




#define ACCARRLIMIT 100
class acc_handler
{
private:
	acc * accArr[ACCARRLIMIT];						//계좌 배열
	int accArrNum;										//계좌 숫자
	

public:
	acc_handler();											//생성자 
	~acc_handler();											//소멸자
	int SearchAccArrNum();									//추가 기능 : 계좌 배열 위치 검색
	void AddAcc(acc * acc);									//추가 기능 : 계좌 배열에 계좌 추가
	bool Menu();											// 기능 : 매뉴
	void MakeAcc();											// 기본 기능 : 계좌 생성
	void Deposit();											// 기본 기능 : 입금
	void Withdraw();										// 기본 기능 : 출금
	void ShowAllAccInfo() const;							// 기본 기능 : 모든 계좌 정보 출력

};

//
//
#endif // !__BANK_H__
//#pragma once
