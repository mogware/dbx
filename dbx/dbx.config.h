#ifndef __DBX_CONFIG__
#define __DBX_CONFIG__

#if defined(_MSC_VER)
#define DBX_MSVC
#if !defined(_DEBUG) && !defined(__DBX_INLINE__)
#define __DBX_INLINE__
#endif
#endif

#if defined(__GNUC__)
#define DBX_GCC
#if __GNUC__ < 4
#define DBX_GCC3
#endif
#if !defined (__NET_INLINE__)
#define __DBX_INLINE__
#endif
#endif

#if defined(DBX_LACKS_INLINE_FUNCTIONS) && !defined(DBX_NO_INLINE)
#define DBX_NO_INLINE
#endif

#if defined(DBX_NO_INLINE)
#undef __DBX_INLINE__
#endif

#if defined(__DBX_INLINE__)
#define DBX_INLINE inline
#else
#define DBX_INLINE
#endif

#endif

