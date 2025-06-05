#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<sys/types.h>
#include<string.h>

#define PORT 80

int main(){
  int s ;
  struct sockaddr_in sock;
  s = socket(AFNET,SOCK_STREAM,0);
  if(s<0){
    printf("socket() failed");
  }
  printf("socket() worked");
  memset(&sock,0,sizeof(sock));
  sock.sin_port = htons(PORT);
  sock.sin_addr.s_addr =htonl(INADDR_ANY);
  sock.sin_family = AF_INET;
 
  if (bind(s, (struct sockaddr*)&sock, sizeof(sock)) < 0) {
      perror("bind() error");
      close(s);
      return 1;
  }else printf("bind success!!\n");
  if (listen(s, 1) < 0) {
      perror("listen() error");
      close(s);
      return 1;
  }else printf("listeningg...");
  
}
