#ifndef	__13E_STRING_H__
#define	__13E_STRING_H__

#include <stddef.h>


extern void *   __13e_memset(void *__s, int __c, size_t __n);
extern size_t   __13e_strlen(const char *__s);
extern size_t   __13e_strnlen(const char *__s, size_t __maxlen);
extern int      __13e_memcmp(const void *__s1, const void *__s2, size_t __n);
extern int      __13e_strcmp(const char *__s1, const char *__s2);
extern int      __13e_strncmp(const char *__s1, const char *__s2, size_t __n);
extern char *   __13e_strcpy(char *__dest, const char *__src);
extern char *   __13e_strncpy(char *__dest, const char *__src, size_t __n);
extern void *   __13e_memcpy(void *__dest, const void *__src, size_t __n);
extern void *   __13e_memmove(void *__dest, const void *__src, size_t __n);


extern void *__13e_memchr(const void *__s, int __c, size_t __n);
extern void *__13e_memrchr(const void *__s, int __c, size_t __n);
extern char *__13e_strchr(const char *__s, int __c);
extern char *__13e_strrchr(const char *__s, int __c);
extern char *__13e_strcat(char *__dest, const char *__src);
extern char *__13e_strncat(char *__dest, const char *__src, size_t __n);


extern char *__13e_strdup(const char *__s);
extern char *__13e_strstr(const char *__haystack, const char *__needle);
extern char *__13e_strcasestr(const char *__haystack, const char *__needle);
extern char *__13e_strsep(char **__stringp, const char *__delim);

extern char *__13e_strtok(char *str, const char *delim);
extern char *__13e_strtok_r(char *str, const char *delim, char **saveptr);




#endif
