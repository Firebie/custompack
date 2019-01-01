#include "mcadincl.h"
#include <math.h>

LRESULT tgFunction(LPCOMPLEXSCALAR result, LPCCOMPLEXSCALAR angle);

FUNCTIONINFO tg = 
  { 
    "tg",                         // Name by which mathcad will recognize the function
    "angle",                      // cmplxsum will be called as cmplxsum(a,b)
    "tg(angle)",                  // description of cmplxsum(a,b)
    (LPCFUNCTION)tgFunction,      // pointer to the executible code
    COMPLEX_SCALAR, 
    1,                            // the return type is also a complex scalar
    {COMPLEX_SCALAR}              // both arguments are complex scalars
  };

// this code executes the addition
LRESULT tgFunction(LPCOMPLEXSCALAR result,  //put return value here
                            LPCCOMPLEXSCALAR angle) // 1st argument
{
    result->real = tan(angle->real);

    return 0;               // return 0 to indicate there was no error
}

LRESULT arctgFunction(LPCOMPLEXSCALAR result, LPCCOMPLEXSCALAR value);

FUNCTIONINFO arctg = 
  { 
    "arctg",                         // Name by which mathcad will recognize the function
    "value",                      // cmplxsum will be called as cmplxsum(a,b)
    "arctg(value)",                  // description of cmplxsum(a,b)
    (LPCFUNCTION)arctgFunction,      // pointer to the executible code
    COMPLEX_SCALAR, 
    1,                            // the return type is also a complex scalar
    {COMPLEX_SCALAR}              // both arguments are complex scalars
  };

// this code executes the addition
LRESULT arctgFunction(LPCOMPLEXSCALAR result,  //put return value here
                            LPCCOMPLEXSCALAR value) // 1st argument
{
    result->real = atan(value->real);

    return 0;               // return 0 to indicate there was no error
}

LRESULT arcsinFunction(LPCOMPLEXSCALAR result, LPCCOMPLEXSCALAR value);

FUNCTIONINFO arcsin = 
  { 
    "arcsin",                         // Name by which mathcad will recognize the function
    "value",                      // cmplxsum will be called as cmplxsum(a,b)
    "arcsin(value)",                  // description of cmplxsum(a,b)
    (LPCFUNCTION)arcsinFunction,      // pointer to the executible code
    COMPLEX_SCALAR, 
    1,                            // the return type is also a complex scalar
    {COMPLEX_SCALAR}              // both arguments are complex scalars
  };

// this code executes the addition
LRESULT arcsinFunction(LPCOMPLEXSCALAR result,  //put return value here
                            LPCCOMPLEXSCALAR value) // 1st argument
{
    result->real = asin(value->real);

    return 0;               // return 0 to indicate there was no error
}

LRESULT arccosFunction(LPCOMPLEXSCALAR result, LPCCOMPLEXSCALAR value);

FUNCTIONINFO arccos = 
  { 
    "arccos",                         // Name by which mathcad will recognize the function
    "value",                      // cmplxsum will be called as cmplxsum(a,b)
    "arccos(value)",                  // description of cmplxsum(a,b)
    (LPCFUNCTION)arccosFunction,      // pointer to the executible code
    COMPLEX_SCALAR, 
    1,                            // the return type is also a complex scalar
    {COMPLEX_SCALAR}              // both arguments are complex scalars
  };

// this code executes the addition
LRESULT arccosFunction(LPCOMPLEXSCALAR result,  //put return value here
                            LPCCOMPLEXSCALAR value) // 1st argument
{
    result->real = acos(value->real);

    return 0;               // return 0 to indicate there was no error
}

BOOL WINAPI _CRT_INIT(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved);

BOOL WINAPI DllEntryPoint (HANDLE hDLL, DWORD dwReason, LPVOID lpReserved)
{
  switch (dwReason)
  {
    case DLL_PROCESS_ATTACH:         // DLL is attaching to the address space of the current process.

      if (!_CRT_INIT(hDLL, dwReason, lpReserved)) 
        return FALSE;
    
      CreateUserFunction(hDLL, &tg);
      CreateUserFunction(hDLL, &arctg);
      CreateUserFunction(hDLL, &arcsin);
      CreateUserFunction(hDLL, &arccos);
      break;

    case DLL_THREAD_ATTACH:         // A new thread is being created in the current process.
    case DLL_THREAD_DETACH:        // A thread is exiting cleanly.
    case DLL_PROCESS_DETACH:      // The calling process is detaching the DLL from its address space.

      if (!_CRT_INIT(hDLL, dwReason, lpReserved)) 
        return FALSE;
      break;

  }
  return TRUE;
}

