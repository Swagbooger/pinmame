/***************************************************************************

  M.A.M.E.32  -  Multiple Arcade Machine Emulator for Win32
  Win32 Portions Copyright (C) 1997-2003 Michael Soderstrom and Chris Kirmse

  This file is part of MAME32, and may only be used, modified and
  distributed under the terms of the MAME license, in "readme.txt".
  By continuing to use, modify or distribute this file you indicate
  that you have read the license and understand and accept it fully.

***************************************************************************/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Screenshot.h"
#include "win32ui.h"

char g_szGameName[256] = "";		// String containing requested game name (may be different from ROM if aliased)

int WINAPI WinMain(HINSTANCE    hInstance,
                   HINSTANCE    hPrevInstance,
                   LPSTR        lpCmdLine,
                   int          nCmdShow)
{
	return Mame32Main(hInstance, lpCmdLine, nCmdShow);
}
