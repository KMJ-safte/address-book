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
		int key = Menu();// �����ȿ� ����
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
				cout << "�����մϴ�";
				Sleep(1000);
				running = false;
				return 0;
				break;
			default:
				cout << "�߸��� �Է��Դϴ�" << endl;
				cout << "�ƹ�Ű�� �Է�" << endl;
				_getch();
				break;
		}
	}

	return 0;
}


