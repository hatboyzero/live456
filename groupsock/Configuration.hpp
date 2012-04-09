//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// Live456 Libraries
//
// Copyright (C) 2012 Matthew Alan Gray
//
//  This software is licensed as described in the file license.txt, which you
//  should have received as part of this distribution.
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the terms described in the file license.txt.
//
//  @author Matthew Alan Gray <mgray@hatboystudios.com>
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
/// @author  John S. Givler, Ph.D.(Computer Science)

#ifndef LIVE456_GROUPSOCK_CONFIGURATION_HPP_INCLUDED
#define LIVE456_GROUPSOCK_CONFIGURATION_HPP_INCLUDED

#ifdef  _MSC_VER
#    pragma once
#    pragma inline_depth(255)
#    pragma inline_recursion(off)
#    pragma warning(disable:4251)   // 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
#    pragma warning(disable:4275)   // non – DLL-interface classkey 'identifier' used as base for DLL-interface classkey 'identifier'
#endif  // _MSC_VER

#ifdef  _MSC_VER
#    ifndef HOST_WIN32              // this probably should be done elsewhere ...
#        ifdef _WIN32
#            define HOST_WIN32
#        endif
#    endif
#    ifndef HOST_WIN64
#        ifdef _WIN64
#            define HOST_WIN64
#        endif
#    endif
#endif  // _MSC_VER


// Microsoft C++ compiler
#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#    ifdef  GROUPSOCK_EXPORTS
#        define GROUPSOCK_DLL_LINK __declspec(dllexport)
#    else
#        define GROUPSOCK_DLL_LINK __declspec(dllimport)
#    endif
#endif  // _MSC_VER


// GNU C++ compiler
#if defined(__GNUG__) && !defined(__INTEL_COMPILER)
#    if 0 // (__GNUC__ >= 4) && !defined(HOST_CYGWIN) && !defined(HOST_SOLARIS)
#        ifdef  GROUPSOCK_EXPORTS
#            define GROUPSOCK_DLL_LINK __attribute__ ((visibility ("default")))
#        else
#            define GROUPSOCK_DLL_LINK __attribute__ ((visibility ("hidden")))
#        endif
#    else
#        ifdef  GROUPSOCK_EXPORTS
#            define GROUPSOCK_DLL_LINK // __declspec(dllexport)
#        else
#            define GROUPSOCK_DLL_LINK // __declspec(dllimport)
#        endif
#    endif
#endif  // __GNUG__


// Sun C++ compiler
#if defined(__SUNPRO_CC)
#    ifdef  GROUPSOCK_EXPORTS
#        define GROUPSOCK_DLL_LINK   // ?
#    else
#        define GROUPSOCK_DLL_LINK   // ?
#    endif
#endif  // __SUNPRO_CC


// Intel C++ compiler
#if defined(__INTEL_COMPILER)
#    ifdef  GROUPSOCK_EXPORTS
#        define GROUPSOCK_DLL_LINK __declspec(dllexport)
#    else
#        define GROUPSOCK_DLL_LINK __declspec(dllimport)
#    endif
#endif  // __INTEL_COMPILER


#ifndef GROUPSOCK_DLL_LINK
#    define GROUPSOCK_DLL_LINK
#endif  // ! GROUPSOCK_DLL_LINK


#endif  // LIVE456_GROUPSOCK_CONFIGURATION_HPP_INCLUDED

