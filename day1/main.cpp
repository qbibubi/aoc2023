#include <cstring>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <regex>

template<typename T> std::vector<T> read_from_file(const std::string&); 
template<typename T> T convert(const std::string& value); 
int part1(const std::vector<std::string>&);
int part2(const std::vector<std::string>&);
int count_digits(const std::string& str);


int
main() 
{
  auto input = read_from_file<std::string>("input.txt");
  auto example = read_from_file<std::string>("example.txt");
  auto example2 = read_from_file<std::string>("example2.txt");

  auto solution1 = part1(input);
  auto solution2 = part2(input);
  auto solution1_example = part1(example);
  auto solution2_example = part2(example2);

  std::cout << "Part 1: " << solution1 << std::endl;
  std::cout << "Part 2: " << solution2 << std::endl;
  std::cout << "Part 1 example: " << solution1_example << std::endl;
  std::cout << "Part 2 example: " << solution2_example << std::endl;

  return 0;
}


template<typename T>
std::vector<T> 
read_from_file(const std::string& filename) 
{
  if (filename.begin() == filename.end()) {
    std::cerr << "Error: Filename is too short" << std::endl;
    return {};
  }

  std::ifstream file(filename);
  if ( !file.is_open() ) {
    std::cerr << "Error: Unable to open file" << std::endl;
    return {}; 
  }

  std::vector<T> lines;
  std::string line;
  while ( std::getline(file, line) ) {
    lines.push_back( convert<T>(line) );
  }
  file.close();

  return lines;
}

template<typename T> 
T convert(const std::string& value) 
{
  T result;
  std::istringstream stream(value);
  stream >> result;
  return result;
}

/* PART 1 */

int 
count_digits(const std::string& str) {
  int digit_count = 0;
  for ( const auto &ch : str ) 
    if ( std::isdigit(ch) )
      digit_count++;
  return digit_count;
}

int 
part1(const std::vector<std::string>& input) 
{ 
  std::vector<int> numbers;
  for ( const auto& line : input ) {
    int digits_in_word = count_digits(line);
    int current_digit = 0;
    std::stringstream ss;

    for ( const auto& ch : line ) {
      if ( !std::isdigit(ch) ) continue;
      current_digit++;
      if ( digits_in_word == 1 ) ss << ch;
      if ( current_digit == 1 || current_digit == digits_in_word ) ss << ch;
    }

    std::string full_number = ss.str();
    numbers.push_back(std::stoi(full_number));
  }

  int result = 0;
  for ( const auto& number : numbers )
    result += number;

  return result;
}


/* PART 2 */

int 
part2(const std::vector<std::string>& input) 
{
  std::regex regex("(?=(one|two|three|four|five|six|seven|eight|nine|[1-9]))");
  std::unordered_map<std::string, std::string> map = {
      { "one", "1" }, { "two", "2" }, { "three", "3" },
      { "four", "4" }, { "five", "5" }, { "six", "6" },
      { "seven", "7" }, { "eight", "8" }, { "nine", "9" }
  };
  std::vector<int> numbers;

  for ( const auto& line : input ) {
    std::vector<std::string> matches;
    std::stringstream ss;
    auto line_begin = std::sregex_iterator(line.begin(), line.end(), regex);

    while ( line_begin != std::sregex_iterator() ) {
      auto match = line_begin->str(1);
      auto it = map.find(match);

      if ( it != map.end() ) {
        match = it->second;
        matches.push_back(match);
      } else {
        matches.push_back(match);
      }

      ++line_begin;
    }
    
    ss << matches[0];
    ss << matches[matches.size() - 1];
    std::string full_number = ss.str();
    numbers.push_back(std::stoi(full_number));
  }

  int result = 0;
  for ( const auto& number : numbers ) {
    result += number;
  }
  return result;
}
