#include"Valid.h"
#include"Function.h"

bool isValidPNum(const string& phone) {
	regex pNum("\\b\\d{3}-\\d{4}-\\d{4}");
	return regex_match(phone, pNum);  // ����ǥ������ �´ٸ� true, false

}

bool isValidName(const string& name)
{
	// ���ڿ��� ��� ���� �ʰ�, ��� ���ڰ� ������ �ƴ� ��쿡�� true ��ȯ
	if (name.empty())
		return false;
	return isspace(static_cast<unsigned char>(name[0])) ? false : true; // ����ִٸ� false �ƴϸ� true
}

bool isValidEmail(const string& Pemail) {
	regex email("(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
	return regex_match(Pemail, email);
}

bool isValid(bool (*Valid)(const string&), string& input) {
	return Valid(input);
}