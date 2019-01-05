#ifndef CAD
#define CAD

void * s_memcpy(void *, const void * , int );
int s_memcmp(const void * , const void * , int );
void * s_memset(void *, int , int );
void * s_memchr (void *, int , int );
char * s_strcpy (char * , const char * );
char * s_strncpy (char * , const char * , int );
char * s_strcat (char *, const char *);
int s_strcmp (const char * , const char * );
int s_strcmpi (const char * , const char * );
char * s_strstr(char *, const char *);
int s_strlen(const char *); 

#endif