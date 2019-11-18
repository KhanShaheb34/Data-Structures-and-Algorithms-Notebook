#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll

ull m;

struct pr
{
	string word;
	ull _hash;
};

pr *hashmap;

ull hx(string str)
{
	ull i = 0, Id = 0;
	while(str[i])
	{
		Id += str[i] - 'a';
		Id <<= 2;
		i++;
	}
	return Id;
}

ull knuth_multiplicative_hash(ull key)
{
	ull knuth = 2654435769;
	return (key * knuth) % m;
}

ull quadratic_hash(ull k, ull i)
{
	return (knuth_multiplicative_hash(k) + i * i + i) % m;
}

bool insert(ull key, string value)
{
	ull i = 0;
	ull index = quadratic_hash(key, i);
	if(hashmap[index]._hash == key)
		return true;
	while(hashmap[index].word != "")
	{
		i++;
		index = quadratic_hash(key, i);
		if(hashmap[index]._hash == key)
			return true;
	}
	hashmap[index].word = value;
	hashmap[index]._hash = key;
	return false;
}

void tokenize(string str)
{
	istringstream ss(str);
	do {
		string word;
		ss >> word;
		insert(hx(word), word);
	} while(ss);
}

int main()
{
	string str;
	cout << "Enter table size : ";
	cin >> m;
	getchar();
	hashmap = new pr[m];
	cout << "Enter elements in one line: ";
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	tokenize(str);
	cout << "The Hash Table:" << endl;
	for(ull i = 0 ; i < m; i++)
	{
		if(hashmap[i].word != "")
			cout << "hashmap[" << i << "] = " << hashmap[i].word << endl;
	}
	return 0;
}
