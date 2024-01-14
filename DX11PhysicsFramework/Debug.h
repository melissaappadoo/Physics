#pragma once

#include <Windows.h>
#include <stdio.h>

class Debug
{
public:
	static int VDebugPrintF(const char* format, va_list args);
	static int DebugPrintF(const char* format, ...);
};

