#include <stdio.h>
#include <assert.h>
#include "13e_string.h"
#include <stdlib.h>

extern void *   __13e_memset(void *__s, int __c, size_t __n)
{
	unsigned char *p = (unsigned char *)__s;
	for (size_t i = 0; i < __n; i++) {
		p[i] = __c;
	}
	return __s;
}

extern size_t   __13e_strlen(const char *__s)
{
	size_t len = 0;
	while(__s[len] != 0)
		len++;

	return len;
}

extern size_t   __13e_strnlen(const char *__s, size_t __maxlen) {
	size_t len = 0;
	while(__s[len] != 0 && len < __maxlen) 
		len++;

	return len;	
}

extern int __13e_memcmp(const void *__s1, const void *__s2, size_t __n) {
    const unsigned char *p1 = (const unsigned char *)__s1;
    const unsigned char *p2 = (const unsigned char *)__s2;
    for (size_t i = 0; i < __n; i++) {
        if (p1[i] != p2[i]) 
            return p1[i] - p2[i];
    }
    return 0;
}


extern int __13e_strcmp(const char *__s1, const char *__s2) {
    const unsigned char *s1 = (const unsigned char *)__s1;
    const unsigned char *s2 = (const unsigned char *)__s2;
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

extern int      __13e_strncmp(const char *__s1, const char *__s2, size_t __n) {
	for (size_t i = 0; i < __n; i++) {
		if ((unsigned char)*__s1 != (unsigned char)*__s2 || *__s1 == 0 || *__s2 == 0) {
			return (unsigned char)*__s1 - (unsigned char)*__s2;
		}
		__s1++;
		__s2++;
	}
	return 0;
}


extern char *   __13e_strcpy(char *__dest, const char *__src) {
	assert(__src);
	assert(__dest);

	size_t i = 0;
	for (i = 0; __src[i] != 0; i++) {
		__dest[i] = __src[i];
	}
	__dest[i] = 0;

	return __dest;
}

extern char *   __13e_strncpy(char *__dest, const char *__src, size_t __n) {
    size_t i = 0;
    for (; i < __n && __src[i] != 0; i++) {
        __dest[i] = __src[i];
    }
    for (; i < __n; i++) {
        __dest[i] = 0;
    }
    return __dest;
}

extern void *   __13e_memcpy(void *__dest, const void *__src, size_t __n) {
    unsigned char *d = (unsigned char *)__dest;
    const unsigned char *s = (const unsigned char *)__src;
    for (size_t i = 0; i < __n; i++) {
        d[i] = s[i];
    }
    return __dest;
}


extern void *   __13e_memmove(void *__dest, const void *__src, size_t __n) {
    unsigned char *d = (unsigned char *)__dest;
    const unsigned char *s = (const unsigned char *)__src;
    if (d < s) {
        for (size_t i = 0; i < __n; i++)
            d[i] = s[i];
    } else if (d > s) {
        for (size_t i = __n; i > 0; i--)
            d[i - 1] = s[i - 1];
    }
    return __dest;
}

extern void* __13e_memchr(const void *__s, int __c, size_t __n) {
	unsigned char *p = (unsigned char*)__s;
	for (size_t i = 0; i < __n; i++) {
		if (p[i] == __c) {
			return p + i;
		}
	}

	return NULL;
}

extern void* __13e_memrchr(const void *__s, int __c, size_t __n) {
	unsigned char *p = (unsigned char*)__s;
	for (int i = (int)__n - 1; i >= 0; i--) {
		if (p[i] == __c) {
			return p + i;
		}
	}

	return NULL;
}

extern char *__13e_strchr(const char *__s, int __c) {
	unsigned char *p = (unsigned char*)__s;
	while (*p != 0) {
		if (*p == __c) {
			return (char *)p;
		}
		p++;
	}
	return NULL;
}

extern char *__13e_strrchr(const char *__s, int __c) {
	size_t len = __13e_strlen(__s);
	unsigned char *p = (unsigned char*)__s + len - 1;
	for (size_t i = 0; i < len; i++) {
		if (*p == __c) {
			return (char *)p;
		}
		p--;
	}
	return NULL;
}

extern char *__13e_strcat(char *__dest, const char *__src) {

	unsigned char *p = (unsigned char*)__dest;
    
    while (*__dest != '\0') {
        __dest++;
    }
    while (*__src != '\0') {
        *__dest = *__src;
        __dest++;
        __src++;
    }
    
    *__dest = '\0';
    
    return (char *)p;
}

extern char *__13e_strncat(char *__dest, const char *__src, size_t __n) {
    char *original_dest = __dest;
    
    while (*__dest != '\0') {
        __dest++;
    }
    
    size_t i = 0;
    while (i < __n && *__src != '\0') {
        *__dest = *__src;
        __dest++;
        __src++;
        i++;
    }
    
    *__dest = '\0';
    
    return original_dest;
}

char *__13e_strdup(const char *s) {
	if (s == NULL) {
		return NULL;
	}

	size_t len = __13e_strlen(s);
	char *new_str = malloc(len + 1);

	if (new_str == NULL) {
		return NULL;
	}

	__13e_strcpy(new_str, s);
	return new_str;
}

char *__13e_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return (char *)haystack;
        }
        haystack++;
    }
    return NULL;
}

char *__13e_strcasestr(const char *haystack, const char *needle) {
    if (*needle == 0) {
        return (char *)haystack;
    }
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n) {
            char c1 = *h;
            char c2 = *n;
            if (c1 >= 'A' && c1 <= 'Z') {
                c1 = c1 + ('a' - 'A');
            }
            if (c2 >= 'A' && c2 <= 'Z') {
                c2 = c2 + ('a' - 'A');
            }
            if (c1 != c2) {
                break;
            }
            h++;
            n++;
        }
        if (*n == 0) {
            return (char *)haystack;
        }
        haystack++;
    }
    return NULL;
}

char *__13e_strsep(char **stringp, const char *delim) {
    char *s;
    char *p;

    if (stringp == NULL || *stringp == NULL)
        return NULL;

    s = *stringp;
    p = s;

    while (*p) {
        const char *d = delim;
        while (*d) {
            if (*p == *d) {
                *p = 0;
                *stringp = p + 1;
                return s;
            }
            d++;
        }
        p++;
    }
    *stringp = NULL;
    return s;
}

char *__13e_strtok(char *str, const char *delim) {
    static char *save = NULL;
    char *start;

    if (str != NULL) {
        save = str;
    }

    if (save == NULL) {
        return NULL;
    }

    while (*save && __13e_strchr(delim, *save)) {
        save++;
    }

    if (*save == '\0') {
        save = NULL;
        return NULL;
    }

    start = save;

    while (*save && !__13e_strchr(delim, *save)) {
        save++;
    }

    if (*save) {
        *save = '\0';
        save++;
    } else {
        save = NULL;
    }

    return start;
}

char *__13e_strtok_r(char *str, const char *delim, char **saveptr) {
    char *start;

    if (str != NULL) {
        *saveptr = str;
    }

    if (*saveptr == NULL) {
        return NULL;
    }

    while (**saveptr && __13e_strchr(delim, **saveptr)) {
        *saveptr++;
    }

    if (**saveptr == '\0') {
        *saveptr = NULL;
        return NULL;
    }

    start = *saveptr;

    while (**saveptr && !__13e_strchr(delim, **saveptr)) {
        *saveptr++;
    }

    if (**saveptr) {
        **saveptr = '\0';
        *saveptr++;
    } else {
        *saveptr = NULL;
    }

    return start;
}
