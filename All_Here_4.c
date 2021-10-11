#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#define n 100
#include <math.h>
#include <stdbool.h>


void f1() {
	long long int a_beg, b_beg;
	printf("Введите два целых числа, больших или равных 0:\n");
	scanf_s("%lld%lld", &a_beg, &b_beg);
	while ((a_beg == 0 && b_beg == 0) || a_beg < 0 || b_beg < 0)
	{
		if (a_beg == 0 && b_beg == 0)
		{
			printf("Оба значения не могут быть равны 0.\nВведите значения заново:\n");
			scanf_s("%lld%lld", &a_beg, &b_beg);
		}
		else
		{
			printf("Введённое число не может быть меньше 0.\nВведите значения заново:\n");
			scanf_s("%lld%lld", &a_beg, &b_beg);
		}
	}
	if (a_beg == b_beg)
	{
		printf("Так как введённые числа равны, то наибольший общий делитель введённых чисел равен %lld.\n", a_beg);
	}
	else if ((a_beg == 0 && b_beg != 0) || (b_beg == 0 && a_beg != 0))
	{
		if (a_beg == 0 && b_beg != 0)
		{
			printf("Так как первое число равно 0, то наибольший общий делитель введённых чисел равен второму числу %lld.\n", b_beg);
		}
		else
		{
			printf("Так как второе число равно 0, то наибольший общий делитель введённых чисел равен первому числу %lld.\n", a_beg);
		}
	}
	else 
	{
		bool a_beg_simple = true, b_beg_simple = true;
		for (int i = 2; i < a_beg / 2 + 1; i++)
		{
			if (a_beg % i == 0)
			{
				a_beg_simple = false;
				break;
			}
		}
		for (int i = 2; i < b_beg / 2 + 1; i++)
		{
			if (b_beg % i == 0)
			{
				b_beg_simple = false;
				break;
			}
		}
		if (a_beg_simple && b_beg_simple)
		{
			printf("Так как введённые числа %lld и %lld взаимно простые, то их наибольший общий делитель - число 1.\n", a_beg, b_beg);
		}
		else if ((a_beg_simple && a_beg > b_beg) || (b_beg_simple && b_beg > a_beg))
		{
			printf("Наибольший общий делитель чисел %lld и %lld - число 1 (case_1).\n", a_beg, b_beg);
		}
		else
		{
			long long int a = a_beg, b = b_beg;
			// Через вычитание:
			while (a !=0 && b != 0)
			{
				if (a > b)
				{
					a = a - b;
				}
				else
				{
					b = b - a;
				}
			}
			printf("Наибольший общий делитель чисел %lld и %lld - число %lld (case_2).\n", a_beg, b_beg, a+b);
			// Через остаток от деления:
			while (a != 0 && b != 0)
			{
				if (a > b && b != 0)
				{
					a = a % b;
				}
				else if (a != 0)
				{
					b = b % a;
				}
			}
			printf("Наибольший общий делитель чисел %lld и %lld - число %lld (case_3).\n", a_beg, b_beg, a+b);
		}
	}
	
}


void f2() {
	int mass[n] = { 0 };
	for (int i = 2; i*i < n; i++)
	{
		if ((i != 2 && i % 2 == 0) || (i != 5 && (i % 10 == 5 || i % 10 == 0)))
		{
			continue;
		}
		if (mass[i] == 0)
		{
			for (int j = i * i; j < n; j += i)
			{
				mass[j] = 1;
			}
		}
	}
	printf("Простые числа до ограничителя %d:\n", n);
	for (int i = 2; i < n; i++)
	{
		if (mass[i] == 0)
		{
			printf("%d\n", i);
		}
	}
}


int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	printf("Номер задачи не превышает 2.\nЧтобы закончить работу, введите 0.\n");
	printf("Введите номер задачи: \n");
	scanf_s("%d", &counter);
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		default:
			printf("Номер задачи не превышает 2.\nЧтобы закончить работу, введите 0.\n");
			break;
		}
		printf("Введите номер следующей задачи: \n");
		scanf_s("%d", &counter);
	}
	return 0;
}