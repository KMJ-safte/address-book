#include"Function.h"
#include"Valid.h"

using namespace std;

int Menu()
{
	cout << "1.��ü �ּҷ�" << endl;
	cout << "2.�ּҷ� �Է�" << endl;
	cout << "3.�ּҷ� ����" << endl;
	cout << "4.�ּҷ� ����" << endl;
	return _getch();
}

void VisiblePInfo(vector<Contact>& vp, bool wait)
{
	if (!vp.empty())
	{
		cout << endl;
		cout << "��ü ��ȭ ��ȣ" << endl;
		for (int i = 0; i < vp.size(); i++)
		{
			cout << "�̸�: " << vp[i].name << endl;
			cout << "��ȭ��ȣ: " << vp[i].pNum << endl;
			cout << "�̸���: " << vp[i].email << endl;
			cout << "----------------------------------" << endl;
		}
	}
	else
	{
		cout << "��ϵ� ��ȭ��ȣ�� �����" << endl;
	}

	cout << endl;
	if (wait) {
		cout << "�ƹ�Ű�� �Է�" << endl;
		_getch();
	}
}

string InputName(vector<Contact>& vp, Contact& p) {
	while (true)
	{
		cout << "�̸��� �Է��ϼ���:";
		getline(cin, p.name);

		// �̸��� ����ִ��� üũ
		if (p.name.empty()) {
			cout << "�̸��� �Է��ؾ� �մϴ�. �ٽ� �Է��ϼ���." << endl;
			continue;
		}

		if (!isValid(isValidName, p.name))
		{
			cout << "�̸��� �ٽ� �Է��ϼ���" << endl;
		}
		else
		{
			break;
		}
	}
	return p.name;
}

string InputPnum(vector<Contact>& vp, Contact& p) {
	bool isDuplicate = false;

	do {
		cout << "��ȭ��ȣ�� �Է��ϼ���(010-1234-1234����): ";
		getline(cin, p.pNum);
		cout << endl;
		if (!isValid(isValidPNum, p.pNum)) {
			cout << "��ȭ ��ȣ ������ �߸��Ǿ����ϴ�.(xxx-xxxx-xxxx)�������� �Է��ϼ���" << endl;
			continue;
		}

		// ��ȭ��ȣ �ߺ� üũ
		isDuplicate = false;
		for (const auto& contact : vp)
		{
			if (contact.pNum == p.pNum)
			{
				cout << "�̹� ��ϵ� ��ȭ��ȣ�Դϴ�. �ٽ� �Է����ּ���." << endl;
				isDuplicate = true;
				break;  // �ߺ��� ������ �ٽ� ��ȭ��ȣ�� �Է� �޵���
			}
		}
	} while (!isValid(isValidPNum, p.pNum) || isDuplicate);
	return p.pNum;
}

string InputEmail(Contact& p) {
	while (true) {
		cout << "�̸����� �Է��ϼ��� (���� ���, ���ĸ� �˻�): ";
		getline(std::cin, p.email);

		// �̸��� ������ ��ȿ���� Ȯ��
		if (p.email.empty() || isValid(isValidEmail, p.email)) {
			return p.email;
			break;
		}
		else {
			std::cout << "�߸��� �̸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n";
		}
	}
	return p.email;
}

void InputPInfo(vector<Contact>& vp, Contact& p) {
	bool running_pNum = true;

	p.name = InputName(vp, p);
	cout << endl;
	cout << "�Էµ� �̸�:" << p.name << endl;
	cout << endl;
	p.pNum = InputPnum(vp, p);
	cout << "�Էµ� ��ȭ��ȣ" << p.pNum << endl;
	cout << endl;
	p.email = InputEmail(p);
	cout << endl;
	cout << "�Էµ� �̸���: " << (p.email.empty() ? "����" : p.email) << "\n";


	vp.push_back(p);

	cout << endl;

	cout << "�ƹ�Ű�� �Է�";
	_getch();
}

void RemovePInfo(vector<Contact>& vp)
{
	string pnum;
	if (vp.empty())
	{
		cout << "��ϵ� �ּҷ��� �����";
	}
	else
	{

		bool found = false;
		bool inputistrue = false;
		cout << "!! ���� �Ͻðھ�� !!(1(����) or 0)" << endl;
		cin >> inputistrue;
		cin.ignore();
		if (inputistrue) {

			cout << "����� �ּҷ�:" << endl;
			
			cout << endl;
			
			VisiblePInfo(vp, false);
			
			cout << endl;
			
			while (true) {
				cout << "������ ��ȭ��ȣ�� �Է��ϼ���:";
				getline(cin, pnum);
				for (int i = 0; i < vp.size(); i++)
				{
					if (vp[i].pNum == pnum)
					{
						vp.erase(vp.begin() + i);
						cout << "�����Ǿ����ϴ�" << endl;
						found = true;
						break;
					}
				}

				if (found) {
					break;
				}
				else {
					cout << "ã���� �����ϴ�. �ٽ��Է����ּ���" << endl;
				}
			}

		}
		
	}



	cout << endl;
	cout << "�ƹ�Ű�� �Է�";
	_getch();
}

void EditPInfo(vector<Contact>& vp, Contact& p) {
	string name;
	char chooce;
	if (vp.empty()) {
		cout << "��ϵ� �ּҷ��� �����ϴ�" << endl;
	}
	else {
		string chooce_pNum;
		string chooce_Email;
		while (true) {

			system("cls");

			VisiblePInfo(vp, false);
			cout << "������ �̸��� �Է��ϼ���:";
			getline(cin, name);

			if (name.empty()) {
				cout << "�̸��� �Է��ؾ� �մϴ�" << endl;
				Sleep(1000);
				continue;
			}

			bool found = false;  // �̸��� ã�Ҵ��� ���θ� ��Ÿ���� ����

			for (int i = 0; i < vp.size(); i++) {
				if (vp[i].name == name) {
					cout << endl;
					cout << "������ " ;
					string newName = InputName(vp, p);
					vp[i].name = newName;
					cout << "��ȭ��ȣ�� ���� �Ұ��ΰ���?(�ƴ϶�� ����)" ;
					while (true) {
						getline(cin, chooce_pNum);
						cout << endl;
						if (chooce_pNum.empty()) {
							string newPNum = InputPnum(vp,p);
							vp[i].pNum = newPNum;
						}
						break;
					}

					cout << "�̸����� ���� �Ұ��ΰ���?(�ƴ϶�� ����)" ;
					while (true) {
						getline(cin, chooce_Email);
						cout << endl;
						if (chooce_Email.empty()) {
							string newEmail = InputEmail(p);
							vp[i].email = newEmail;
						}
						break;
					}
					found = true;
					break;
				}
			}

			if (!found) {
				cout << "�̸��� ��ġ���� �ʾƿ�" << endl;
			}

			cout << "�ٽ� �ۼ��ϰڽ��ϱ�?(o/x)" << endl;
			cin >> chooce;
			cin.ignore();  // cin >> chooce �� ���� ���� ���� ����

			if (chooce == 'x') {
				break;
			}
		}
	}
	cout << "�ƹ�Ű�� �Է�";
	_getch();
}