#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
#define L 16
void printalign(vector<string>& ss)
{
	string tmp = "";
	int cur = 0;
	int sz = ss.size();
	for (int i = 0; i <= sz - 1; i++)
	{
		int tmp_sz = ss[i].size();
		if (cur+tmp_sz==16)
		{
			tmp = tmp + ss[i];
			cout << setw(L) << tmp << endl;
			tmp = "";
			cur = 0;
		}
		else if(cur+tmp_sz<16)
		{
			cur = cur + tmp_sz;
			tmp = tmp + ss[i];
			tmp = tmp + " ";
			cur = cur + 1;
		}
		else if (cur + tmp_sz > 16)
		{
			cout << setw(L) << tmp << endl;
			tmp = "";
			cur = 0;
			i=i-1;

		}
		
		
	}
	cout << setw(L) << tmp << endl;
}
vector <string> splitwor(string str)
{
	int sz = str.size();
	vector<string>word;
	string tmp="";
	for (int i = 0; i <= sz - 1; i++)
	{
		if (str.at(i) == ' ')
		{
			word.push_back(tmp);
			tmp = "";
		}
		else
		{
			tmp = tmp + str[i];
		}
	}
	word.push_back(tmp);
	return word;

}
int main()
{
	string s;
	getline(cin, s);
	vector <string> split;
	split = splitwor(s);
	printalign(split);
	cout << endl;
	return 0;

}