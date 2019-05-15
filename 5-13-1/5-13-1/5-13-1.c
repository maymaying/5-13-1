#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<assert.h>


/*
void Fun(int *px, int *py)
{

}
int main()
{
	int x = 0;
	int y = 0;
	Fun(&x, &y);

	return 0;
}
*/


#if 0
/*
//false
void *Mymemmove(void *dest, const void *src, int count)
{
	assert(dest != NULL && src != NULL);
	void *p = dest;
	if (src > dest)
	{
		while (count != 0)
		{
			*((char*)dest) = *((char*)src);
			((char*)dest)++;
			((char*)src)++;
			count--;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
			//count--;
		}
	}
	return p;
}
*/


//true
//void *memmove( void *dest, const void *src, size_t count );
void *Mymemmove(void *dest, void *src, int count)
{
	assert(dest != NULL && src != NULL);
	void *ret = dest;
	if (dest < src)
	{
		while (count--)
		{
			*(char*)dest = *(char *)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[10] = { 0 };
	//memmove(arr + 2, arr, 16);
	Mymemmove(arr, arr + 2, 16);// 3 4 5 6 5 6 7
	//Mymemmove(arr + 2, arr, 16);// 1 2 1 2 3 4 7
	//Mymemcpy(arr,arr+2,16);   //memcpy �ڴ����ص�����  ��memmove
	system("pause");
	return 0;
}
#endif


/*
//�ڴ濽������
//void *memcpy( void *dest, const void *src, size_t count );  count�ֽ���
void *Mymemcpy(void *dest, const void *src, int count)
{
	assert(dest != NULL && src != NULL);
	void *ret = dest;
	while (count != 0)
	{
		*((char*)dest) = *((char*)src);
		((char*)dest)++;
		((char*)src)++;
		count--;
	}
	return dest;
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[10] = { 0 };
	Mymemcpy(arr2, arr, 16);    //memcpy �ڴ����ص�����  ��memmove

	////memcpy(arr2,arr,16);
	//int*p = (int *)memcpy(arr2,arr,16);
	//int i = 0;
	//for(i = 0;i < 10;i++)
	//{
	//	printf("%d ",p[i]);//*(p+i)
	//}

	system("pause");
	return 0;
}
*/


/*
//str1��str2�Ƚ�
//int strcmp( const char *string1, const char *string2 );
int Mystrcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	//printf("%d\n", strcmp("abcd", "abcd"));//0
	//printf("%d\n", strcmp("abde", "abce"));//1
	//printf("%d\n", strcmp("abce", "adcd"));//-1

	printf("%d\n", Mystrcmp("abcd", "abcd"));//0
	printf("%d\n", Mystrcmp("abde", "abce"));//1
	printf("%d\n", Mystrcmp("abce", "adcd"));//-1
	system("pause");
	return 0;
}
*/


//VC->crt->src


/*
//char *strchr( const char *string, int c );
const char *Mystrchr(const char *src, char ch)
{
	assert(src != NULL);
	while (*src != '\0')
	{
		if (*src == ch)
		{
			return src;
		}
		src++;
	}
	return NULL;
}
int main()
{
	//char *src = "abc";
	//printf("%s\n",strchr(src,'b'));

	char *src = "abc";
	printf("%s\n", Mystrchr(src, 'b'));
	system("pause");
	return 0;
}
*/


#if 0
//char *strstr( const char *string, const char *strCharSet );
/*
const char *Mystrstr(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	while (*str1 != '\0')
	{
		const char *p = str1;
		while (*str1 != '\0' && *str2 != '\0'&&*str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str1 == '\0')
		{
			return NULL;
		}
		if (*str2 == '\0')
		{
			return p;
		}
		str1++;
	}
	return NULL;       //�˶δ������   
}
*/

//�����㷨--      KMP--
const char *Mystrstr(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	const char *s1 = NULL;
	const char *s2 = NULL;
	const char *start = str1;
	while (*start != '\0')
	{
		s1 = start;//s1���˵���һ�ε���һ��λ��
		s2 = str2;//s2���˵�str2����ʼλ��
		while (*s1 != '\0' && *s2 != '\0'&&*s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		if (*s2 == '\0')
		{
			return start;
		}
		start++;
	}
	return NULL;
}
int main()
{
	//char *dest = "abbcdef";//����
	//char *src = "bbc";//�Ӵ�
	//printf("%s\n",strstr(dest,src));

	char *dest = "abbbbcdef";//����
	char *src = "bbc";//�Ӵ�
	printf("%s\n", Mystrstr(dest, src));
	system("pause");
	return 0;
}
#endif


/*
int Mystrncmp(const char *str1, const char *str2, int n)
{
	return NULL;
}
char *Mystrncat(char *dest, const char *src, int n)
{
	return NULL;
}
char *Mystrncpy(char *dest, const char *src, int n)
{
	return NULL;
}
*/


/*
//char *strcat( char *strDestination, const char *strSource );׷���ַ���
char *Mystrcat(char *dest, const char *src)
{
	char *p = dest;
	assert(dest != NULL && src != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	//destָ����'\0'
	while (*dest++ = *src++){}
	return p;
}
int main()
{
	//char dest[25] = "fabc";
	//char *src = "hello";
	//strcat(dest, src);

	char dest[25] = "fabc";
	char *src = "hello";
	Mystrcat(dest, src);
	printf("%s\n",dest);
	system("pause");
	return 0;
}
*/


/*
//char *strcpy( char *strDestination, const char *strSource );
char *Mystrcpy(char *dest, const char *src)//��const,��֤srcֵ����
{
	//char *p = dest;
	//assert(dest != NULL && src != NULL);
	//while(*src != '\0')
	//{
	//*dest = *src;
	//dest++;
	//src++;
	//}
	//*dest = '\0';
	//return p;// '0'��'\0'��NULL��0
	char *p = dest;
	while (*dest++ = *src++){}//*dest='\0'�˳�ѭ��
	return p;
}
int main()
{
	//char *dest = "abcdef";//readonly ֻ��
	//char *src = "hello";
	//strcpy(dest, src);
	//printf("%s\n",dest);//����

	//char dest[20] = "abcdef";
	//char *src = "hello";
	//strcpy(dest, src);
	//printf("%s\n", dest);//hello

	char dest[20] = "abcdef";
	char *src = "hello";
	Mystrcpy(dest, src);
	printf("%s\n", dest);
	system("pause");
	return 0;
}
*/


/*
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
int main()
{
	int money = 0;
	int empty = 0;
	int total = 0;
	scanf("%d", &money);
	//total = money;
	//empty = money;
	//while (empty > 1)
	//{
	//	total += empty / 2;
	//	empty = empty / 2 + empty % 2;
	//}

	total = money * 2 - 1;

	printf("%d\n", total);
	system("pause");
	return 0;
}
*/


/*
//һ��������ֻ�����������ǳ���һ��,�����������ֶ����������Ρ��ҳ�������ֻ����һ�ε����֣����ʵ�֡� 
int main()
{
	int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//1����������е���������
	int i = 0;
	int num = 0;
	int pos = 0;//pos���������iλΪ1��λ��
	int x = 0;
	int y = 0;
	for (i = 0; i < len; i++)
	{
		num ^= arr[i];
	}
	//2��num�϶������Ľ��-->�ҵ�num�����Ƶ�һλΪ1��λ��
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//3���������飬��Ϊ����������
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("%d,%d\n", x, y);
	system("pause");
	return 0;
}
*/