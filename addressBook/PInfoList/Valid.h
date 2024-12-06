#ifndef VALID_H
#define VALID_H

#include<bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cctype>
#include <regex>

using namespace std;


bool isValidPNum(const string& phone);

bool isValidName(const string& name);

bool isValidEmail(const string& email);

bool isValid(bool (*Valid)(const string&), string& input);

#endif // !VALID_H
