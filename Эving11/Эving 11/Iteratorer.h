#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <set>

void loopVector(std::vector<std::string> vec);

void replaceVector(std::vector<std::string>& vec, std::string old, std::string replacement);

void loopSet(std::set<std::string> vec);

void replaceSet(std::set<std::string>& vec, std::string old, std::string replacement);