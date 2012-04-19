//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the
// Free Software Foundation; either version 2.1 of the License, or (at your
// option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)
// 
// This library is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
// more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this library; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// "liveMedia"
// Copyright (c) 1996-2012 Live Networks, Inc.  All rights reserved.
// Copyright (c) 2012 Matthew Alan Gray - All rights reserved.
// Medium
// C++ header
//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
#ifndef MEDIA_HH_INCLUDED
#define MEDIA_HH_INCLUDED

#include "Configuration.hpp"

#include "liveMedia_version.hh"

#include <UsageEnvironment/NetCommon.h>
#include <UsageEnvironment/HashTable.hh>
#include <UsageEnvironment/UsageEnvironment.hh>

#include <stdio.h>

// The following makes the Borland compiler happy:
#ifdef __BORLANDC__
#define _strnicmp strnicmp
#define fabsf(x) fabs(x)
#endif

#define mediumNameMaxLen 30

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
class LIVEMEDIA_DLL_LINK Medium
{
    /// @name Types
    /// @{
public:
    /// @}

    /// @name Medium implementation
    /// @{
public:
    static Boolean lookupByName(UsageEnvironment& env,
                                char const* mediumName,
                                Medium*& resultMedium);
    static void close(UsageEnvironment& env, char const* mediumName);
    static void close(Medium* medium); // alternative close() method using ptrs
        // (has no effect if medium == NULL)

    UsageEnvironment& envir() const {return fEnviron;}

    char const* name() const {return fMediumName;}

    // Test for specific types of media:
    virtual Boolean isSource() const;
    virtual Boolean isSink() const;
    virtual Boolean isRTCPInstance() const;
    virtual Boolean isRTSPClient() const;
    virtual Boolean isRTSPServer() const;
    virtual Boolean isMediaSession() const;
    virtual Boolean isServerMediaSession() const;
    virtual Boolean isDarwinInjector() const;
protected:
    TaskToken& nextTask() { return fNextTask; }
    /// @}

    /// @name 'Structors
    /// @{
protected:
    friend class MediaLookupTable;
             Medium(UsageEnvironment& env); // abstract base class
    virtual ~Medium(); // instances are deleted using close() only
    /// @}

    /// @name Member Variables
    /// @{
private:
    UsageEnvironment&   fEnviron;
    char                fMediumName[mediumNameMaxLen];
    TaskToken           fNextTask;
    /// @}

};  // class Medium

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// A data structure for looking up a Medium by its string name.
// (It is used only to implement "Medium", but we make it visible here, in case developers want to use it to iterate over
//  the whole set of "Medium" objects that we've created.)
class LIVEMEDIA_DLL_LINK MediaLookupTable
{
    /// @name Types
    /// @{
public:
    /// @}

    /// @name MediaLookupTable implementation
    /// @{
public:
    static MediaLookupTable* ourMedia(UsageEnvironment& env);
    HashTable const& getTable() { return *fTable; }
private:
    friend class Medium;

    Medium* lookup(char const* name) const;
    // Returns NULL if none already exists

    void addNew(Medium* medium, char* mediumName);
    void remove(char const* name);

    void generateNewName(char* mediumName, unsigned maxLen);
    /// @}

    /// @name 'Structors
    /// @{
protected:
             MediaLookupTable(UsageEnvironment& env);
    virtual ~MediaLookupTable();
    /// @}

    /// @name Member Variables
    /// @{
private:
    UsageEnvironment&   fEnv;
    HashTable*          fTable;
    unsigned            fNameGenerator;
    /// @}

};  // class MediaLookupTable

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~
// The structure pointed to by the "liveMediaPriv" UsageEnvironment field:
class LIVEMEDIA_DLL_LINK _Tables
{
    /// @name Types
    /// @{
public:
    /// @}

    /// @name _Tables implementation
    /// @{
public:
    static _Tables* getOurTables(UsageEnvironment& env, Boolean createIfNotPresent = True);
        // returns a pointer to an "ourTables" structure (creating it if necessary)
    void reclaimIfPossible();
        // used to delete ourselves when we're no longer used

    MediaLookupTable* mediaTable;
    void* socketTable;
    /// @}

    /// @name 'Structors
    /// @{
protected:
             _Tables(UsageEnvironment& env);
    virtual ~_Tables();
    /// @}

    /// @name Member Variables
    /// @{
private:
    UsageEnvironment&   fEnv;
    /// @}

};  // class _Tables

//-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~

#endif  // MEDIA_HH_INCLUDED
