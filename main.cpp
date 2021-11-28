#include "bignum.h"
#include <iostream>
#include <sstream>

void input_tests()
{
	int64_t error_counter = 0;

	BigNum a = 1;
	BigNum b = -2;

	BigNum c(3);
	BigNum d(-4);

	BigNum e{ 5 };
	BigNum f{ -6 };

	BigNum g("7");
	BigNum h("-8");
	BigNum i("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	
	try { BigNum j("-"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum k("+"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum l("a"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum m("-b"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum n("+c"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	BigNum o("000000000000000000000");
	BigNum p("000000000000000000000400");
	try { BigNum q("000000000000000000000d"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	
	BigNum r{ "7" };
	BigNum s{ "-8" };
	try { BigNum t{ "-" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum u{ "+" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum v{ "a" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum w{ "-b" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum x{ "+c" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	BigNum y{ "000000000000000000000" };
	BigNum z{ "000000000000000000000400" };
	try { BigNum aa{ "000000000000000000000d" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }

	BigNum ab;
	BigNum ac = 0;
	BigNum ad(0);
	BigNum ae{ 0 };
	BigNum af("0");
	BigNum ag{ "0" };

	BigNum ah(+0);
	BigNum ai{ +0 };
	BigNum aj("+0");
	BigNum ak{ "+0" };

	BigNum al(-0);
	BigNum am{ -0 };
	BigNum an("-0");
	BigNum ao{ "-0" };

	try { BigNum ap(" 0"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum aq("0 "); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum ar(" +0"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum as(" -0"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum at("+0 "); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum au("-0 "); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }

	try { BigNum av{ " 0" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum aw{ "0 " }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum ax{ " +0" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum ay{ " -0" }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum az{ "+0 " }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum ba{ "-0 " }; std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }

	BigNum bb{ +123 };
	BigNum bc{ 123 };
	BigNum bd{ -123 };
	BigNum be{ +000123 };
	BigNum bf{ 000123 };
	BigNum bg{ -000123 };
	BigNum bh{ +0000 };
	BigNum bi{ 0000 };
	BigNum bj{ -0000 };
	BigNum bk{ -0 };
	BigNum bl{ 0 };
	BigNum bm{ +0 };

	try { BigNum bn("+123w"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bo("123w"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bp("-123w"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bq("+w123"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum br("w123"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bs("-w123"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bt("+1w23"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bu("1w23"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bv("-1w23"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bw("+0w00123"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bx("0w00123"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum by("-0w00123"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum bz("+00w00"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum ca("00w00"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum cb("-00w00"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum cc("+0000w"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum cd("0000w"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }
	try { BigNum ce("-0000w"); std::cout << "You shouldn't see this" << std::endl; } catch (std::exception& e) { e; error_counter++; }

	if (error_counter != 42)
	{
		std::cout << "Some errors unhandled" << std::endl;
	}
}

void dummy_test()
{
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
}

int _compare_str_unary(BigNum num, int64_t exp_num, BigNum a, const char* sign)
{
	std::stringstream ss;
	ss << num;

	std::string expected = std::to_string(exp_num);

	if (ss.str() != expected)
	{
		std::cout << "Returned: " << ss.str() << " Expected: " << expected << " For: " << sign << a << std::endl;
		return 1;
	}

	return 0;
}

int _compare_str(BigNum num, int64_t exp_num, BigNum a, BigNum b, const char* sign)
{
	std::stringstream ss;
	ss << num;

	std::string expected = std::to_string(exp_num);

	if (ss.str() != expected)
	{
		std::cout << "Returned: " << ss.str() << " Expected: " << expected << " For: " << a << sign << b << std::endl;
		return 1;
	}

	return 0;
}

int _compare_bool(bool x, bool y, BigNum a, BigNum b, const char* sign)
{
	if (x != y)
	{
		std::cout << "Returned: " << x << " Expected: " << y << " For: " << a << sign << b << std::endl;
		return 1;
	}

	return 0;
}

void operations_tests(int64_t start, int64_t end, bool progress=false)
{
	std::cout << "---------Start of operations tests---------" << std::endl;

	int64_t error_count = 0;

	for (int64_t i = start; i < end; i++)
	{
		for (int64_t j = start; j < end; j++)
		{
			BigNum a(i);
			BigNum b(j);

			error_count += _compare_str_unary(a, i, a, "");
			error_count += _compare_str_unary(b, j, b, "");
			error_count += _compare_str_unary(-a, -i, a, "-");
			error_count += _compare_str_unary(-b, -j, b, "-");
			error_count += _compare_str_unary(+a, +i, a, "+");
			error_count += _compare_str_unary(+b, +j, b, "+");

			error_count += _compare_str(a + b, i + j, a, b, "+");
			error_count += _compare_str(b + a, j + i, b, a, "+");
			error_count += _compare_str(a - b, i - j, a, b, "-");
			error_count += _compare_str(b - a, j - i, b, a, "-");
			error_count += _compare_str(a * b, i * j, a, b, "*");
			error_count += _compare_str(b * a, j * i, b, a, "*");
			error_count += _compare_bool(a == a, i == i, a, b, "==");
			error_count += _compare_bool(b == b, j == j, a, b, "==");
			error_count += _compare_bool(a == b, i == j, a, b, "==");
			error_count += _compare_bool(a != b, i != j, a, b, "!=");
			error_count += _compare_bool(a < b, i < j, a, b, "<");
			error_count += _compare_bool(a <= b, i <= j, a, b, "<=");
			error_count += _compare_bool(a > b, i > j, a, b, ">");
			error_count += _compare_bool(a >= b, i >= j, a, b, ">=");

			error_count += _compare_str(-a + b, -i + j, -a, b, "+");
			error_count += _compare_str(b + -a, j + -i, b, -a, "+");
			error_count += _compare_str(-a - b, -i - j, -a, b, "-");
			error_count += _compare_str(b - -a, j - -i, b, -a, "-");
			error_count += _compare_str(-a * b, -i * j, -a, b, "*");
			error_count += _compare_str(b * -a, j * -i, b, -a, "*");
			error_count += _compare_bool(-a == b, -i == j, -a, b, "==");
			error_count += _compare_bool(-a != b, -i != j, -a, b, "!=");
			error_count += _compare_bool(-a < b, -i < j, -a, b, "<");
			error_count += _compare_bool(-a <= b, -i <= j, -a, b, "<=");
			error_count += _compare_bool(-a > b, -i > j, -a, b, ">");
			error_count += _compare_bool(-a >= b, -i >= j, -a, b, ">=");

			error_count += _compare_bool(a == -b, i == -j, a, -b, "==");
			error_count += _compare_bool(a != -b, i != -j, a, -b, "!=");
			error_count += _compare_bool(a < -b, i < -j, a, -b, "<");
			error_count += _compare_bool(a <= -b, i <= -j, a, -b, "<=");
			error_count += _compare_bool(a > -b, i > -j, a, -b, ">");
			error_count += _compare_bool(a >= -b, i >= -j, a, -b, ">=");

			error_count += _compare_str((-(-a + b + a + a - b) - (b - b + a - a - a + b - a + b)), 
				(-(-i + j + i + i - j) - (j - j + i - i - i + j - i + j)), a, b, " special1 ");

			error_count += _compare_str((-(-a * (b + a) + a - b) * (b - b + a - (a * a) + b - a + b)),
				(-(-i * (j + i) + i - j) * (j - j + i - (i * i) + j - i + j)), a, b, "special2");

			a = -b;
			b = -a;
			error_count += _compare_str_unary(a, -j, a, "");
			error_count += _compare_str_unary(b, j, b, "");
		}
		if (progress) std::cout << "Testing " << i << std::endl;
	}
	std::cout << "Error count " << error_count << std::endl;
	std::cout << "---------End of operations tests---------" << std::endl;
}

void _compare_stream(std::string str)
{
	std::stringstream ss1(str);
	int a = 1;
	ss1 >> a;

	std::stringstream ss2(str);
	BigNum b = 2;
	ss2 >> b;

	_compare_str_unary(b, a, a, "");
	if (ss1.fail() != ss2.fail())
	{
		std::cout << "Failbit error" << std::endl;
		std::cout << str << " " << a << " " << b << std::endl;
	}

}

void bonus_stream_test()
{
	std::cout << "---------Start of stream tests---------" << std::endl;

	for (int64_t i = -1000; i < 1000; i++)
	{
		_compare_stream(std::to_string(i));
	}
	
	_compare_stream("-xyz");
	_compare_stream("+xyz");
	_compare_stream("-12z");
	_compare_stream("+12z");
	_compare_stream("-x1z");
	_compare_stream("+x1z");
	_compare_stream("xyz");
	_compare_stream("xyz");
	_compare_stream("12z");
	_compare_stream("12z");
	_compare_stream("x1z");
	_compare_stream("x1z");

	std::cout << "---------End of stream tests---------" << std::endl;
}

int main()
{
	input_tests();

	//dummy_test();

	//operations_tests(-1000, 1000, 0);

	//bonus_stream_test();

	return 0;
}
