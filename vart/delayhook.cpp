#include <windows.h>
#include <delayimp.h>
#include <iostream>

FARPROC WINAPI delay_hook(
    unsigned int dliNotify, 
    PDelayLoadInfo pdli)
{
  switch (dliNotify) {
  case dliFailLoadLib:
    // LoadLibrary failed.
    // If you don't want to handle this failure yourself, return 0.
    // In this case the helper will raise an exception
    // (ERROR_MOD_NOT_FOUND) and exit.
    // If you want to handle the failure by loading an alternate
    // DLL (for example), then return the HMODULE for
    // the alternate DLL. The helper will continue execution with
    // this alternate DLL and attempt to find the
    // requested entrypoint via GetProcAddress.
    std::cout << "LoadLibrary failure\n";
    return 0;

  case dliFailGetProc:
    // GetProcAddress failed.
    // If you don't want to handle this failure yourself, return 0.
    // In this case the helper will raise an exception
    // (ERROR_PROC_NOT_FOUND) and exit.
    // If you choose, you may handle the failure by returning
    // an alternate FARPROC function address.
    std::cout << "GetProc failure\n";
    return 0;

  default:
    return NULL;
  }
}

const PfnDliHook __pfnDliFailureHook2 = delay_hook;
