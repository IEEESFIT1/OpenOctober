#include<bits/stdc++.h>
using namespace std;

long int p, q, n, t, flag, temp[100], enc[1000], dc[1000], ms[1000], encrypt[1000];
char message[1000];
int prime(long int pr)
{
	int i;
	int j = sqrt(pr);
	for (i = 2; i <= j; i++)
	{
		if (pr % i == 0)
			return 0;
	}
	return 1;
}
long int CD(long int a) {
	long int k = 1;
	while (1) {
		k = k + t;
		if (k % a == 0)
			return (k / a);
	}
}
void CE() {
	int k = 0;
	for (int i = 2; i < t; ++i)
	{
		if (t % i == 0)
			continue;
		flag = prime(i);
		if (flag == 1 && i != p && i != q)
		{
			enc[k] = i;
			flag = CD(enc[k]);
			if (flag > 0)
			{
				dc[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}

void Encrypt() {
	long int pt, ct, key = enc[0], k, l;
	int i = 0;
	l = strlen(message);
	// cout << l << "                ";
	while (i != l) {
		pt = ms[i];
		pt = pt - 96;
		k = 1;
		for (int j = 0; j < key; ++j)
		{
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		ct = k + 96;
		encrypt[i] = ct;
		i++;
	}
	encrypt[i] = -1;
	cout << "Encrypted Message :";
	for (int i = 0; encrypt[i] != -1; i++)
	{
		printf("%c", encrypt[i] );
	}
}
void Decrypt()
{
	long int pt, ct, key = dc[0], k;
	int i = 0;
	while (encrypt[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (int j = 0; j < key; j++)
		{
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		ms[i] = pt;
		i++;
	}
	ms[i] = -1;
	cout << "\nDecrypted Message :\n";
	for (i = 0; ms[i] != -1; i++)
		printf("%c", ms[i]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << "Enter 1st Prime No:\n";
	cin >> p;
	cout << "Enter 2nd Prime No:\n";
	cin >> q;
	cout << "Enter your Message";
	// fflush(stdin); // to clear the output buffer
	cin >> message;

	n = p * q;
	t = (p - 1) * (q - 1);
	for (int i = 0; message[i] != '\0'; ++i)
	{
		ms[i] = message[i];
	}
	CE();
	Encrypt();
	Decrypt();
	return 0;
}