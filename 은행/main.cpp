#include <iostream>
#include"Bank.h"
using namespace std;


int main()
{
	////은행 핸들 프로그램 // 은행 프로그램을 계속 진행할지 여부를 물어줌,  진행시 계속 menu 호출
	acc_handler accHandle;

	bool Do_bank = true;
	while (Do_bank) {
		cout << "은행 프로그램을 실행 하시겠습니까?" << endl;
		cout << " 진행 : Y     종료 : N" << endl;
		char select;

		cin >> select;

		if (select == 'Y' || select == 'y' || select == 'ㅛ') {
			system("cls");
			Do_bank = accHandle.Menu();
		}
		else if (select == 'N' || select == 'n' || select == 'ㅜ') {
			Do_bank = false;
		}
		else {
			cout << " 잘못된 입력입니다" << endl;
		}
	}

}
