#pragma once
#include <string>
#include <vector>
#ifndef  CONSTANTTYPES
#define  CONSTANTTYPES

struct Point;
class Varlib;
class Date;

extern constexpr char NumberType = '8';
extern constexpr char QuitCommand = 'q';
extern constexpr char printCommand = '=';
extern constexpr char name = 'a';
extern constexpr char let = 'L';
extern const std::string declkey;
extern Varlib variableLib;

extern std::vector<std::string> monthLib;

#endif // !
