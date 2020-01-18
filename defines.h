/*
 * =====================================================================================
 *
 *       Filename:  defines.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06.01.2020 20:57:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: kucharski22daniel@gmail.com 
 *   Organization:  
 *
 * =====================================================================================
 */

/* #####   HEADER FILE INCLUDES   ################################################### */

/* #####   EXPORTED MACROS   ######################################################## */

#define SEARCH_FILE_NAME   "<file "
#define END_OF_FILE        "</file"
#define BUFFER_LENGTH 		150U

#if defined (__WIN32) ||  (WIN32) || (__CYGWIN__) 
#define		HOW_MANY_DIGIT_LESS		1U
#define     PATH_SEPARATOR          "\\"
#define	HOW_MANY_DIGIT_LESS2  0U
#elif defined(__APPLE__)
#define		HOW_MANY_DIGIT_LESS		1U
#else
#define     PATH_SEPARATOR          "/"
#define		HOW_MANY_DIGIT_LESS		1U
#endif

/* #####   EXPORTED TYPE DEFINITIONS   ############################################## */

/* #####   EXPORTED DATA TYPES   #################################################### */

/* #####   EXPORTED VARIABLES   ##################################################### */

/* #####   EXPORTED FUNCTION DECLARATIONS   ######################################### */

