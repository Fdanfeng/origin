#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;

int n,map_index;    //����ʽ�ĸ���N,map���±�
string input;
unordered_map<string,int> mp[2]; //����map

void deal_part(string part);
void deal_expr(string expr);
void deal_formula(int ceof,string formula);
void deal_term(int ceof,string element);

//��flag�ָ�str�����ָ����ַ������ϴ�ŵ�vec�� 
void split(string &str,vector<string> &vec,char flag)
{
	stringstream ss(str);
	string temp;
	while(getline(ss,temp,flag)) 
	{
		vec.push_back(temp); 
	}
}

void deal_input(string input)
{
	vector<string> vec;
	split(input,vec,'=');
	//������벿��
	map_index=0;
	deal_part(vec[0]);
	//�����Ұ벿��
	map_index=1;
	deal_part(vec[1]); 
}

void deal_part(string part)
{
	vector<string> vec;
	split(part,vec,'+');
	for(string &expr:vec)
	    deal_expr(expr);
}

void deal_expr(string expr)
{
	//ceof��Ϊ�մ������
	if(isdigit(expr[0]))
	{
		int ceof=1;
		string formula;
		stringstream ss(expr);
		ss>>ceof;
		ss>>formula;
		deal_formula(ceof,formula);
	} 
	//ceofΪ��
	else
	    deal_formula(1,formula); 
}

void deal_formula(int ceof,string formula)
{
	auto cur=formula.begin();
	while(cur!=formula.end())
	{
		if(isupper(*cur))
		{
			//Ԫ����formula���е���ʼλ�ú���ֹλ�� 
			string::iterator element_begin=cur,element_end;
			if(cur+1!=formula.end()&&islower(*(cur+1)))
			   element_end=cur+2;
			else
			   element_end=cur+1;
			   
			string element(element_begin,element_end);
			//������term�ĺ�׺ceof 
			if(element_end==formula.end()||isdigit(*element_end))
			{
				deal_term(ceof,element);
				cur=element_end;
			}
			//���ں�׺ceof
			else
			{
				string::iterator ceof_begin=element_end,ceof_end;
				
			} 
		}
	}
}

int main()
{
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++)
	{
		mp[0].clear();
		mp[1].clear();
		getline(cin,input);
		deal_input(input);
		cout<<(isEqual(mp[0],mp[1])?'Y':'N')<<"\n";
	}
	return 0;
} 
