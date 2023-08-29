# Demo of delayload with Visual Studio

- `mep` is is the application
- `mep` links with `vart`
- `vart` links with `xrt`
- `vart` delayloads `xrt`
- `vart` calls `AddDllDirectory` during static global initialization
- `xrt` is loaded on first calls to `xrt::run` from `vart`
- `xrt` prints the path from where it was loaded

## Build and run
```
% mkdir build
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
```
