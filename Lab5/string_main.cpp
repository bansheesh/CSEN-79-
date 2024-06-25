#include "mystring.h"
#include <cassert>
#include <cstdlib> // Provides size_t
#include <cstring>
#include <ostream>

using namespace coen79_lab5;

int main() {
  // Create string s1, s2(“Hello, World!”), s3(s2)
  // cout s1, s2, s3
  string s1, s2("Hello, World!"), s3(s2);
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "s2: " << s2 << std::endl;
  std::cout << "s3: " << s3 << std::endl;

  //+= operator tests:
  // cout s1 length
  // s1 += string(“A”) -> cout s1 and s1 length
  // s1 += “B” -> cout s1 and s1 length
  // s1 += ‘C’ -> cout s1 and s1 length
  std::cout << "*** += operator tests ***" << std::endl;
  std::cout << "s1 length: " << s1.length() << std::endl;

  s1 += string("A");
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "s1 length: " << s1.length() << std::endl;

  s1 += "B";
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "s1 length: " << s1.length() << std::endl;

  s1 += 'C';
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "s1 length: " << s1.length() << std::endl;

  //[] operator test
  // cout s1[0], s1[1], s1[2]
  std::cout << "*** [] operator test ***" << std::endl;
  std::cout << "s1[0]: " << s1[0] << std::endl;
  std::cout << "s1[1]: " << s1[1] << std::endl;
  std::cout << "s1[2]: " << s1[2] << std::endl;

  //= operator test
  // s2 = string(“= Test 1 Success”)
  // cout s2 and (s2=string(“= Test 2 Success”))
  std::cout << "*** = operator test ***" << std::endl;
  s2 = string("= Test 1 Success");
  std::cout << "s2: " << s2 << std::endl;
  s2 = string("= Test 2 Success");
  std::cout << "s2: " << s2 << std::endl;

  // Create string A(“A”), B(“B”)
  // Logical operator tests
  // A==A; A==B; A!=A; A!=B; A>A; A>B; B>A; A>=A; A>=B; B>=A; A<A; A<B;
  // B<A; A<=A; A<=B; B<=A
  std::cout << "*** logical operator tests ***" << std::endl;
  string A("A"), B("B");
  std::cout << "A == A: " << std::boolalpha << (A == A) << std::endl;
  std::cout << "A == B: " << (A == B) << std::endl;
  std::cout << "A != A: " << (A != A) << std::endl;
  std::cout << "A != B: " << (A != B) << std::endl;
  std::cout << "A > A: " << (A > A) << std::endl;
  std::cout << "A > B: " << (A > B) << std::endl;
  std::cout << "B > A: " << (B > A) << std::endl;
  std::cout << "A >= A: " << (A >= A) << std::endl;
  std::cout << "A >= B: " << (A >= B) << std::endl;
  std::cout << "B >= A: " << (B >= A) << std::endl;
  std::cout << "A < A: " << (A < A) << std::endl;
  std::cout << "A < B: " << (A < B) << std::endl;
  std::cout << "B < A: " << (B < A) << std::endl;
  std::cout << "A <= A: " << (A <= A) << std::endl;
  std::cout << "A <= B: " << (A <= B) << std::endl;
  std::cout << "B <= A: " << (B <= A) << std::endl;

  //+ operator tests
  // cout (A+B); (A+”C”); (B+A)
  std::cout << "*** + operator tests ***" << std::endl;
  std::cout << "A + B: " << (A + B) << std::endl;
  std::cout << "A + C: " << (A + "C") << std::endl;
  std::cout << "B + A: " << (B + A) << std::endl;

  //>> operator test
  // cin >> s1, then cout s1
  std::cout << "*** >> operator test ***" << std::endl;
  string C;
  std::cout << "Please enter a word: " << std::endl;
  std::cin >> C;
  std::cout << "You entered: " << C << std::endl;

  // Single character constructor test
  // create string C(‘C’), then cout string C
  std::cout << "*** Single character constructor test ***" << std::endl;
  C = 'C';
  std::cout << "C: " << C << std::endl;

  // Insert tests
  // Create s1 = “ABCD” -> cout s1
  // s1.insert(“-”,0) -> cout
  // s1.insert(“*”, 3)->cout
  // s1.insert(“.”, s1.length()) -> cout
  std::cout << "*** insert tests ***" << std::endl;
  s1 = "ABCD";
  std::cout << "s1: " << s1 << std::endl;
  s1.insert("-", 0);
  std::cout << "s1: " << s1 << std::endl;
  s1.insert("*", 3);
  std::cout << "s1: " << s1 << std::endl;
  s1.insert(".", s1.length());
  std::cout << "s1: " << s1 << std::endl;

  // Dlt tests
  // Create s1=“1112233445555” -> cout
  // s1.dlt(0,3)->cout
  // s1.dlt(2,2)->cout
  // s1.dlt(s1.length()-4,4)->cout
  std::cout << "*** dlt tests ***" << std::endl;
  s1 = "1112233445555";
  std::cout << "s1: " << s1 << std::endl;
  s1.dlt(0, 3);
  std::cout << "s1: " << s1 << std::endl;
  s1.dlt(2, 2);
  std::cout << "s1: " << s1 << std::endl;
  s1.dlt(s1.length() - 4, 4);
  std::cout << "s1: " << s1 << std::endl;

  // Replace tests
  // Create s1=“abc” -> cout
  // s1.replace(‘z’, 0) -> cout
  // s1.replace(‘y’,1) -> cout
  // s1.replace(s2, s1.length()-s2.length()) -> cout
  std::cout << "*** replace tests ***" << std::endl;
  s1 = "abc";
  s2 = "zyx";
  std::cout << "s1: " << s1 << std::endl;
  s1.replace('z', 0);
  std::cout << "s1: " << s1 << std::endl;
  s1.replace('y', 1);
  std::cout << "s1: " << s1 << std::endl;
  s1.replace(s2, s1.length() - s2.length());
  std::cout << "s1: " << s1 << std::endl;
  s1.dlt(0, s1.length());
  s1 = "123DEFGHIJKLMNOP";
  std::cout << "s1: " << s1 << std::endl;
  s1.replace("123", 5);
  std::cout << "s1: " << s1 << std::endl;
  s1.replace("123", 13);
  std::cout << "s1: " << s1 << std::endl;

  // Count tests
  // Create s1=“ABBCCCDDDD”
  // Cout s1, s1.count(‘A’) , s1.count(‘B’) , s1.count(‘C’) , s1.count(‘D’) ,
  // 1.count(‘E’)
  std::cout << "*** count tests ***" << std::endl;
  s1 = "ABBCCCDDDD";
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "Num A's: " << s1.count('A') << std::endl;
  std::cout << "Num B's: " << s1.count('B') << std::endl;
  std::cout << "Num C's: " << s1.count('C') << std::endl;
  std::cout << "Num D's: " << s1.count('D') << std::endl;
  std::cout << "Num E's: " << s1.count('E') << std::endl;

  // Search tests
  // Use the same string from the count tests
  // Cout s1, s1.search(‘A’) , s1. search(‘B’) , s1. search(‘C’) , s1.
  // search(‘D’) , s1.search(‘E’) Create s1=“ABCDEFGHIJKLMNOP” Cout s1,
  // s1.search(string(“ABC”)) , s1. search(string(“GHI”)) ,
  // s1.search(string(“NOP”)) , s1. search(string(“XYZ”))
  std::cout << "*** search tests ***" << std::endl;
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "First A: " << s1.search('A') << std::endl;
  std::cout << "First B: " << s1.search('B') << std::endl;
  std::cout << "First C: " << s1.search('C') << std::endl;
  std::cout << "First D: " << s1.search('D') << std::endl;
  std::cout << "First E: " << s1.search('E') << std::endl;
  s1 = "ABCDEFGHIJKLMNOP";
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "Location of \"ABC\": " << s1.search(string("ABC")) << std::endl;
  std::cout << "Location of \"GHI\": " << s1.search(string("GHI")) << std::endl;
  std::cout << "Location of \"NOP\": " << s1.search(string("NOP")) << std::endl;
  std::cout << "Location of \"XYZ\": " << s1.search(string("XYZ")) << std::endl;

  return 0;
}
