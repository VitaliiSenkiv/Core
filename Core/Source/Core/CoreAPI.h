#pragma once

/**
 * This file should be included to all internal Core files to allow use CORE_API
 * to allow exporting structs/classes
 */

#pragma region CoreDll

#ifdef CORE_BUILD
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif // CORE_BULID

#pragma endregion