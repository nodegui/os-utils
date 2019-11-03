#pragma once
#include <iostream>

namespace AboutPanel
{
  struct options {
    std::string name;
    std::string version;
    std::string applicationVersion;
    std::string copyright;
  };

  void open(options options);
}; // namespace AboutPanel
