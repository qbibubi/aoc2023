#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
#include <sstream>


std::vector<std::string> read_from_file(const char*); 
int part1(std::vector<std::string>);
int count_digits(const std::string& str);


int 
main() 
{
  auto input = read_from_file("input.txt");
  // auto example = read_from_file("example.txt");
  
  // part 1
  int part1_answer = part1(input);
  // int part1_example = part1(example);

  std::cout << part1_answer << std::endl;
  // std::cout << part1_example << std::endl;
  // part 2

  return 0;
}


int 
part1(std::vector<std::string> input)
{
  std::vector<std::string> string_numbers;
  for (int i = 0; i < input.size(); ++i) 
  {
    int digits_in_word = count_digits(input[i]);
    int current_digit = 0;
    std::stringstream ss;

    for (int j = 0; j < input[i].size(); ++j) {
      if ( !std::isdigit(input[i][j]) ) {
        continue;
      }
      current_digit++;

      if ( digits_in_word == 1 ) {
        ss << input[i][j];
      }

      if ( current_digit == 1 || current_digit == digits_in_word) {
        ss << input[i][j];
      }
    }
    std::string s = ss.str();
    string_numbers.push_back(s);
  }

  int result = 0;
  for(auto var : string_numbers) {
    std::cout << var << std::endl;
    int number = std::stoi(var);
    result += number;
  }

  return result;
}


int count_digits(const std::string& str) {
  int digit_count = 0;
  for (const auto &ch : str) 
  {
    if (std::isdigit(ch)) {
      digit_count++;
    }
  }
  return digit_count;
}


std::vector<std::string> 
read_from_file(const char* filename) 
{
  std::ifstream file(filename);
  if ( !file.is_open() ) {
    std::cout << "Unable to open file" << std::endl;
    return {}; 
  }

  std::vector<std::string> lines;
  std::string line;
  while ( std::getline(file, line) ) {
    lines.push_back(line);
  }
  file.close();

  return lines;
}

