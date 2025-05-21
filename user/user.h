struct stat;
struct datetime {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
};

int datetime(struct datetime *);

// system calls
int fork(void);
int exit(int) __attribute__((noreturn)); //1.6,1.7 Exit a process
int wait(int*);
int pipe(int*);
int write(int, const void*, int); //1.2,1.5 Write to a file
int read(int, void*, int); //1.2,1.5 Read a file
int close(int); //1.2,1.3,1.5 Close a file
int kill(int);
int exec(const char*, char**);
int open(const char*, int); //1.2,1.3,1.5 Open a file
int mknod(const char*, short, short);
int unlink(const char*); //1.4 Delete a file
int fstat(int fd, struct stat*); //1.2,1.3 Get file status
int link(const char*, const char*); //1.4 Create a hard link
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int); //1.1 Sleep for a number of milliseconds
int uptime(void);
int kbdint(void); //2.1 Keyboard interrupt
int countsyscall(void); //2.2 Count system calls
int getppid(void);
int getptable(int nproc, void *buffer); //2.4 Get process table
int randd(void); //2.6 Random number generator

// ulib.c
int stat(const char*, struct stat*); //1.2 Get file status
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void fprintf(int, const char*, ...) __attribute__ ((format (printf, 2, 3)));
void printf(const char*, ...) __attribute__ ((format (printf, 1, 2))); //1.6,1.7 Convert string to integer
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
int atoi(const char*); //1.6,1.7 Convert string to integer
int memcmp(const void *, const void *, uint);
void *memcpy(void *, const void *, uint);

// umalloc.c
void* malloc(uint);
void free(void*);
int setscheduler(int mode);
int setpriority(int pid, int priority);
int printmetrics(void);
