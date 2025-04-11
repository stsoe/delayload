#define VART_SOURCE
#include "vart.h"
#include "xrt.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>

namespace {

struct dllpath
{
  dllpath()
  {
    std::cout << "vart.cpp:dllpath::dllpath()\n";
    SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    ::AddDllDirectory(L"c:\\users\\stsoe\\tmp\\dllrepo");
  }
};

static dllpath x;

}


namespace vart {

vart::
vart()
{
  std::cout << "vart::vart()\n";
}

vart::
~vart()
{
  std::cout << "vart::~vart()\n";
}

void
vart::
run()
{
  std::cout << "vart::run()\n";
  xrt::xrt x;

  // The run feature is implemented in version >= 2
  if (x.version() >= 2)
    x.run();
}


} // namespace vart  

