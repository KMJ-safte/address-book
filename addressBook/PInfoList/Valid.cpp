#include"Valid.h"
#include"Function.h"

bool isValidPNum(const string& phone) {
	regex pNum("\\b\\d{3}-\\d{4}-\\d{4}");
	return regex_match(phone, pNum);  // 정규표현식이 맞다면 true, false

}

bool isValidName(const string& name)
{
	// 문자열이 비어 있지 않고, 모든 문자가 공백이 아닌 경우에만 true 반환
	if (name.empty())
		return false;
	return isspace(static_cast<unsigned char>(name[0])) ? false : true; // 비어있다면 false 아니면 true
}

bool isValidEmail(const string& Pemail) {
	regex email("(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
	return regex_match(Pemail, email);
}

bool isValid(bool (*Valid)(const string&), string& input) {
	return Valid(input);
}