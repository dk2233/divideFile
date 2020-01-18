AC_INIT([fileDivide], [0.3])
#m4_include([pkg.m4])
AC_CONFIG_MACRO_DIR([m4])
PKG_PROG_PKG_CONFIG
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_AUX_DIR([build-aux])
dnl I add all warning to be reported
AM_INIT_AUTOMAKE([-Wall])
# Handle --enable-debug (disabled by default)
remember_set_CFLAGS="$CFLAGS"
AC_PROG_CC_C99
AC_PROG_CC_C_O
AC_PROG_RANLIB

CFLAGS="$remember_set_CFLAGS -Wall -Wpedantic -Wextra -O3"

AC_ARG_ENABLE(debug,
              AS_HELP_STRING(
                             [--enable-debug],
                             [enable debugging code,default no]),
    [case "${enableval}" in
      yes) debug=true ;;
      no)  debug=false ;;
      *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
    esac],
    [debug=false])

AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")
AM_COND_IF(DEBUG,
    AC_DEFINE(DEBUG, 1, [Define to 0 if this is a release build]),
    AC_DEFINE(DEBUG, 0, [Define to 1 or higher if this is a debug build]))

if test "$debug" = true;then
CFLAGS+="-g"
##else
##    AX_APPEND_FLAG([-O3])
fi
#PKG_CHECK_MODULES([PCRE2], [pcre2-8], [have_pcre2=yes], [have_pcre2=no])
#AC_CHECK_LIB([pcre2-8],[pcre2_config],[])
AC_HEADER_STDC
dnl AC_DEFINE([PCRE2_CODE_UNIT_WIDTH],[8])
dnl AC_CHECK_HEADERS([pcre2.h], [LIBS="-lpcre2-8 $LIBS"],[AC_MSG_ERROR([there is no pcre2 header])],[])
AM_PROG_AR
AC_PROG_INSTALL
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

cat << EOF
$PACKAGE-$VERSION configuration summary:

    Install prefix ..................... : ${prefix}
    C preprocessor ..................... : ${CPP}
    C compiler ......................... : ${CC}
    Linker ............................. : ${LD}
    C preprocessor flags ............... : ${CPPFLAGS}
    C compiler flags ................... : ${CFLAGS} ${VISIBILITY_CFLAGS}
    Linker flags ....................... : ${LDFLAGS}
    Extra libraries .................... : ${LIBS}

EOF
