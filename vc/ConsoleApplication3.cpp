// ConsoleApplication3.cpp: 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "def.h"
#include <cstring>



using namespace std;



	char const *base64code = "ZO6Kq79L&CPWvNopzQfghDRSG@di*kAB8rsFewxlm+/u5a^2YtTJUVEn0$HI34y#=";

	int pwbase64()               //注册码计算
	{
		const char *data = "JNvuZZZZZZK92aJVJ7TO2k2GpRzCDV+/pKqENeZZZZZ=";//pKqEpKqEpKqEpKqEpKqEpKqEpKqEpKqEpKqEpKqEpKq= POIUPOIUPOIUPOIUPOIUPOIUPOIUPOIUPOIUPOIUPOI=
		int midata[256] = { 0 };
		int t1, t2, t3, g1, g2, g3, g4, i;
		int slen, j, k = 0, f = 0;
		slen = strlen(data);
		j = slen / 4;
		for (int e = 0; e < j; e++)
		{
			g1 = -1; g2 = -1; g3 = -1; g4 = -1;
			for (i = 0; i < 64; i++)
			{
				if (base64code[i] == data[k])
				{
					g1 = i ^ (i >> 3);
					k++;
					break;
				}
			}
			for (i = 0; i < 64; i++)
			{
				if (base64code[i] == data[k])
				{
					k++;
					g2 = i ^ (i >> 3);
					break;
				}

			}            //g2
			for (i = 0; i < 64; i++)
			{
				if (base64code[i] == data[k])
				{
					k++;
					g3 = i ^ (i >> 3);
					break;
				}

			}
			for (i = 0; i < 64; i++)
			{
				if (base64code[i] == data[k])
				{
					k++;
					g4 = i ^ (i >> 3);
					break;
				}

			}
			//printf("%x %x %x %x ", g1, g2, g3, g4);
			t1 = (g1 << 2) | ((g2 >> 4) & 0x3);
			t1 = t1 & 0x00ff;
			t2 = g2 * 16 | (g3 >> 2) & 0xF;
			t2 = t2 & 0x00ff;
			t3 = (g3 << 6) | g4 & 0x3F;
			t3 = t3 & 0x00ff;
			if (data[f] == '=') { break; }
			midata[f++] = t1; printf("%X ", t1);                 //结果只取两位数
			if (data[f] == '=') { break; }
			midata[f++] = t2; printf("%X ", t2);
			if (data[f] == '=') { break; }
			midata[f++] = t2; printf("%X \n", t3);
		}
		return 0;
	}
	int pwdebase64(int baseseg[3])
	{
		//for (int i = 0; i < 3; i++) { printf("%X",baseseg[i]); }
		//printf("\n");
		int t1 = baseseg[0], t2 = baseseg[1], t3 = baseseg[2], g1, g2, g3, g4, r1, r2, r3;         //12342234323442345234623472348234
		for (int a = 0; a < 64; a++)
		{
			for (int b = 0; b < 64; b++)
			{
				for (int  c = 0; c < 64; c++)
				{
					for (int d = 0; d < 64; d++)
					{
						g1 = a ^ (a >> 3);
						g2 = b ^ (b >> 3);
						g3 = c ^ (c >> 3);
						g4 = d ^ (d >> 3);


						r1 = (g1 << 2) | ((g2 >> 4) & 0x3);
						r1 = r1 & 0x00ff;
						r2 = g2 * 16 | (g3 >> 2) & 0xF;
						r2 = r2 & 0x00ff;
						r3 = (g3 << 6) | g4 & 0x3F;
						r3 = r3 & 0x00ff;

						//printf("%x%x%x     ", r1, r2, r3); printf("%x%x%x \n", t1, t2, t3);

						if ( r1 == t1 && r2 == t2 && r3 == t3)
						{
							//printf("gugugu ");
				     		printf("%c%c%c%c", base64code[a], base64code[b], base64code[c], base64code[d]);
							return 0;
						}
					}
				}
			}
		}
		
	}
	void solve(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 *a6, __int64 *a7, __int64 *a8)
	{
		*a8 = a3 + (a2 + a1 * a5 - a4)*a5;
		*a6 = (a4 - a2) / (2 * a1);
		*a7 = a3 + (a1**a6 + a2)**a6;
	}

	int main()
	{
		unsigned char buf[33];
		cout << "按要求输入" << endl;
		cout << "示例 ：username 如果是 1234#2234#3234#4234#5234#6234#7234#8234" << "username'#' 必须有7个" << endl;
		cout << "         则输入：" << "12342234323442345234623472348234   一共输入32位" << endl;
		cout << "你的username：" << endl;
		cout << "   4   8  12  16  20  24  28  32↓" << endl;
		cout << "-------------------------------->  长度" << endl;
		cin >> buf;
		unsigned int v1[4], v2[4], v3[4], v4[4], v5[4], v6[4], v7[4], v8[4];//内容获取
		unsigned __int64 opt[5];
		for (int i = 0; i < 4; i++)
		{
			v1[i] = (unsigned int)buf[0 + i];
			v2[i] = (unsigned int)buf[4 + i];
			v3[i] = (unsigned int)buf[8 + i];
			v4[i] = (unsigned int)buf[12 + i];
			v5[i] = (unsigned int)buf[16 + i];
			v6[i] = (unsigned int)buf[20 + i];
			v7[i] = (unsigned int)buf[24 + i];
			v8[i] = (unsigned int)buf[28 + i];
		}
		unsigned __int64 temp1, temp2, temp3, temp4;         //计算5个64位数
		temp1 = (v1[0] * v2[0]) << 0x10;
		temp2 = v3[1] ^ v1[1];
		temp3 = (v1[2] % (v4[2] + 1)) + 1;
		temp4 = v1[3] / (v5[3] + 1);
		opt[0] = temp1 + temp2 + temp3 + temp4;
		temp1 = (v2[0] ^ v6[0]) << 0x10;
		temp2 = v2[1] % (v7[1] + 3);
		temp3 = (v2[2] / (v8[2] + 1) + 5);
		temp4 = (v1[3] + v2[3]);
		opt[1] = temp1 + temp2 + temp3 + temp4;
		temp1 = (v2[2] / (v3[0] + 3)) << 10;
		temp2 = (v3[1] % v4[1]) ^ temp1;
		temp3 = v3[2] + v6[2] + 0xC;
		temp4 = v8[3] + v3[3];
		opt[2] = temp1 + temp2 + temp3 + temp4;
		opt[3] = v1[1] ^ v3[3];
		opt[3] *= (v2[3] + v4[1]);
		opt[3] &= (v5[2] & v6[2]);
		opt[3] *= v8[3];
		opt[3] += opt[1];
		opt[3] *= v7[0];
		opt[3] *= opt[0];
		opt[3] = opt[3] - (opt[3] - opt[1]) % (2 * opt[0]); 
		temp1 = (v4[0] ^ v5[0]) << 0x10;
		temp2 = (v4[1] % (v5[1] + 2))*temp1;
		temp3 = ((v4[2] % (v5[2] + 5)) + 7);
		temp4 = (v4[3] * v5[3]);
		opt[4] = temp2 + temp3 + temp4;                //对USER计算完成
		const char *true5 = "pKqENeZZZZZ=";
		//pwbase64();
		__int64 x, y, z;
		            //  char codet[25];                    win10 bug memorycopy
		//for (int i = 0; i < 25; i++) { codet[i] = 0; }

		solve(opt[0], opt[1], opt[2], opt[3], opt[4], &x, &y, &z);
		//printf("%I64X \n%I64X \n%I64X \n", x, y, z);
		cout << "你的注册码：" << endl;
		// printf("%s", codet);
		int bak1[3], bak2[3], bak3[3], bak4[3], bak5[3], bak6[3], bak7[3], bak8[3];  
		bak1[0] = x & 0xff;
		bak1[1] = x >>8 & 0xff; 
		bak1[2] = x >>16 & 0xff;
		bak2[0] = x >>24& 0xff;
		bak2[1] = x >>32 & 0xff;
		bak2[2] = x >>40 & 0xff;
		bak3[0] = x >>48 & 0xff; 
		bak3[1] = x >>56 & 0xff;

		bak3[2] = y & 0xff;
		bak4[0] = y >> 8 & 0xff;
		bak4[1] = y >> 16 & 0xff;
		bak4[2] = y >> 24 & 0xff;
		bak5[0] = y >> 32 & 0xff;
		bak5[1] = y >> 40 & 0xff;
		bak5[2] = y >> 48 & 0xff;
		bak6[0] = y >> 56 & 0xff;

		bak6[1] = z & 0xff;
		bak6[2] = z >> 8 & 0xff;
		bak7[0] = z >> 16 & 0xff;
		bak7[1] = z >> 24 & 0xff;
		bak7[2] = z >> 32 & 0xff;
		bak8[0] = z >> 40 & 0xff;
		bak8[1] = z >> 48 & 0xff;
		bak8[2] = z >> 56 & 0xff;





		//printf("%I64X \n", x);

		//for (int i = 0; i < 3; i++) { printf("%x",bak1[i]); }
		pwdebase64(bak1);                               //解码输出
		pwdebase64(bak2);
		pwdebase64(bak3);
		pwdebase64(bak4);
		pwdebase64(bak5);
		pwdebase64(bak6);
		pwdebase64(bak7);
		pwdebase64(bak8);
		printf("%s\n", true5);
		system("pause");
		return 0;
	}





/* unsigned __int64 int128mul(unsigned __int64 m1, unsigned __int64 m2)                                     //没大数库  cust瓜皮版 大数计算
{
unsigned __int64 mt11, mt12, mt21, mt22,part1, part2, part3,part5,part6,result;
mt12 = HIDWORD(m1);
mt11 = LOWORD(m1);            //对应两个大数 高低位；
mt22 = HIDWORD(m2);
mt21 = LOWORD(m2);
part1 = mt11 * mt21;                                                               //
part2 = mt11 * mt22;
part3 = mt12 * mt21; 
//printf("%I64X\n", part3);
//part4 = mt12 * mt22;
part5 = LOWORD(part2);
part6 = LOWORD(part3);
part5 = part5 << 16;
part6 = part6 << 16;
result = part1 + part5;
result = result + part6;
return result;
*/