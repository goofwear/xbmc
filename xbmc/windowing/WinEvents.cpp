/*
 *      Copyright (C) 2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "WinEvents.h"

#include "system.h"

#if   defined(TARGET_WINDOWS)
#include "windows/WinEventsWin32.h"
#define WinEventsType CWinEventsWin32

#elif defined(TARGET_DARWIN_OSX)
#include "osx/WinEventsOSX.h"
#define WinEventsType CWinEventsOSX

#elif defined(TARGET_DARWIN_IOS)
#include "osx/WinEventsIOS.h"
#define WinEventsType CWinEventsIOS

#elif defined(TARGET_ANDROID)
#include "android/WinEventsAndroid.h"
#define WinEventsType CWinEventsAndroid

#elif defined(HAVE_WAYLAND)
#include "wayland/WinEventsWayland.h"
#define WinEventsType KODI::WINDOWING::WAYLAND::CWinEventsWayland

#elif defined(TARGET_LINUX) && defined(HAVE_MIR)
#include "mir/WinEventsMir.h"
#define WinEventsType CWinEventsMir

#elif (defined(TARGET_FREEBSD) || defined(TARGET_LINUX)) && defined(HAS_SDL_WIN_EVENTS)
#include "osx/WinEventsSDL.h"
#define WinEventsType CWinEventsSDL

#elif (defined(TARGET_FREEBSD) || defined(TARGET_LINUX)) && defined(HAS_X11_WIN_EVENTS)
#include "X11/WinEventsX11.h"
#define WinEventsType CWinEventsX11

#elif defined(TARGET_LINUX) && defined(HAS_LINUX_EVENTS)
#include "WinEventsLinux.h"
#define WinEventsType CWinEventsLinux
#endif

static WinEventsType    g_imp;

void CWinEvents::MessagePush(XBMC_Event* ev)
{
  g_imp.MessagePush(ev);
}

bool CWinEvents::MessagePump()
{
  return g_imp.MessagePump();
}

