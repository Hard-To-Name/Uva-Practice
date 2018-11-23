# UVA-Practice
Keep going :)

## Notes
### UVA-119:  
  Speed up line (may cause the situation below):
  ```cpp
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ```
  Different compilers may produce different result. (e.g. all outputs by cout come after all outputs by printf)
  
### UVA-11687:  
  C++ string to int:
  - Way 1
  ```cpp
  #include <sstream>
  #include <string>

  std::string text = "123";
  int number;
  std::istringstream iss (text);
  iss >> number;
  if (!iss.good ()) {
    //something happened
  }
  ```
  - Way 2
  ```cpp
  #include <string>
  
  std::string str("123");
  int n = std::stoi(str);
  ```
  
  C++ int to string:
  - Way 1
  ```cpp
  #include <sstream>
  #include <string>

  int i = 123;
  std::string out_string;
  std::stringstream ss;
  ss << i;
  out_string = ss.str();
  ```
  - Way 2
  ```cpp
  #include <string>
  
  int n = 123;
  std::string str = std::to_string(n);
  ```
  
### UVA-11956:  
  Usage of printf: http://www.cypress.com/file/54441/download
  ```
  $o: print a number in octal (base 8)
  %d: print a decimal number (base 10)
  %x: print a number in hexidecimal (base 16)
  ```
