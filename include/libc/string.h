#ifndef _STRING_H
#define _STRING_H
/*
	string.h
*/

#if !defined(_SIZE_T) && !defined(_SIZE_T_)
#define _SIZE_T
#if (_MIPS_SZLONG == 32)
typedef unsigned int	size_t;
#endif
#if (_MIPS_SZLONG == 64)
typedef unsigned long	size_t;
#endif
#endif

#ifndef NULL
#define NULL	0
#endif

// char *stpcpy(char *,const char *);
// char *strcat(char *,const char *);
char *strchr(const char *,int);
// int  strcmp(const char *,const char *);
// char *strcpy(char *,const char *);
// size_t strcspn(const char *,const char *);
// char *strdup(const char *);
// char *strerror(int);
// int  stricmp(const char *,const char *);
size_t strlen(const char *);
// char *strlwr(char *);
// char *strncat(char *,const char *,size_t);
// int  strncmp(const char *,const char *,size_t);
// char *strncpy(char *,const char *,size_t);
// int  strnicmp(const char *,const char *,size_t);
// char *strnset(char *,int,size_t);
// char *strpbrk(const char *,const char *);
// char *strrchr(const char *,int);
// char *strrev(char *);
// char *strset(char *,int);
// size_t strspn(const char *,const char *);
// char *strstr(const char *,const char *);
// char *strtok(char *,const char *);
// char *strupr(char *);

// void *memccpy(void *,void *,int,size_t);
// void *memchr(void *,int,size_t);
// int  memcmp(const void *,const void *,size_t);
void *memcpy(void *,const void *,size_t);
// int  memicmp(void *,void *,size_t);
// void *memmove(void *,void *,size_t);
// void *memset(void *,int,size_t);

// void movmem(void *,void *,unsigned);
// void setmem(void *,unsigned,int);

// #define strcmpi(s1,s2)		stricmp(s1,s2)
// #define strncmpi(s1,s2,n)	strnicmp(s1,s2,n)

#endif

