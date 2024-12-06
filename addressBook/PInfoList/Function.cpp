#include"Function.h"
#include"Valid.h"

using namespace std;

int Menu()
{
	cout << "1.전체 주소록" << endl;
	cout << "2.주소록 입력" << endl;
	cout << "3.주소록 삭제" << endl;
	cout << "4.주소록 수정" << endl;
	return _getch();
}

void VisiblePInfo(vector<Contact>& vp, bool wait)
{
	if (!vp.empty())
	{
		cout << endl;
		cout << "전체 전화 번호" << endl;
		for (int i = 0; i < vp.size(); i++)
		{
			cout << "이름: " << vp[i].name << endl;
			cout << "전화번호: " << vp[i].pNum << endl;
			cout << "이메일: " << vp[i].email << endl;
			cout << "----------------------------------" << endl;
		}
	}
	else
	{
		cout << "등록된 전화번호가 없어요" << endl;
	}

	cout << endl;
	if (wait) {
		cout << "아무키나 입력" << endl;
		_getch();
	}
}

string InputName(vector<Contact>& vp, Contact& p) {
	while (true)
	{
		cout << "이름을 입력하세요:";
		getline(cin, p.name);

		// 이름이 비어있는지 체크
		if (p.name.empty()) {
			cout << "이름을 입력해야 합니다. 다시 입력하세요." << endl;
			continue;
		}

		if (!isValid(isValidName, p.name))
		{
			cout << "이름을 다시 입력하세요" << endl;
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
		cout << "전화번호를 입력하세요(010-1234-1234형식): ";
		getline(cin, p.pNum);
		cout << endl;
		if (!isValid(isValidPNum, p.pNum)) {
			cout << "전화 번호 형식이 잘못되었습니다.(xxx-xxxx-xxxx)형식으로 입력하세요" << endl;
			continue;
		}

		// 전화번호 중복 체크
		isDuplicate = false;
		for (const auto& contact : vp)
		{
			if (contact.pNum == p.pNum)
			{
				cout << "이미 등록된 전화번호입니다. 다시 입력해주세요." << endl;
				isDuplicate = true;
				break;  // 중복이 있으면 다시 전화번호를 입력 받도록
			}
		}
	} while (!isValid(isValidPNum, p.pNum) || isDuplicate);
	return p.pNum;
}

string InputEmail(Contact& p) {
	while (true) {
		cout << "이메일을 입력하세요 (공백 허용, 형식만 검사): ";
		getline(std::cin, p.email);

		// 이메일 형식이 유효한지 확인
		if (p.email.empty() || isValid(isValidEmail, p.email)) {
			return p.email;
			break;
		}
		else {
			std::cout << "잘못된 이메일 형식입니다. 다시 입력하세요.\n";
		}
	}
	return p.email;
}

void InputPInfo(vector<Contact>& vp, Contact& p) {
	bool running_pNum = true;

	p.name = InputName(vp, p);
	cout << endl;
	cout << "입력된 이름:" << p.name << endl;
	cout << endl;
	p.pNum = InputPnum(vp, p);
	cout << "입력된 저화번호" << p.pNum << endl;
	cout << endl;
	p.email = InputEmail(p);
	cout << endl;
	cout << "입력된 이메일: " << (p.email.empty() ? "없음" : p.email) << "\n";


	vp.push_back(p);

	cout << endl;

	cout << "아무키나 입력";
	_getch();
}

void RemovePInfo(vector<Contact>& vp)
{
	string pnum;
	if (vp.empty())
	{
		cout << "등록된 주소록이 없어요";
	}
	else
	{

		bool found = false;
		bool inputistrue = false;
		cout << "!! 삭제 하시겠어요 !!(1(삭제) or 0)" << endl;
		cin >> inputistrue;
		cin.ignore();
		if (inputistrue) {

			cout << "저장된 주소록:" << endl;
			
			cout << endl;
			
			VisiblePInfo(vp, false);
			
			cout << endl;
			
			while (true) {
				cout << "삭제할 전화본호를 입력하세요:";
				getline(cin, pnum);
				for (int i = 0; i < vp.size(); i++)
				{
					if (vp[i].pNum == pnum)
					{
						vp.erase(vp.begin() + i);
						cout << "삭제되었습니다" << endl;
						found = true;
						break;
					}
				}

				if (found) {
					break;
				}
				else {
					cout << "찾을수 없습니다. 다시입력해주세요" << endl;
				}
			}

		}
		
	}



	cout << endl;
	cout << "아무키나 입력";
	_getch();
}

void EditPInfo(vector<Contact>& vp, Contact& p) {
	string name;
	char chooce;
	if (vp.empty()) {
		cout << "등록된 주소록이 없습니다" << endl;
	}
	else {
		string chooce_pNum;
		string chooce_Email;
		while (true) {

			system("cls");

			VisiblePInfo(vp, false);
			cout << "수정할 이름을 입력하세요:";
			getline(cin, name);

			if (name.empty()) {
				cout << "이름을 입력해야 합니다" << endl;
				Sleep(1000);
				continue;
			}

			bool found = false;  // 이름을 찾았는지 여부를 나타내는 변수

			for (int i = 0; i < vp.size(); i++) {
				if (vp[i].name == name) {
					cout << endl;
					cout << "변경할 " ;
					string newName = InputName(vp, p);
					vp[i].name = newName;
					cout << "전화번호를 유지 할것인가요?(아니라면 공백)" ;
					while (true) {
						getline(cin, chooce_pNum);
						cout << endl;
						if (chooce_pNum.empty()) {
							string newPNum = InputPnum(vp,p);
							vp[i].pNum = newPNum;
						}
						break;
					}

					cout << "이메일을 유지 할것인가요?(아니라면 공백)" ;
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
				cout << "이름이 일치하지 않아요" << endl;
			}

			cout << "다시 작성하겠습니까?(o/x)" << endl;
			cin >> chooce;
			cin.ignore();  // cin >> chooce 후 남은 개행 문자 제거

			if (chooce == 'x') {
				break;
			}
		}
	}
	cout << "아무키나 입력";
	_getch();
}