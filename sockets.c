#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<sys/types.h>

#define IP"142.250.66.4" 
#define PORT 80 

//       #include <sys/socket.h>

//       int socket(int domain, int type, int protocol);

int main(){
  
  int s;
  struct sockaddr_in sock;

  s = socket(AF_INET , SOCK_STREAM ,0);
  if(s<0){
    printf("socket() error\n");
    return 0;
  }
  memset(&sock,0,sizeof(sock));
  sock.sin_addr.s_addr = inet_addr(IP);
  sock.sin_port = htons(PORT);
  sock.sin_family = AF_INET;


  if( connect(s, (struct sock_addr*)&socket,sizeof(sock_addr) ) <0 ){
    printf("connect() error\n");
    close(s);
    return -1;
  }

  printf("connected");
  char *message="Yoooo";
  int sent = send(s,message,strlen(message),0);
  if(sent<0)printf("didnt work");
  close(s);
  return 0;
  
}
