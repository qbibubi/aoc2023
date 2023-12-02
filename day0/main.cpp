#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

template<typename T> std::vector<T> read_from_file(const std::string&); 
template<typename T> T convert(const std::string& value); 
template<> std::string convert<std::string>(const std::string& value);
int part1(const std::vector<std::string>&);
int part2(const std::vector<std::string>&);


int
main() 
{
  auto input = read_from_file<std::string>("input.txt");
  auto example = read_from_file<std::string>("example.txt");
  auto example2 = read_from_file<std::string>("example2.txt");

  auto solution1 = part1(input);
  auto solution2 = part2(input);
  auto solution1_example = part1(example);
  auto solution2_example = part1(example);

  std::cout << std::setw(10) << "Part 1: " << solution1 << std::endl;
  std::cout << std::setw(10) << "Part 2: " << solution2 << std::endl;
  std::cout << std::setw(20) << "Part 1 example: " << solution1_example << std::endl;
  std::cout << std::setw(20) << "Part 2 example: " << solution2_example << std::endl;

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

template<>std::string convert<std::string>(const std::string& value) { return value; }


int part1(const std::vector<std::string>& input) 
{ 
  return input.size(); 
}


int part2(const std::vector<std::string>& input) 
{
  return input.size(); 
}
