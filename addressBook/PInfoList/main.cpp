#include"Function.h"
#include"Valid.h"

using namespace std;



int main()
{
	Contact PInfo;
	vector<Contact> VPInfo;

	bool running = true;

	while (running)
	{
		system("cls");
		int key = Menu();// 루프안에 선언
		switch (key)
		{
			case 49:
				VisiblePInfo(VPInfo, true);
				break;
			case 50:
				InputPInfo(VPInfo, PInfo);
				break;
			case 51:
				RemovePInfo(VPInfo);
				break;
			case 52:
				EditPInfo(VPInfo, PInfo);
				break;
			case 27:
				cout << "종료합니다";
				Sleep(1000);
				running = false;
				return 0;
				break;
			default:
				cout << "잘못된 입력입니다" << endl;
				cout << "아무키나 입력" << endl;
				_getch();
				break;
		}
	}

	return 0;
}


