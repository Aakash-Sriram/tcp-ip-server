#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>


#define PORT 80

int main(){
  int s ;
  struct sockaddr_in sock;
  s = socket(AF_INET,SOCK_STREAM,0);
  if(s<0){
    printf("socket() failed");
  }
  printf("socket() worked");
  memset(&sock,0,sizeof(sock));
  sock.sin_port = htons(PORT);
inet_pton(AF_INET, "127.0.0.1", &sock.sin_addr);
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
  
  socklen_t socklen = sizeof(sock);
  
  int client_fd = accept(s,(struct sockaddr*)&sock,&socklen); 

  if( client_fd<0 ){
    perror("Not accepting");
    close(s);
    return 1;
  }else printf("accepted\n");

  char buffer[1024];
  while(1){
    memset(&buffer,0,sizeof(buffer));
    ssize_t rec = recv(client_fd,buffer,sizeof(buffer)-1,0);
    if(rec<0){
      perror("didnt receieve message");
      close(s);
      break;
      return -1;
      }
    else if(rec==0){
      perror("client connection closed");
      close(s);
      break;
      return -1;  
    }
    else{
      buffer[rec]='\0';
      printf("Recieved message: %s",buffer);
    }  
  }
  close(s);
  return 0;
}
