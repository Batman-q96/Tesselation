#include "Debug_prints.h"
#include <stdio.h>
#ifdef debug_build
void debug_sleep(int duration) {
	Sleep(duration);
}
void debug_print(LPCTSTR lpszFormat, ...) {
	va_list args, temp;
	va_start(args, lpszFormat);
	va_copy(temp, args);
	//if (va_arg(temp, int)) {
	TCHAR buff[512];
	if (_vsntprintf_s(buff, 512 - 1, lpszFormat, args) < 0) {
		OutputDebugString(L"ERROR:debug output too large");
	}
	else {
		OutputDebugString(buff);
	}
	/*}
	else {
		OutputDebugString(lpszFormat);
	}*/
	va_end(temp);
	va_end(args);
}
#else
void debug_print(LPCTSTR lpszFormat, ...);
void debug_sleep(int duration);
#endif