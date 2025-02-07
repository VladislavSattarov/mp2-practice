#include <gtest.h>
#include "polinom.h"
#include "monom.h"
// ����� ������� � ���������

TEST(Monom, can_create_Monom_with_possitive_deg_less_999)
{
	ASSERT_NO_THROW(Monom m(5, 111));
}

TEST(Monom, cant_create_Monom_with_possitive_deg_gr_999)
{
	ASSERT_ANY_THROW(Monom m(5, 1111));
}

TEST(Monom, cant_create_Monom_with_negative_deg)
{
	ASSERT_ANY_THROW(Monom m(5, -111));
}

TEST(MonomList, can_create_MonomList)
{
	EXPECT_NO_THROW(MonomList M);
}

TEST(MonomList, insert_monom_correct) {
	MonomList M;
	auto it = M.begin();

	M.Insert(Monom(5, 10));
	M.Insert(Monom(5, 50));
	M.Insert(Monom(5, 100));
	++it; ++it;

	EXPECT_EQ(50, (*it).deg);
}

TEST(MonomList, copy_new_memory) {
	MonomList M;
	auto it1 = M.begin();
	M.Insert(Monom(5, 10));
	M.Insert(Monom(5, 50));
	M.Insert(Monom(5, 100));
	++it1; ++it1;

	MonomList L(M);
	auto it2 = L.begin();
	++it2; ++it2;
	(*it2).deg = 1;

	EXPECT_NE((*it1).deg, (*it2).deg);
}

TEST(MonomList, assigment_new_memory) {
	MonomList M;
	auto it1 = M.begin();
	M.Insert(Monom(5, 10));
	M.Insert(Monom(5, 50));
	M.Insert(Monom(5, 100));
	++it1; ++it1;

	MonomList L = M;
	auto it2 = L.begin();
	++it2; ++it2;
	(*it2).deg = 1;

	EXPECT_NE((*it1).deg, (*it2).deg);
}

TEST(Polinom, add_less_deg_monom)
{
	Polinom A("x^2 + 1"), B("x^2 + 5x + 1");;
	Monom m(5, 100);

	A += m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, add_gr_deg_monom)
{
	Polinom A("5x + 1"), B("x^2 + 5x + 1");
	Monom m(1, 200);

	A += m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, add_eq_deg_monom)
{
	Polinom A("x^2 + 5x + 1"), B("2x^2 + 5x + 1");
	Monom m(1, 200);

	A += m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, sub_less_deg_monom)
{
	Polinom A("x^2 + 1"), B("x^2 - 5x + 1");
	Monom m(5, 100);

	A -= m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, sub_gr_deg_monom)
{
	Polinom A("5x + 1"), B("-x^2 + 5x + 1");
	Monom m(1, 200);

	A -= m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, sub_eq_deg_monom)
{
	Polinom A("x^2 + 5x + 1"), B("5x + 1");
	Monom m(1, 200);

	A -= m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, mult_zero_cf_monom)
{
	Polinom A("x^3 + y^5 - 10z + 1"), B("0");
	Monom m = 0;

	A *= m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, throw_mult_big_digree_monom)
{
	Polinom A("x^5+5");
	Monom m(5, 555);

	ASSERT_ANY_THROW(A * m);
}

TEST(Polinom, mult_monom)
{
	Polinom A("x^5 - 5y^3 + 1.5z^5 + 1"), B("4x^6y^2z^3 - 20x^1y^5z^3 + 6x^1y^2z^8 + 4x^1y^2z^3");
	Monom m(4, 123);

	A = A * m;

	EXPECT_EQ(B, A);
}

TEST(Polinom, add_scalar)
{
	Polinom A("x^2 + 1"), B("x^2 + 6.1");

	A += 5.1;

	EXPECT_EQ(B, A);
}

TEST(Polinom, sub_scalar)
{
	Polinom A("x^2 + 1"), B("x^2 - 4.1");

	A -= 5.1;

	EXPECT_EQ(B, A);
}

TEST(Polinom, mult_zero)
{
	Polinom A("x^3 + y^5 - 10z + 1"), B("0");

	A *= 0.0;

	EXPECT_EQ(B, A);
}

TEST(Polinom, add_poly_eq_deg)
{
	Polinom A("5.43x^5y^4z^3 + 3.21x^3y^2z^1 - 1.23x^3 - 10.1"), B("5.43x^5y^4z^3 + 3.21x^3y^2z^1 - 1.23x^3 - 10.1"), res("10.86x^5y^4z^3 + 6.42x^3y^2z^1 - 2.46x^3 - 20.2");

	EXPECT_EQ(res, A + B);
}

TEST(Polinom, add_poly_ne_deg)
{
	Polinom A("y^9 + y^7 + y^5 + 5"), B("y^8 + y^6 + y^4 + y"), res("y^8 + y^6 + y^4 + y + y^9 + y^7 + y^5 + 5");

	EXPECT_EQ(res, A + B);
}

TEST(Polinom, sub_poly_eq_deg)
{
	Polinom A("5.43x^5y^4z^3 + 3.21x^3y^2z^1 - 1.23x^3 - 10.1"), B("4.43x^5y^4z^3 + 3.21x^3y^2z^1 - .23x^3 - 20.2"), res("1x^5y^4z^3 - x^3 + 10.1");

	EXPECT_EQ(res, A - B);
}

TEST(Polinom, sub_poly_ne_deg)
{
	Polinom A("y^9 + y^7 + y^5 + 5"), B("y^8 + y^6 + y^4 + y"), res("-y^8 - y^6 - y^4 - y + y^9 + y^7 + y^5 + 5");

	EXPECT_EQ(res, A - B);
}

TEST(Polinom, mult_poly1)
{
	Polinom A("x^3y^2z - x^4z^2"), B("x^3y^2z + x^4z^2"), res("x^6y^4z^2 - x^8z^4");

	EXPECT_EQ(res, A * B);
}

TEST(Polinom, mult_poly2)
{
	Polinom A("z"), B("z"), res("z^2");

	EXPECT_EQ(res, A * B);
}

TEST(Polinom, cant_mult_poly_with_big_deg)
{
	Polinom A("z^5"), B("z^5");

	ASSERT_ANY_THROW(A * B);
}

TEST(Polinom, calculate_in_point_correct)
{
	Polinom A("2.1x^5y^7 - 5.3z^9");
	double res = A(1.2, 3.3, 0.9);

	EXPECT_DOUBLE_EQ(22268.094717399301, res);
}

TEST(PolinomInput, throw_two_or_more_points)
{
	ASSERT_ANY_THROW(Polinom A("3.1x^5 + 4.5.1y"));
}

TEST(PolinomInput, no_throw_correct_points)
{
	ASSERT_NO_THROW(Polinom A("3.1x + 4.2x + 5.1xyz + .23"));
}

TEST(PolinomInput, throw_two_or_more_variables)
{
	ASSERT_ANY_THROW(Polinom A("x^5y + yz + zz"));
}

TEST(PolinomInput, throw_two_or_more_operation_signs)
{
	ASSERT_ANY_THROW(Polinom A("x + - y"));
}

TEST(PolinomInput, no_throw_first_operation_sign)
{
	ASSERT_NO_THROW(Polinom A("+ x + y"));
}

TEST(PolinomInput, throw_big_degree)
{
	ASSERT_ANY_THROW(Polinom A("x^5yz^10 + 1"));
}

TEST(PolinomInput, throw_negative_degree)
{
	ASSERT_ANY_THROW(Polinom A("x^-5yz + 1"));
}

TEST(PolinomInput, throw_wrong_symbols)
{
	ASSERT_ANY_THROW(Polinom A("xyz + 1 + M"));
}

TEST(PolinomInput, correct_input_only_scalar)
{
	Polinom A("5.1"), B;

	B += 5.1;

	EXPECT_EQ(B, A);
}

TEST(PolinomInput, correct_input_only_one_variable)
{
	Polinom A("y^5"), B;
	B += Monom(1, 50);

	EXPECT_EQ(B, A);
}

TEST(PolinomInput, correct_input_variables_with_first_degree)
{
	Polinom A("1+xyz"), B;
	B += 1;
	B += Monom(1, 111);

	EXPECT_EQ(B, A);
}

TEST(PolinomInput, correct_input_variables_with_zero_degree)
{
	Polinom A("1+xyz+x^0y^5z^0"), B;

	B += 1;
	B += Monom(1, 111);
	B += Monom(1, 50);

	EXPECT_EQ(B, A);
}

TEST(PolinomInput, correct_input_monoms_with_same_degree)
{
	Polinom A("1 + xyz + x^1y^1z^1 + 10.1 - 0.7xyz"), B;
	B += 11.1;
	B += Monom(1.3, 111);

	EXPECT_EQ(B, A);
}

TEST(PolinomInput, correct_input_monom_with_zero_cf)
{
	Polinom A("1 + xyz - x^1y^1z^1 + 10.1"), B;

	B += 11.1;

	EXPECT_EQ(B, A);
}

TEST(Polinom, add1)
{
	Polinom P("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	Polinom Q("4x^3y^2z^6 - 6x^2yz^8");
	Polinom res("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z + 4x^3y^2z^6 - 6x^2yz^8");
	EXPECT_EQ(res, P + Q);
}

TEST(Polinom, add2)
{
	Polinom P("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	Polinom Q("4x^7y^2z^6 - 6x^6yz^8");
	Polinom res("4x^7y^2z^6 - 6x^6yz^8 + 3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	EXPECT_EQ(res, P + Q);
}

TEST(Polinom, add3)
{
	Polinom P("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	Polinom Q("4x^5y^2z^5 + 5x^4y^3z^3");
	Polinom res("7x^5y^2z^5 + 7x^3y^5z");
	EXPECT_EQ(res, P + Q);
}

TEST(Polinom, add4)
{
	Polinom P("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^7y^5z");
	Polinom Q("4x^6y^2z^6 - 6x^2yz^8");
	Polinom res("7x^7y^5z + 4x^6y^2z^6 + 3x^5y^2z^5 - 5x^4y^3z^3 - 6x^2yz^8");
	EXPECT_EQ(res, P + Q);
}

TEST(Polinom, add5)
{
	Polinom P("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^7y^5z");
	Polinom Q("-3x^5y^2z^5 + 5x^4y^3z^3 - 7x^7y^5z");
	Polinom res("0");
	EXPECT_EQ(res, P + Q);
}

TEST(Polinom, mult1)
{
	Polinom P("1-x");
	Polinom Q("1+x");
	Polinom res("1-x^2");
	EXPECT_EQ(res, P * Q);
}

TEST(Polinom, mult2)
{
	Polinom P("x-1");
	Polinom Q("1+x");
	Polinom res("1-x^2");
	EXPECT_EQ(res, P * Q);
}

TEST(Polinom, mult3)
{
	Polinom P("1-x");
	Polinom Q("1+x");
	Polinom res("1-x^2");
	EXPECT_EQ(res, Q * P);
}

TEST(Polinom, mult4)
{
	Polinom P("x-1");
	Polinom Q("1+x");
	Polinom res("1-x^2");
	EXPECT_EQ(res, Q * P);
}