/**
 * @file functions_to_implement.cpp
 * @author Derek Larson (some implementations), declarations template was provided
 * @brief CSPB 3010 functions to implement for the test driven development
 * lecture activity 5.2
 * 
 * @note 7 functions implemented in addition to the two provided as example
 * 
 * @test Uses catch2 library for unit tests in test.cpp
 * requires "catch.hpp"
 * make test && ./test
 */

#include <iostream>
#include <vector>
/* String functions section */

/**
 * @brief Accepts a string and separator, returns a vector of strings
 * split on the separator excluding the separator. Returns the input string
 * in a vector if no separator match is found.
 * 
 * @param whole whole string to examine
 * @param separator string to separate on
 * @return std::vector<std::string> vector of strings split by the separator
 */
std::vector<std::string> Split(std::string whole, std::string separator) {
  std::vector<std::string> result;
  std::string remaining = whole; // copy to modify

  size_t pos;
  while ((pos = remaining.find(separator)) != std::string::npos) {
    result.push_back(remaining.substr(0, pos)); //push up to the found separator
    remaining.erase(0, pos+separator.length()); //erase up to and including separator
  }

  result.push_back(remaining); // send tailing string
  

  return result;
}

/**
 * @brief takes two strings and removes all matches of the second substring
 * from the first string.
 * 
 * @param s1 the string to modify
 * @param s2 the substring to remove from s1
 * @return std::string a string with all instances of s2 removed
 */
std::string RemoveAllSubstrings(std::string s1, std::string s2) {
  std::string result = s1;

  size_t pos;
  while ((pos  = result.find(s2)) != std::string::npos) {
    result.erase(pos, s2.length());
  }

  return result;
}

/**
 * @brief Takes two strings and removes the first instance of the second
 * string from the first.
 * 
 * @param s1 The whole string to modify
 * @param s2 the substring to remove
 * @return std::string the modified string with the substring removed
 */
std::string RemoveFirstSubstring(std::string s1, std::string s2) {
  std::string result = s1;

  size_t pos;
  if ((pos  = result.find(s2)) != std::string::npos) {
    result.erase(pos, s2.length());
  }

  return result;
}


/* Vector functions section */
/**
 * @brief accepts a vector of strings and returns them as one
 * string concatenated in order with the glue between each.
 * 
 * @param pieces vector of strings to join
 * @param glue string to glue between each joined string
 * @return std::string output string of the joined vector of strings
 */
std::string Join(std::vector<std::string> pieces, std::string glue) {
  std::string result = "";
  
  for (size_t i = 0; i < pieces.size(); ++i) {
    result += pieces.at(i);
    
    if (i < pieces.size() - 1) { // only add glue if it's not the last element
      result += glue;
    }
  }

  return result;
}

// takes two vectors of integers, a and b. The function then removes elements from a if they are also in b.
// If the integer is in b, but not in a, nothing happens.
std::vector<int> MatchVectors(std::vector<int> a, std::vector<int> b);

/**
 * @brief divides an input integer by 2 until it is impossible to do so, 
 * then returns the final number.
 * 
 * @param original input number to divide by 2
 * @return int of the last number that cannot be divided by two
 * returns 0 when it reaches zero, else you can infinitely divide zero by 2 with no remainder
 */
int RemoveTwos(int original) {
  if (original == 0) { return 0; }
  if (original % 2 == 1) { return original; }
  return RemoveTwos(original/2);
}

/**
 * @brief takes a vector of integers and removes 
 * all elements evenly divisible by the passed in int
 * 
 * @param input vector of numbers to check
 * @param divides_by number to cleanly divide by
 * @return std::vector<int> vector of numbers from the
 * first parameter that cleanly divide by the second parameter
 * @note Returns an empty vector if divides_by zero.
 */
std::vector<int> MultiplesFilter(std::vector<int> input, int divides_by) {
  std::vector<int> result;
  if (divides_by == 0) { return result; } // avoiding undefined behavior

  for (int number : input) {
    if (number % divides_by == 0) { result.push_back(number); }
  }
  return result;
}

/**
 * @brief returns a vector that functions of a mask of 
 * the even numbers of the input vector
 * 
 * @param input input vector of ints
 * @return std::vector<bool> output vector of bools
 * representing true for even, false for odd in the same order.
 */
std::vector<bool> EvenMask(std::vector<int> input) {
  std::vector<bool> result;
  
  for (int number: input) {
    result.push_back(number % 2 == 0);
  }

  return result;
}

// returns a vector with true for odd numbers and false for even numbers
std::vector<bool> OddMask(std::vector<int>);

// Sums all numbers in a vector and returns the resulting value
int Sum(std::vector<int> nums);

// Multiplies all numbers in a vector together and returns the resulting value
int Product(std::vector<int> nums);

// Adds an integer n to each element of a given vector
std::vector<int> VectorPlusN(std::vector<int> v, int n);

// Multiples an integer n with each element of a given vector
std::vector<int> VectorTimesN(std::vector<int> v, int n);

// takes in two integers and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<int> Multiples(int n, int m);

// takes an integer n that is >= 0 and returns a vector of all squares up to n^n (1^1, 2^2, 3^3, .... n^n)
std::vector<int> SquaresUntil(int n);

// takes an int, n, and returns the nth value of the fibonacci sequence (1, 1, 2, 3, 5, 8, 13, ...)
int NthFibonacci(int n);

// returns -1 if the number is negative and 1 if positive
int Sign(int num);

// takes two vectors of doubles, a and b. The function then removes elements from a if they are also in b.
// If the double is in b, but not in a, nothing happens.
std::vector<double> MatchVectors(std::vector<double> a, std::vector<double> b);

// takes a vector of doubles and removes all elements evenly divisible by the passed in double
std::vector<double> MultiplesFilter(std::vector<double>, double divides_by);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<double> nums, double greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<double> nums, double less_than);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<int> nums, int greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<int> nums, int less_than);

// Sums all numbers in a vector and returns the resulting value
double Sum(std::vector<double> nums);

// Multiplies all numbers in a vector together and returns the resulting value
double Product(std::vector<double> nums);

// Adds an double n to each element of a given vector
std::vector<double> VectorPlusN(std::vector<double> v, double n);

// Multiples an double n with each element of a given vector
std::vector<double> VectorTimesN(std::vector<double> v, double n);

// takes in two doubles and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<double> Multiples(double n, double m);

// returns -1 if the number is negative and 1 if positive
double Sign(double num);

// adds n to each element of the vector
std::vector<double> AddN(std::vector<double>, double n);

// adds n to each element of the vector
std::vector<std::string> AddN(std::vector<std::string>, std::string n);

// subtracts n to each element of the vector
std::vector<int> SubtractN(std::vector<int>, int n);

// subtracts n to each element of the vector
std::vector<double> SubtractN(std::vector<double>, double n);

// ====================================================================

// takes an int, n, and returns the factorial of that int (n!)
int Factorial(int n)
{
	if(n>1)
		return n*Factorial(n-1);
	else
		return 1;
}

// adds n to each element of the vector
std::vector<int> AddN(std::vector<int> v, int n)
{
	for(int i=0;i<(int)v.size();i++)
	{
		v[i]+=n;
	}
	return v;
}