#ifndef FUNCTION_H
#define FUNCTION_H

#include<bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cctype>
#include <regex>

using namespace std;

struct Contact
{
	string name;
	string pNum;
	string email;
};


int Menu();



void VisiblePInfo(vector<Contact>& vp, bool wait);

string InputName(vector<Contact>& vp, Contact& p);

string InputPnum(vector<Contact>& vp, Contact& p);

string InputEmail(Contact& p);

void InputPInfo(vector<Contact>& vp, Contact& p);

void RemovePInfo(vector<Contact>& vp);

void EditPInfo(vector<Contact>& vp, Contact& p);

#endif // !FUNCTION.H
