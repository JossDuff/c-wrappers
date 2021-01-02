/*
 * File: syscalls.c
 * Name: Joss Duff
 */

//include statements
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int Socket(int domain, int type, int protocol){
  int sock;
  if((sock=socket(domain, type, protocol))==-1){
    fprintf(stderr, "Socket error - %s", strerror(errno));
    exit(errno);
  }
  return sock;
}

int Bind(int sockfd, const struct sockaddr *address, socklen_t addrlength){
  int b;
  if((b=bind(sockfd, address, addrlength))==-1){
    fprintf(stderr, "Bind error - %s", strerror(errno));
    exit(errno);
  }
  return b;
}

int Listen(int sockfd, int backLog){
  int L;
  if((L=listen(sockfd, backLog))==-1){
    fprintf(stderr, "Listen error - %s", strerror(errno));
    exit(errno);
  }
  return L;
}

int Connect(int sockfd, const struct sockaddr *address, socklen_t addrlength){
  int C;
  if((C=connect(sockfd, address, addrlength))==-1){
    fprintf(stderr, "Connect error - %s", strerror(errno));
    exit(errno);
  }
  return C;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
  int a;
  if((a=accept(sockfd, addr, addrlen))==-1){
    fprintf(stderr, "Accept error - %s", strerror(errno));
    exit(errno);
  }
  return a;
}

ssize_t Recv(int sockfd, void *buf, size_t len, int flags){
  ssize_t r = recv(sockfd, buf, len, flags);
  if(r==-1){
    fprintf(stderr, "Recv error - %s", strerror(errno));
    exit(errno);
  }
  return r;
}

ssize_t Send(int sockfd, const void *buf, size_t len, int flags){
  ssize_t S;
  if((S=send(sockfd, buf, len, flags))==-1){
    fprintf(stderr, "Recv error - %s", strerror(errno));
    exit(errno);
  }
  return S;
}

int Socketpair(int domain, int type, int protocol, int sv[2]){
  int S;
  if((S=socketpair(domain, type, protocol, sv))==-1){
    fprintf(stderr, "Socketpair error - %s", strerror(errno));
    exit(errno);
  }
  return S;
}

int Pipe(int *fildes){
  int p;
  if((p=pipe(fildes))==-1){
    fprintf(stderr, "Pipe error - %s", strerror(errno));
    exit(errno);
  }
  return p;
}

pid_t Fork(){
  pid_t f;
  if((f=fork())==-1){
    fprintf(stderr, "Fork error - %s", strerror(errno));
    exit(errno);
  }
  return f;
}

pid_t Wait(int *status){
  pid_t W;
  if((W=wait(status))==-1){
    fprintf(stderr, "Wait error - %s", strerror(errno));
  }
  return W;
}

int Open(const char *path, int oflag, mode_t mode){
  int O;
  if((O=open(path, oflag, mode))==-1){
    fprintf(stderr, "Open error - %s", strerror(errno));
    exit(errno);
  }
  return O;
}

int Close(int d){
  int C;
  if((C=close(d))==-1){
    fprintf(stderr, "Close error - %s", strerror(errno));
    exit(errno);
  }
  return C;
}

ssize_t Write(int fd, void *buf, size_t nbyte){
  ssize_t W;
  if((W=write(fd, buf, nbyte))==-1){
    fprintf(stderr, "Write error - %s", strerror(errno));
    exit(errno);
  }
  return W;
}

ssize_t Read(int fd, void *buf, size_t nbyte){
  ssize_t R;
  if((R=read(fd, buf, nbyte))==-1){
    fprintf(stderr, "Read error - %s", strerror(errno));
    exit(errno);
  }
  return R;
}

FILE *Fopen(const char *path, const char *mode){
  FILE *fp = NULL;
  if((fp=fopen(path, mode))==NULL){
    fprintf(stderr, "Fopen error - %s", strerror(errno));
    exit(errno);
  }
  return fp;
}

void Fclose(FILE *fp){
  if(fclose(fp)==EOF){
    fprintf(stderr, "Fclose error - %s", strerror(errno));
    exit(errno);
  }
}

int Fseek(FILE *ptr, long offset, int position){
  int F;
  if((F=fseek(ptr, offset, position))==-1){
    fprintf(stderr, "Fseek error - %s", strerror(errno));
    exit(errno);
  }
  return F;
}

long Ftell(FILE *ptr){
  long F;
  if((F=ftell(ptr))==-1){
    fprintf(stderr, "Ftell error - %s", strerror(errno));
    exit(errno);
  }
  return F;
}

size_t Fread(void *buf, size_t itemSize, size_t numItems, FILE *stream){
  size_t R;
  R = fread(buf, itemSize, numItems, stream);
  if(ferror(stream)&&!feof(stream)){
    fprintf(stderr, "Fread error - %s", strerror(errno));
    exit(errno);
  }
  return R;
}

size_t Fwrite(const void *buf, size_t itemSize, size_t numItems, FILE *stream){
  size_t W;
  W = fwrite(buf, itemSize, numItems, stream);
  if(ferror(stream)){
    fprintf(stderr, "Fwrite error - %s", strerror(errno));
    exit(errno);
  }
  return W;
}

void *Malloc(size_t numBytes){
  void *ptr = NULL;
  if((ptr=malloc(numBytes))==NULL){
    fprintf(stderr, "Malloc error %s", strerror(errno));
    exit(errno);
  }
  return ptr;
}

int Uname(struct utsname *name){
  int u;
  if((u=uname(name))==-1){
    fprintf(stderr, "Uname error - %s", strerror(errno));
    exit(errno);
  }
  return u;
}
