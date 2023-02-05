#pragma once

#pragma region CoreDll

#ifdef CORE_BUILD
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif // CORE_BULID

#pragma endregion