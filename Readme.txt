% cd build

% cmake ..

% cmake --build . --verbose --config Debug --target install

% cd bin

% mep.exe
vart.cpp:dllpath::dllpath()
vart::vart()
vart::run()
X::X()
C:\Users\stsoe\tmp\MEP2\build\bin\xrt.dll
xrt::xrt()
xrt::run()
xrt::~xrt()
vart::~vart()

% mv xrt.dll c:\users\stsoe\tmp\dllrepo

% mep.exe
vart.cpp:dllpath::dllpath()
vart::vart()
vart::run()
X::X()
c:\users\stsoe\tmp\dllrepo\xrt.dll
xrt::xrt()
xrt::run()
xrt::~xrt()
vart::~vart()


