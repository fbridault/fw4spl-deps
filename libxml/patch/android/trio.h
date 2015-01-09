/*************************************************************************
 *
 * $Id: trio.h,v 1.19 2009/09/13 10:12:22 breese Exp $
 *
 * Copyright (C) 1998 Bjorn Reese and Daniel Stenberg.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE AUTHORS AND
 * CONTRIBUTORS ACCEPT NO RESPONSIBILITY IN ANY CONCEIVABLE MANNER.
 *
 *************************************************************************
 *
 * http://ctrio.sourceforge.net/
 *
 ************************************************************************/

#ifndef TRIO_TRIO_H
#define TRIO_TRIO_H

#if !defined(WITHOUT_TRIO)

/*
 * Use autoconf defines if present. Packages using trio must define
 * HAVE_CONFIG_H as a compiler option themselves.
 */
#if defined(HAVE_CONFIG_H)
# include <config.h>
#endif

#include "triop.h"

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Error codes.
 *
 * Remember to add a textual description to trio_strerror.
 */
enum {
  TRIO_EOF      = 1,
  TRIO_EINVAL   = 2,
  TRIO_ETOOMANY = 3,
  TRIO_EDBLREF  = 4,
  TRIO_EGAP     = 5,
  TRIO_ENOMEM   = 6,
  TRIO_ERANGE   = 7,
  TRIO_ERRNO    = 8,
  TRIO_ECUSTOM  = 9
};

/* Error macros */
#define TRIO_ERROR_CODE(x) ((-(x)) & 0x00FF)
#define TRIO_ERROR_POSITION(x) ((-(x)) >> 8)
#define TRIO_ERROR_NAME(x) trio_strerror(x)

typedef int (*trio_outstream_t) TRIO_PROTO((trio_pointer_t, int));
typedef int (*trio_instream_t) TRIO_PROTO((trio_pointer_t));

TRIO_CONST char *trio_strerror TRIO_PROTO((int));

/*************************************************************************
 * Print Functions
 */

int trio_printf TRIO_PROTO((TRIO_CONST char *format, ...));
int trio_vprintf TRIO_PROTO((TRIO_CONST char *format, va_list args));
int trio_printfv TRIO_PROTO((TRIO_CONST char *format, void **args));

int trio_fprintf TRIO_PROTO((FILE *file, TRIO_CONST char *format, ...));
int trio_vfprintf TRIO_PROTO((FILE *file, TRIO_CONST char *format, va_list args));
int trio_fprintfv TRIO_PROTO((FILE *file, TRIO_CONST char *format, void **args));

int trio_dprintf TRIO_PROTO((int fd, TRIO_CONST char *format, ...));
int trio_vdprintf TRIO_PROTO((int fd, TRIO_CONST char *format, va_list args));
int trio_dprintfv TRIO_PROTO((int fd, TRIO_CONST char *format, void **args));

int trio_cprintf TRIO_PROTO((trio_outstream_t stream, trio_pointer_t closure,
                 TRIO_CONST char *format, ...));
int trio_vcprintf TRIO_PROTO((trio_outstream_t stream, trio_pointer_t closure,
                  TRIO_CONST char *format, va_list args));
int trio_cprintfv TRIO_PROTO((trio_outstream_t stream, trio_pointer_t closure,
                  TRIO_CONST char *format, void **args));

int trio_sprintf TRIO_PROTO((char *buffer, TRIO_CONST char *format, ...));
int trio_vsprintf TRIO_PROTO((char *buffer, TRIO_CONST char *format, va_list args));
int trio_sprintfv TRIO_PROTO((char *buffer, TRIO_CONST char *format, void **args));

int trio_snprintf TRIO_PROTO((char *buffer, size_t max, TRIO_CONST char *format, ...));
int trio_vsnprintf TRIO_PROTO((char *buffer, size_t bufferSize, TRIO_CONST char *format,
           va_list args));
int trio_snprintfv TRIO_PROTO((char *buffer, size_t bufferSize, TRIO_CONST char *format,
           void **args));

int trio_snprintfcat TRIO_PROTO((char *buffer, size_t max, TRIO_CONST char *format, ...));
int trio_vsnprintfcat TRIO_PROTO((char *buffer, size_t bufferSize, TRIO_CONST char *format,
                      va_list args));

#if defined(TRIO_DEPRECATED)
char *trio_aprintf TRIO_PROTO((TRIO_CONST char *format, ...));
char *trio_vaprintf TRIO_PROTO((TRIO_CONST char *format, va_list args));
#endif

int trio_asprintf TRIO_PROTO((char **ret, TRIO_CONST char *format, ...));
int trio_vasprintf TRIO_PROTO((char **ret, TRIO_CONST char *format, va_list args));
int trio_asprintfv TRIO_PROTO((char **result, TRIO_CONST char *format, trio_pointer_t * args));

/*************************************************************************
 * Scan Functions
 */
int trio_scanf TRIO_PROTO((TRIO_CONST char *format, ...));
int trio_vscanf TRIO_PROTO((TRIO_CONST char *format, va_list args));
int trio_scanfv TRIO_PROTO((TRIO_CONST char *format, void **args));

int trio_fscanf TRIO_PROTO((FILE *file, TRIO_CONST char *format, ...));
int trio_vfscanf TRIO_PROTO((FILE *file, TRIO_CONST char *format, va_list args));
int trio_fscanfv TRIO_PROTO((FILE *file, TRIO_CONST char *format, void **args));

int trio_dscanf TRIO_PROTO((int fd, TRIO_CONST char *format, ...));
int trio_vdscanf TRIO_PROTO((int fd, TRIO_CONST char *format, va_list args));
int trio_dscanfv TRIO_PROTO((int fd, TRIO_CONST char *format, void **args));

int trio_cscanf TRIO_PROTO((trio_instream_t stream, trio_pointer_t closure,
                TRIO_CONST char *format, ...));
int trio_vcscanf TRIO_PROTO((trio_instream_t stream, trio_pointer_t closure,
                 TRIO_CONST char *format, va_list args));
int trio_cscanfv TRIO_PROTO((trio_instream_t stream, trio_pointer_t closure,
                 TRIO_CONST char *format, void **args));

int trio_sscanf TRIO_PROTO((TRIO_CONST char *buffer, TRIO_CONST char *format, ...));
int trio_vsscanf TRIO_PROTO((TRIO_CONST char *buffer, TRIO_CONST char *format, va_list args));
int trio_sscanfv TRIO_PROTO((TRIO_CONST char *buffer, TRIO_CONST char *format, void **args));

/*************************************************************************
 * Locale Functions
 */
void trio_locale_set_decimal_point TRIO_PROTO((char *decimalPoint));
void trio_locale_set_thousand_separator TRIO_PROTO((char *thousandSeparator));
void trio_locale_set_grouping TRIO_PROTO((char *grouping));

/*************************************************************************
 * Renaming
 */
#ifdef TRIO_REPLACE_STDIO
/* Replace the <stdio.h> functions */
#ifndef HAVE_PRINTF
# undef printf
# define printf trio_printf
#endif
#ifndef HAVE_VPRINTF
# undef vprintf
# define vprintf trio_vprintf
#endif
#ifndef HAVE_FPRINTF
# undef fprintf
# define fprintf trio_fprintf
#endif
#ifndef HAVE_VFPRINTF
# undef vfprintf
# define vfprintf trio_vfprintf
#endif
#ifndef HAVE_SPRINTF
# undef sprintf
# define sprintf trio_sprintf
#endif
#ifndef HAVE_VSPRINTF
# undef vsprintf
# define vsprintf trio_vsprintf
#endif
#ifndef HAVE_SNPRINTF
# undef snprintf
# define snprintf trio_snprintf
#endif
#ifndef HAVE_VSNPRINTF
# undef vsnprintf
# define vsnprintf trio_vsnprintf
#endif
#ifndef HAVE_SCANF
# undef scanf
# define scanf trio_scanf
#endif
#ifndef HAVE_VSCANF
# undef vscanf
# define vscanf trio_vscanf
#endif
#ifndef HAVE_FSCANF
# undef fscanf
# define fscanf trio_fscanf
#endif
#ifndef HAVE_VFSCANF
# undef vfscanf
# define vfscanf trio_vfscanf
#endif
#ifndef HAVE_SSCANF
# undef sscanf
# define sscanf trio_sscanf
#endif
#ifndef HAVE_VSSCANF
# undef vsscanf
# define vsscanf trio_vsscanf
#endif
/* These aren't stdio functions, but we make them look similar */
#undef dprintf
#define dprintf trio_dprintf
#undef vdprintf
#define vdprintf trio_vdprintf
#undef aprintf
#define aprintf trio_aprintf
#undef vaprintf
#define vaprintf trio_vaprintf
#undef asprintf
#define asprintf trio_asprintf
#undef vasprintf
#define vasprintf trio_vasprintf
#undef dscanf
#define dscanf trio_dscanf
#undef vdscanf
#define vdscanf trio_vdscanf
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WITHOUT_TRIO */

#endif /* TRIO_TRIO_H */
