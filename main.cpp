// ���������, ������� ������� ��������
// 1.������� ������� (sin x, cos x, x, x^2) 2.������� ����� ������������� 
// 3.������� ��� ���-�� � ��������� 4.������������� (�������� ���-�) 5.�����

#include <functional>
#include <iostream>
#include <clocale>
#include <cmath>

double cos_fun(double x) {
	return cos(x);
}

double sin_fun(double x) {
	return sin(x);
}

double x_func(double x) {
	return x;
}

double x_square_func(double x) {
	return x * x;
}

std::function<double(double)> f_cos = cos_fun;

std::function<double(double)> f_sin = sin_fun;

double trapezoidalIntegral(double& a, double& b, int n, const std::function<double(double)>& f);
double stolbikIntegral(double& a, double& b, int n, const std::function<double(double)>& f);


int main() {
	setlocale(LC_ALL, "Russian");

	int action{ 0 };
	int choice{ 0 };
	int method{ 0 };

	int* method_flag = &method;

	double a{ 0 };		//������� ��������������
	double b{ 0 };

	int n{ 0 };		// ����� ����������� ���������

	double delta{ 0 }; // ��� ��������������

	std::function<double(double)> f;		//��������������� �������

	std::cout << "1 - ������� �������" << "\n" << "2 - ������� ����� ��������������" << "\n" <<
		"3 - ������� ��� �������������� � ��������" << "\n" << "4 - �������������" <<
		"\n" << "5 - �����" << "\n";

	if(bool cond = true){
		while (true) {
			std::cout << "choose your fighter" << "\n";
			std::cin >> action;

			switch (action) {
			case 1:
				std::cout << "�������� �������: 1- cos, 2- sin, 3- x, 4- x^2" << "\n";
				std::cin >> choice;
				switch (choice) {
				case 1: 
					f = cos_fun;
					break;
				case 2:
					f = sin_fun;
					break;
				case 3: 
					f = x_func;
					break;
				case 4:
					f = x_square_func;
					break;
				default: std::cout << "������� 1 ��� 2  ��� 3 ��� 4 !!!";
					break;
				}
				break;

			case 2:
				std::cout << "�������� ����� ��������������: 1 - ��������, 2 - ����������" << "\n";
				std::cin >> choice;

				switch (choice) {
				case 1:
					*method_flag = 1;
					break;

				case 2:
					*method_flag = 2;
					break;

				default: std::cout << "������� 1 ��� 2!";
					break;
				}

				break;

			case 3:
				std::cout << "�������� ��� � �������� ��������������: 1 - ���, 2 - ��������" << "\n";
				std::cin >> choice;

				switch (choice) {
				case 1:
					std::cin >> delta;
					break;

				case 2:
					std::cin >> a >> b;
					break;

				default: std::cout << "������� 1 ��� 2!";
					break;
				}

				n = (uint32_t)(b - a) / delta;
				break;

			case 4:
				if (*method_flag == 1) {
					double ans{ 0 };
					ans = trapezoidalIntegral(a, b, n, f);
					std::cout << ans << "\n";
				}

				if (*method_flag == 2) {
					double ans{ 0 };
					ans = stolbikIntegral(a, b, n, f);
					std::cout << ans << "\n";
				}
				break;

			case 5:
				cond = false;
				break;

			default: std::cout << "bye bye!";
				break;
			}
		}
	}
	
	/*  #include <functional>
		std::function <double(double)> var;			������ �������, �� ���� �++14
	*/


}double trapezoidalIntegral(double& a, double& b, int n, const std::function<double(double)>& f) {
	const double width = (b - a) / n;

	double trapezoidal_integral = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = a + step * width;
		const double x2 = a + (step + 1) * width;

		trapezoidal_integral += 0.5 * (x2 - x1) * (f(x1) + f(x2));
	}

	return trapezoidal_integral;
}

double stolbikIntegral(double& a, double& b, int n, const std::function<double(double)>& f) {
	const double width = (b - a) / n;

	double stolbik_integral = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = a + step * width;
		const double x2 = a + (step + 1) * width;

		stolbik_integral += f(x1) * (x2 - x1);
	}

	return stolbik_integral;
}
