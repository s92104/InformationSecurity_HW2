// InformationSecurity_HW2.cpp : 定義主控台應用程式的進入點。
//

#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

//Table
const int PC_1[56]{ 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
const int PC_2[48]{ 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32, };
const int FP[64] {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };
const int E[48]{ 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
const int S[8][64]{ {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},
{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} };
const int P[32]{ 16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25 };
const int IP[64]{ 58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };

bitset<56> selectPermutation_1(bitset<64> key)
{
	bitset<56> PC_1_key;
	for (int i = 0; i < 56; i++)
	{
		PC_1_key[55-i] = key[63-(PC_1[i]-1)];
	}
	return PC_1_key;
}
bitset<48> selectPermutation_2(bitset<56> key)
{
	bitset<48> PC_2_key;
	for (int i = 0; i < 48; i++)
	{
		PC_2_key[47-i] = key[55-(PC_2[i]-1)];
	}
	return PC_2_key;
}
vector<bitset<48>> generateSubKey(bitset<64> key)
{
	//16把subkey
	vector<bitset<48>> subkey;
	//PC-1
	bitset<56> PC_1_key=selectPermutation_1(key);
	//拆一半
	bitset<28> C, D;
	for (int i = 0; i < 28; i++)
	{
		C[i] = PC_1_key[i+28];
		D[i] = PC_1_key[i];
	}
	//16 round
	for (int round = 0; round < 16; round++)
	{
		//rotated left
		if (round == 0 || round == 1 || round == 8 || round == 15)
		{
			bitset<1> rec;
			rec[0] = C[27];
			C=C << 1;
			C[0] = rec[0];

			rec[0] = D[27];
			D=D << 1;
			D[0] = rec[0];
		}
		else
		{
			bitset<2> rec;
			rec[1] = C[27];
			rec[0] = C[26];
			C=C << 2;
			C[1] = rec[1];
			C[0] = rec[0];

			rec[1] = D[27];
			rec[0] = D[26];
			D=D << 2;
			D[1] = rec[1];
			D[0] = rec[0];
		}
		//PC-2
		bitset<56> PC_2_key;
		for (int i = 0; i < 28; i++)
		{
			PC_2_key[i+28] = C[i];
			PC_2_key[i] = D[i];
		}
		//SubKey
		subkey.push_back(selectPermutation_2(PC_2_key));
	}

	return subkey;
}
bitset<64> reverseFP(bitset<64> data)
{
	bitset<64> key;
	for (int i = 0; i < 64; i++)
	{
		key[63 - (FP[i] - 1)] = data[63 - i];
	}
	return key;
}
bitset<48> expand(bitset<32> R)
{
	bitset<48> expandR;
	for (int i = 0; i < 48; i++)
	{
		expandR[47 - i] = R[31 - (E[i] - 1)];
	}
	return expandR;
}
bitset<32> f(bitset<32> R, bitset<48>key)
{
	//Expand
	bitset<48> f_data = expand(R);
	//XOR
	f_data ^= key;
	//切八份
	bitset<6> s[8];
	bitset<32> s_data;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			s[i][5-j] = f_data[47 - j - 6 * i];
		}
		//SandBox
		bitset<2> tmpR;
		tmpR[0] = s[i][0];
		tmpR[1] = s[i][5];
		int row = tmpR.to_ulong();
		bitset<4> tmpC;
		tmpC[0] = s[i][1];
		tmpC[1] = s[i][2];
		tmpC[2] = s[i][3];
		tmpC[3] = s[i][4];
		int column = tmpC.to_ulong();
		bitset<4> tmpS(S[i][row * 16 + column]);
		//合起來
		for (int j = 0; j < 4; j++)
		{
			s_data[31 - j - 4 * i] = tmpS[3 - j];
		}
	}
	//P
	bitset<32> p;
	for (int j = 0; j < 32; j++)
	{
		p[31 - j] = s_data[31 - (P[j] - 1)];
	}
	return p;
}
bitset<64> reverseIP(bitset<64> data)
{
	bitset<64> reverseIP_data;
	for (int i = 0; i < 64; i++)
	{
		reverseIP_data[63 - (IP[i]-1)] = data[63 - i];
	}
	return reverseIP_data;
}
int main()
{
	string in,k;
	while (cin >> in)
	{
		cin >> k;
		bitset<64> data(in);
		bitset<64> key(k);
		//Generate SubKey
		vector<bitset<48>> subkey = generateSubKey(key);
		//Reverse FP
		bitset<64> reverseFP_data = reverseFP(data);
		//切一半，交換
		bitset<32> L, R;
		for (int i = 0; i < 32; i++)
		{
			L[i] = reverseFP_data[i];
			R[i] = reverseFP_data[i+32];
		}		
		//16 Round
		for (int round = 0; round < 16; round++)
		{
			//L->R
			bitset<32> recR = R;
			R = L;
			//R XOR f->L
			L = recR^f(L, subkey[15 - round]);
		}
		//合起來
		bitset<64> LR;
		for (int i = 0; i < 32; i++)
		{
			LR[63 - i] = L[31-i];
			LR[63 - i - 32] = R[31 - i];
		}	
		//Reverse IP
		bitset<64> reverseIP_data = reverseIP(LR);
		cout << reverseIP_data << endl;
	}

	return 0;
}


