#define XRT_SOURCE
#include "xrt.h"
#include <iostream>
#include <windows.h>

namespace {

inline std::string
dlpath(const char* dllname)
{
  char dll_path[MAX_PATH];
  if (!::GetModuleFileName(::GetModuleHandle(dllname), dll_path, MAX_PATH))
    throw std::runtime_error("Get handle of " + std::string(dllname) + " failed");

  return dll_path;
}

struct X {
  X()
  {
    std::cout << "X::X()\n";
    std::cout << dlpath("xrt.dll") << "\n";
  }
};

static X x;

}


namespace xrt {

xrt::
xrt()
{
  std::cout << "xrt::xrt()\n";
}

xrt::
~xrt()
{
  std::cout << "xrt::~xrt()\n";
}

void
xrt::
run()
{
  std::cout << "xrt::run()\n";
}

}
