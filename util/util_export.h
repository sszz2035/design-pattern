#ifndef _UTIL_EXPORT_H_
#define _UTIL_EXPORT_H_

// DLL 导出/导入宏定义
#ifdef _WIN32
    #ifdef UTIL_EXPORTS
        #define UTIL_API __declspec(dllexport)
    #else
        #define UTIL_API __declspec(dllimport)
    #endif
#else
    #define UTIL_API
#endif

#endif // _UTIL_EXPORT_H_
