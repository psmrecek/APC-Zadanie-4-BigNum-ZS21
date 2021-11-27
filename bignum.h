#pragma once

// here you can include whatever you want :)
#include <string>
#include <stdint.h>
#include <iostream>

#define SUPPORT_DIVISION 0 // define as 1 when you have implemented the division
#define SUPPORT_IFSTREAM 0 // define as 1 when you have implemented the input >>

// if you do not plan to implement bonus, just delete those lines
class BigNum final
{
public:
    friend std::ostream& operator<<(std::ostream& lhs, const BigNum& rhs);
    friend bool operator==(const BigNum& lhs, const BigNum& rhs);
    friend bool operator!=(const BigNum& lhs, const BigNum& rhs);
    friend bool operator<(const BigNum& lhs, const BigNum& rhs);
    friend bool operator>(const BigNum& lhs, const BigNum& rhs);
    friend bool operator<=(const BigNum& lhs, const BigNum& rhs);
    friend bool operator>=(const BigNum& lhs, const BigNum& rhs);
    // constructors
    BigNum() : m_number{ "0" }, m_positive{ true } {}
    BigNum(int64_t n)
    {
        if (n < 0)
        {
            m_positive = false;
            n *= -1;
        }
        else
        {
            m_positive = true;
        }
        m_number = std::to_string(n);
    }
    explicit BigNum(const std::string& str)
    {
        if (str.length() == 0)
        {
            m_number = "0";
            m_positive = true;
        }
        else
        {
            bool ignore_first = false;
            if (str[0] == '-')
            {
                m_positive = false;
                ignore_first = true;
            }
            else if (str[0] == '+')
            {
                m_positive = true;
                ignore_first = true;
            }
            else
            {
                m_positive = true;
                ignore_first = false;
            }

            std::string new_str = str;
            if (ignore_first)
            {
                if (str.length() == 1) throw "Unable to construct BigNum";
                new_str = str.substr(1);
            }

            for (size_t i = 0; i < new_str.length(); i++)
            {
                if (std::isdigit(new_str[i]) == 0) throw "Unable to construct BigNum";
            }
            size_t not_zero = new_str.find_first_not_of("0");
            if (not_zero == std::string::npos)
            {
                m_number = "0";
                m_positive = true;
            }
            else
            {
                m_number = new_str.substr(not_zero);
            }
        }
    }

    // copy
    BigNum(const BigNum& other) = default;
    BigNum& operator=(const BigNum& rhs)
    {
        m_number = rhs.m_number;
        m_positive = rhs.m_positive;
        return *this;
    }

    // unary operators
    const BigNum& operator+() const
    {
        return *this;
    }

    BigNum operator-() const
    {
        BigNum new_bignum = *this;
        if (new_bignum.m_number == "0")
        {
            new_bignum.m_positive = true;
        }
        else
        {
            new_bignum.m_positive = !new_bignum.m_positive;
        }
        return new_bignum;
    }

    // binary arithmetics operators
    BigNum& operator+=(const BigNum& rhs)
    {
        std::string num1{ m_number };
        std::string num2{ rhs.m_number };

        if (m_positive && rhs.m_positive)
        {
            m_number = help_add(num1, num2);
            m_positive = true;
        }
        
        if (!m_positive && !rhs.m_positive)
        {
            m_number = help_add(num1, num2);
            m_positive = false;
        }

        if ((m_positive && !rhs.m_positive) || (!m_positive && rhs.m_positive))
        {
            m_number = help_sub(rhs);
        }

        return *this;
    }
    BigNum& operator-=(const BigNum& rhs)
    {
        std::string num1{ m_number };
        std::string num2{ rhs.m_number };

        if (m_positive && !rhs.m_positive)
        {
            m_number = help_add(num1, num2);
            m_positive = true;
        }

        if (!m_positive && rhs.m_positive)
        {
            m_number = help_add(num1, num2);
            m_positive = false;
        }
        
        if ((m_positive && rhs.m_positive) || (!m_positive && !rhs.m_positive))
        {
            m_number = help_sub(rhs);
        }

        return *this;
    }
    BigNum& operator*=(const BigNum& rhs)
    {

        if (m_number == "0" || rhs.m_number == "0")
        {
            m_number = "0";
            m_positive = true;
            return *this;
        }

        if ((m_positive && rhs.m_positive) || (!m_positive && !rhs.m_positive))
        {
            m_positive = true;
        }
        else
        {
            m_positive = false;
        }

        std::string num1{ m_number };
        std::string num2{ rhs.m_number };

        int64_t len1 = num1.length();
        int64_t len2 = num2.length();

        char zero = '0';
        int64_t id1 = 0;
        int64_t id2 = 0;
        std::string result{ "" };
        result.resize(len1 + len2, zero);

        for (int64_t i = len1 - 1; i >= 0; i--)
        {
            int64_t carry = 0;
            int64_t intermediate1 = num1[i] - zero;
            id2 = 0;   

            for (int64_t j = len2 - 1; j >= 0; j--)
            {
                int64_t intermediate2 = num2[j] - zero;
                int64_t sum =  result[id1 + id2] - zero + intermediate1 * intermediate2 + carry;
                result[id1 + id2] = sum % 10 + zero;
                carry = sum / 10;
                id2++;
            }

            if (carry > 0)
            {
                result[id1 + id2] += (char)carry;
            }

            id1++;
        }

        reverse_and_delete_zero(result);

        m_number = result;

        return *this;
    }

#if SUPPORT_DIVISION == 1
    BigNum& operator/=(const BigNum& rhs); // bonus
    BigNum& operator%=(const BigNum& rhs); // bonus
#endif

private:
    // here you can add private data and members, but do not add stuff to 
    // public interface, also you can declare friends here if you want
    std::string m_number{ "0" };
    bool m_positive = true;

    std::string help_add(std::string& num1, std::string& num2)
    {
        if (num1.length() > num2.length())
        {
            std::swap(num1, num2);
        }

        int64_t len1 = num1.length();
        int64_t len2 = num2.length();
        int64_t diff = len2 - len1;

        std::string result{ "" };
        int64_t carry = 0;
        char zero = '0';

        for (int64_t i = len1 - 1; i >= 0; i--)
        {
            int64_t intermediate = ((num1[i] - zero) + (num2[i + diff] - zero) + carry);
            result.push_back(intermediate % 10 + zero);
            carry = intermediate / 10;
        }

        for (int64_t i = len2 - len1 - 1; i >= 0; i--)
        {
            int64_t intermediate = ((num2[i] - zero) + carry);
            result.push_back(intermediate % 10 + zero);
            carry = intermediate / 10;
        }

        if (carry > 0)
        {
            int64_t intermediate = carry + '0';
            result.push_back((char)intermediate);
        }

        std::reverse(result.begin(), result.end());

        return result;
    }

    void reverse_and_delete_zero(std::string& result)
    {
        std::reverse(result.begin(), result.end());

        size_t not_zero = result.find_first_not_of("0");
        if (not_zero == std::string::npos)
        {
            result = "0";
            m_positive = true;
        }
        else
        {
            result = result.substr(not_zero);
        }
    }

    std::string help_sub(const BigNum& rhs)
    {
        std::string num1{ m_number };
        std::string num2{ rhs.m_number };

        if (num1 == num2)
        {
            m_positive = true;
            return "0";
        }

        int64_t len1 = num1.length();
        int64_t len2 = num2.length();
        int64_t diff = len2 - len1;

        bool flip = false;
        if (diff > 0)
        {
            flip = true;
        }
        else if (diff < 0)
        {
            flip = false;
        }
        else
        {
            for (int64_t i = 0; i < len1; i++)
            {
                if (num1[i] < num2[i])
                {
                    flip = true;
                    break;
                }
                else if (num1[i] > num2[i])
                {
                    flip = false;
                    break;
                }
            }
        }

        if (flip)
        {
            std::swap(num1, num2);
            m_positive = !m_positive;
        }

        len1 = num1.length();
        len2 = num2.length();
        diff = len2 - len1;

        std::string result{ "" };
        int64_t carry = 0;
        char zero = '0';

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        for (int64_t i = 0; i < len2; i++) {
            int64_t intermediate = ((num1[i] - zero) - (num2[i] - zero) - carry);
            if (intermediate < 0) 
            {
                intermediate = intermediate + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            intermediate += zero;
            result.push_back((char)intermediate);
        }

        for (int64_t i = len2; i < len1; i++) {
            int64_t intermediate = ((num1[i] - zero) - carry);
            if (intermediate < 0) 
            {
                intermediate = intermediate + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            intermediate += zero;
            result.push_back((char)intermediate);
        }

        reverse_and_delete_zero(result);

        return result;
    }
};

BigNum operator+(BigNum lhs, const BigNum& rhs)
{
    return lhs += rhs;
}
BigNum operator-(BigNum lhs, const BigNum& rhs)
{
    return lhs -= rhs;
}
BigNum operator*(BigNum lhs, const BigNum& rhs)
{
    return lhs *= rhs;
}

#if SUPPORT_DIVISION == 1
BigNum operator/(BigNum lhs, const BigNum& rhs); // bonus
BigNum operator%(BigNum lhs, const BigNum& rhs); // bonus
#endif

// alternatively you can implement 
// std::strong_ordering operator<=>(const BigNum& lhs, const BigNum& rhs);
// idea is, that all comparison should work, it is not important how you do it
bool operator==(const BigNum& lhs, const BigNum& rhs)
{
    return ((lhs.m_number == rhs.m_number) && (lhs.m_positive == rhs.m_positive));
}
bool operator!=(const BigNum& lhs, const BigNum& rhs)
{
    return !operator==(lhs, rhs);
}
bool operator<(const BigNum& lhs, const BigNum& rhs)
{
    if (operator==(lhs, rhs))
    {
        return false;
    }

    if (!lhs.m_positive && rhs.m_positive)
    {
        return true;
    }

    if (lhs.m_positive && !rhs.m_positive)
    {
        return false;
    }

    int64_t len1 = lhs.m_number.length();
    int64_t len2 = rhs.m_number.length();
    int64_t diff = len2 - len1;

    bool return_value_true = true;
    bool return_value_false = false;

    if (!lhs.m_positive && !rhs.m_positive)
    {
        return_value_true = false;
        return_value_false = true;
    }

    if (diff > 0)
    {
        return return_value_true;
    }
    else if (diff < 0)
    {
        return return_value_false;
    }
    else
    {
        std::string num1{ lhs.m_number };
        std::string num2{ rhs.m_number };
        for (int64_t i = 0; i < len1; i++)
        {
            if (num1[i] < num2[i])
            {
                return return_value_true;
            }
            else if (num1[i] > num2[i])
            {
                return return_value_false;
            }
        }
    }
    return return_value_false;
}
bool operator>(const BigNum& lhs, const BigNum& rhs)
{
    return !operator==(lhs, rhs) && !operator<(lhs, rhs);
}
bool operator<=(const BigNum& lhs, const BigNum& rhs)
{
    return operator==(lhs, rhs) || operator<(lhs, rhs);
}
bool operator>=(const BigNum& lhs, const BigNum& rhs)
{
    return operator==(lhs, rhs) || operator>(lhs, rhs);
}


std::ostream& operator<<(std::ostream& lhs, const BigNum& rhs)
{
    if (rhs.m_positive)
    {
        lhs << rhs.m_number;
    }
    else
    {
        lhs << "-" << rhs.m_number;
    }
    
    return lhs;
}

#if SUPPORT_IFSTREAM == 1
std::istream& operator>>(std::istream& lhs, BigNum& rhs); // bonus
#endif
