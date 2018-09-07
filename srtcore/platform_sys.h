/*
 * SRT - Secure, Reliable, Transport
 * Copyright (c) 2018 Haivision Systems Inc.
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 * 
 */
#ifndef INC__PLATFORM_SYS_H
#define INC__PLATFORM_SYS_H

#ifdef WIN32
   #define _CRT_SECURE_NO_WARNINGS 1 // silences windows complaints for sscanf
   #include <winsock2.h>
   #include <ws2tcpip.h>
   #include <ws2ipdef.h>
   #include <windows.h>
   #if defined(_MSC_VER)
      #include <stdint.h>
      #include <win/inttypes.h>
      #pragma warning(disable:4251)
   #elif defined(__MINGW32__)
      #include <inttypes.h>
      #include <stdint.h>
   #endif
#else

#if __APPLE__
#define __APPLE_USE_RFC_3542 /* IPV6_PKTINFO */
#define __POSIX_C_SOURCE
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#include <cerrno>
#include <cstring>
#include <cstdlib>
#endif

#endif
