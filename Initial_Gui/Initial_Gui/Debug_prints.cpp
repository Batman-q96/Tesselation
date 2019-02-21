#include "stdafx.h"
#include "Debug_prints.h"
#include <stdio.h>

#ifdef _DEBUG
void debug_sleep(int duration) {
	Sleep(duration);
}
void debug_print(LPCTSTR lpszFormat, ...) {
	va_list args, temp;
	va_start(args, lpszFormat);
	va_copy(temp, args);
	TCHAR buff[512];
	if (_vsntprintf_s(buff, 512 - 1, lpszFormat, args) < 0) {
		OutputDebugString(TEXT("ERROR:debug output too large"));
	}
	else {
		OutputDebugString(buff);
	}
	va_end(temp);
	va_end(args);
}
#else
void debug_print(LPCTSTR lpszFormat, ...) {

}
void debug_sleep(int duration) {

}
#endif