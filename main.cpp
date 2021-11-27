#include "bignum.h"
#include <iostream>

//int main(int argc, char* argv[])
int main()
{

	//try
	//{
	//	const std::string c{ "+" };
	//	BigNum num3(c);
	//}
	//catch (const char* e)
	//{
	//	std::cout << e << std::endl;
	//}

	int64_t a = +150;
	int64_t b = 600;

	const std::string c{ "-0000150" };
	const std::string d{ "-0000600" };

	BigNum num1 = a;
	BigNum num2 = b;
	BigNum num3(c);
	BigNum num4(d);
	BigNum num5;

	std::cout << "----------print----------" << std::endl;
	std::cout << num1 << " (150)" << std::endl;
	std::cout << num2 << " (600)" << std::endl;
	std::cout << num3 << " (-150)" << std::endl;
	std::cout << num4 << " (-600)" << std::endl;
	std::cout << num5 << " (0)" << std::endl;

	std::cout << "----------add----------" << std::endl;
	std::cout << num1 + num2 << " (750)" << std::endl;
	std::cout << num3 + num4 << " (-750)" << std::endl;
	std::cout << num3 + num2 << " (450)" << std::endl;
	std::cout << num1 + num4 << " (-450)" << std::endl;
	std::cout << num2 + num1 << " (750)" << std::endl;
	std::cout << num4 + num3 << " (-750)" << std::endl;
	std::cout << num2 + num3 << " (450)" << std::endl;
	std::cout << num4 + num1 << " (-450)" << std::endl;
	std::cout << num5 + num5 << " (0)" << std::endl;

	std::cout << "----------sub----------" << std::endl;
	std::cout << num1 - num2 << " (-450)" << std::endl;
	std::cout << num3 - num4 << " (450)" << std::endl;
	std::cout << num3 - num2 << " (-750)" << std::endl;
	std::cout << num1 - num4 << " (750)" << std::endl;
	std::cout << num2 - num1 << " (450)" << std::endl;
	std::cout << num4 - num3 << " (-450)" << std::endl;
	std::cout << num2 - num3 << " (750)" << std::endl;
	std::cout << num4 - num1 << " (-750)" << std::endl;
	std::cout << num1 - num1 << " (0)" << std::endl;

	std::cout << "----------mul----------" << std::endl;
	std::cout << num1 * num2 << " (90000)" << std::endl;
	std::cout << num3 * num4 << " (90000)" << std::endl;
	std::cout << num3 * num2 << " (-90000)" << std::endl;
	std::cout << num1 * num4 << " (-90000)" << std::endl;

	std::cout << "---------ord ==----------" << std::endl;
	std::cout << (num1 == num1) << " (1)" << std::endl;
	std::cout << (num1 == num2) << " (0)" << std::endl;
	std::cout << (num1 == num3) << " (0)" << std::endl;
	std::cout << (num1 == num3) << " (0)" << std::endl;
	std::cout << "---------ord !=----------" << std::endl;
	std::cout << (num1 != num1) << " (0)" << std::endl;
	std::cout << (num1 != num2) << " (1)" << std::endl;
	std::cout << (num1 != num3) << " (1)" << std::endl;
	std::cout << (num1 != num4) << " (1)" << std::endl;
	std::cout << "---------ord <----------" << std::endl;
	std::cout << (num1 < num1) << " (0)" << std::endl;
	std::cout << (num1 < num2) << " (1)" << std::endl;
	std::cout << (num1 < num3) << " (0)" << std::endl;
	std::cout << (num1 < num4) << " (0)" << std::endl;
	std::cout << "---------ord <=----------" << std::endl;
	std::cout << (num1 <= num1) << " (1)" << std::endl;
	std::cout << (num1 <= num2) << " (1)" << std::endl;
	std::cout << (num1 <= num3) << " (0)" << std::endl;
	std::cout << (num1 <= num4) << " (0)" << std::endl;
	std::cout << "---------ord >----------" << std::endl;
	std::cout << (num1 > num1) << " (0)" << std::endl;
	std::cout << (num1 > num2) << " (0)" << std::endl;
	std::cout << (num1 > num3) << " (1)" << std::endl;
	std::cout << (num1 > num4) << " (1)" << std::endl;
	std::cout << "---------ord >-----------" << std::endl;
	std::cout << (num1 >= num1) << " (1)" << std::endl;
	std::cout << (num1 >= num2) << " (0)" << std::endl;
	std::cout << (num1 >= num3) << " (1)" << std::endl;
	std::cout << (num1 >= num4) << " (1)" << std::endl;

	std::cout << "----------unary '+'----------" << std::endl;
	std::cout << +num1 << " (150)" << std::endl;
	std::cout << +num2 << " (600)" << std::endl;
	std::cout << +num3 << " (-150)" << std::endl;
	std::cout << +num4 << " (-600)" << std::endl;
	std::cout << +num5 << " (0)" << std::endl;

	std::cout << "----------unary '-'----------" << std::endl;
	std::cout << -num1 << " (-150)" << std::endl;
	std::cout << -num2 << " (-600)" << std::endl;
	std::cout << -num3 << " (150)" << std::endl;
	std::cout << -num4 << " (600)" << std::endl;
	std::cout << -num5 << " (0)" << std::endl;

	std::cout << "---------unary '='-----------" << std::endl;
	num1 = num3;
	num4 = num2;
	num3 = BigNum(8);
	num2 = BigNum(10);
	std::cout << num1 << " (-150)" << std::endl;
	std::cout << num2 << " (10)" << std::endl;
	std::cout << num3 << " (8)" << std::endl;
	std::cout << num4 << " (600)" << std::endl;
	std::cout << num5 << " (0)" << std::endl;



	return 0;
}
