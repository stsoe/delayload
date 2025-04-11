# Demo of delayload with Visual Studio

- `mep` is is the application
- `mep` links with `vart`
- `vart` links with `xrt`
- `vart` delayloads `xrt`
- `vart` calls `AddDllDirectory` during static global initialization
- `xrt` is loaded when `xrt::xrt` construtor is first called from `vart`
- `xrt` prints the path from where it was loaded
- `xrt_legacy` doesn't have the xrt::run API.

## Build and run
```
% cmake -B build/latest
% cmake --build build/latest --verbose --config Release --target install

% cd build/latest/bin

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

## Demo of missing API feature

The demo `xrt` class implements `xrt::version()` to indicate to application `vart` that
the function `xrt::run()` is present or not.

`vart` is built against a version of `xrt` that contains the run() API, but if we deploy
the legacy version of `xrt.dll`, then the function won't be found at runtime.  

With delay loading of `xrt.dll` the application `vart` will still run, but if it tries
to call `xrt::run()` a delay hook is called to indicate GetProc failure.

In the `vart` example, the call to `xrt::run()` is protected against a
version check (`xrt::version()`) so if at runtime the `xrt.dll` is the
legacy one, then `vart` will still run successfully, only not call
`xrt::run()`. This means that the delay hook is unused in this
example.

```
% cmake -B build/latest
% cmake --build build/latest --verbose --config Release --target install
% cmake -B build/legacy
% cmake --build build/legacy --verbose --config Release --target install

% cd build/latest/bin
% mep.exe
vart.cpp:dllpath::dllpath()
vart::vart()
vart::run()
X::X()
C:\<path>\bin\xrt.dll
xrt::xrt()
xrt::run()
xrt::~xrt()
vart::~vart()

% copy ..\legacy\bin\xrt.dll .
% mep.exe
vart.cpp:dllpath::dllpath()
vart::vart()
vart::run()
X::X()
C:\Users\stsoe\git\stsoe\delayload\build\latest\bin\xrt.dll
xrt::xrt()
xrt::~xrt()
vart::~vart()

To demo the delay hook, uncomment the conditional version check in vart.cpp.
```

