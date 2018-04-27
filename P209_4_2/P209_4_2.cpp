// P209_4_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//本函数实现字符串中重复字符的删除
void del_rep_word(char *s)
{
	int i, j,k;
	i = 1;
	/*算法：从第二个元素观察每一个有效字符，是否与其紧前面字符重复，如是，则停止观察，
	并将该元素从数组删除，并开始当前位置字符的继续是否重复的判断，如果不是，则需要观察前两个字符，
	依次前推，如果一直没找到相同的字符，则需要将观察位置+1，继续判断
	*/
	while(s[i])
	{
		j = i - 1;
		while (j >= 0)
		{
			if (s[i] == s[j])//找到就需要退出while循环
				break;
			else
				j--;//没有找到，继续往前找
		}
		if (j < i&&j>=0)//如果确实找到了前面有效位置上相同的元素，则需要进行删除，直至最后\0字符复制给前面减1的位置，完成有效元素的自动减1
			for (k = i; s[k]; k++)
				s[k] = s[k + 1];
		else
			i++;//如果没有发现重复的元素则观察下一个位置
	}

}

int main()
{
	char s[20];
	scanf_s("%s", s,20);
	del_rep_word(s);
	printf_s("%s", s);
	return 0;
}

