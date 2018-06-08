/*
*Created by ������
*Student Number 1652977
*This is T4 of DiscremeMath Homework
*/
#include <iostream>
#include "climits"
using namespace std;
const int N = 100;
int p[N], key[N], tb[N][N];

void prim(int v, int n)
{
	int i, j;
	int min;
	for (i = 1; i <= n; i++)
	{
		p[i] = v;
		key[i] = tb[v][i];
	}
	key[v] = 0;
	for (i = 2; i <= n; i++)
	{
		min = INT_MAX;
		for (j = 1; j <= n; j++)
		{
			if (key[j] > 0 && key[j] < min)
			{
				v = j;
				min = key[j];
			}
		}
		cout << "��С�ķ���:" << p[v] << "��" << v << endl;
		key[v] = 0;
		for (j = 1; j <= n; j++)
		{
			if (tb[v][j] < key[j])
			{
				p[j] = v;
				key[j] = tb[v][j];
			}
		}
	}
}

int main()
{
	int n, m;
	int i, j;
	int u, v, w;
	cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������������0����):\n"; //��������Ķ�����Ŀ�ͱ���
	while (cin >> n >> m)
	{
		if (m != 0 && n != 0)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
					tb[i][j] = INT_MAX;
			}
			cout << "�����������ߵĽڵ�����Լ����ǵ�Ȩֵ(�Կո�ָ�������):\n";
			while (m--)	      //�������б����Լ����ǵ�Ȩֵ
			{
				cin >> u >> v >> w;	  //��������Լ����ǵ�Ȩֵ
				tb[u][v] = tb[v][u] = w;
			}
			prim(1, n);
			cout << endl;
			system("pause");
			system("cls");
			cout << "����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�����������������0����):\n"; //��������Ķ�����Ŀ�ͱ���
		}
		else if (n == 0 && m == 0)
		{
			exit(1);
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	return 0;
}