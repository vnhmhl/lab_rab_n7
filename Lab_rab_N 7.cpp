#include <iostream>
#include <math.h>
using namespace std;

typedef float(*fptr)(float);//тип-указатель на функцию уравнения

/*решение уравнения методом половинного деления, уравнение передается с помощью указателя на функцию */
float root(fptr f, float a, float b, float e)
{
	float x;
	do
	{
		x = (a + b) / 2;			//находим середину отрезка
		if ((*f)(a) * f(x) < 0)		//выбираем отрезок
			b = x;
		else a = x;
	} while (fabs((b - a) / 2) > e);
	return x;
}

//функция, для которой ищется корень
float testf(float x)
{
	return 3 * sin(sqrt(x)) + 0.35 * x - 3.8; //записываем функцию
}

void main()
{
	setlocale(LC_ALL, "Russian");
	/*в функцию root передается указатель на функцию, координаты отрезка и точность */
	float res = root(testf, 2, 3, 0.00001);
	float res1 = floor(res * 10000) / 10000; //округляем число до 4 знаков после запятой
	cout << "\nРешение уравнения при помощи метода половинного деления" << endl;
	cout << "на отрезке [2;3] принимает точное значение: X = " << res1 << endl;//выводим полученное значение
}