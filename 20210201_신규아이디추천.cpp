#include <iostream>
#include <string>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/72410

string solution(string new_id) {
	string answer = "";

	//1 �빮�� -> �ҹ���
	char ch = 0;
	string condition1 = "";
	for (size_t i = 0; i < new_id.length(); ++i)
	{
		ch = new_id[i];

		if ('A' <= ch && ch <= 'Z')
		{
			ch += + 32;
		}

		condition1 += ch;
	}

	//2 ���ĺ�,����,-,_,. �� ����
	string condition2 = "";
	for (size_t i = 0; i < condition1.length(); ++i)
	{
		ch = condition1[i];

		if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9') || ch == '-' || ch == '_' || ch == '.')
		{
			condition2 += ch;
		}
	}

	if (condition2.length() == 0)
	{
		return "aaa";
	}

	//3 .�� ���ӵǸ� 1����
	string condition3 = "";
	condition3 += condition2[0];
	for (size_t i = 1; i < condition2.length(); ++i)
	{
		if (condition2[i] == '.' && condition2[i - 1] == '.')
		{
			continue;
		}

		condition3 += condition2[i];
	}

	//4 .�� ó���̳� ���̸� ����
	string condition4 = "";
	for (size_t i = 0; i < condition3.length(); ++i)
	{
		if ((i == 0 && condition3.front() == '.') || (i == condition3.length() - 1 && condition3.back() == '.'))
		{
			continue;
		}

		condition4 += condition3[i];
	}

	if (condition4.length() == 0)
	{
		return "aaa";
	}

	//5 ����� a
	string condition5 = "";
	for (size_t i = 0; i < condition4.length(); ++i)
	{
		ch = condition4[i];
		if (ch == ' ')
		{
			ch = 'a';
		}

		condition5 += ch;
	}

	//6 15�ڱ��� ����, �������� .�̸� ����
	string condition6 = "";
	if (15 < condition5.length())
	{
		for (size_t i = 0; i < 15; ++i)
		{
			condition6 += condition5[i];
		}
	}
	else
	{
		condition6 = condition5;
	}

	if (condition6.back() == '.') 
	{
		condition6.erase(condition6.end() - 1);
	}
	

	//7 ���̰� 2�� ���ϸ� ���������ڷ� 3�ɶ����� ä���
	string condition7 = condition6;
	if (condition6.length() < 3)
	{
		while (condition7.length() < 3)
		{
			condition7 += condition7.back();
		}
	}
	
	answer = condition7;

	return answer;
}

int main() {

	string str = "=.=";

	solution(str);

	return 0;
}