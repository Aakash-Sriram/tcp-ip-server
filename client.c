#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<sys/types.h>

#define PORT 8080


int main(){
  
  int s;
  struct sockaddr_in sock;

  s = socket(AF_INET , SOCK_STREAM ,0);
  if(s<0){
    printf("socket() error\n");
    return 0;
  }
  memset(&sock,0,sizeof(sock));
  inet_pton(AF_INET, "127.0.0.1", &sock.sin_addr);
  sock.sin_port = htons(PORT);
  sock.sin_family = AF_INET;


  if( connect(s, (const struct sockaddr*)&sock,sizeof(sock) ) <0 ){
    perror("connect() error");
    close(s);
    return -1;
  }
  printf("connected\n");
  int no;
  printf("Enter no of messages to send:");
  scanf("%d",&no);
  getchar();
  printf("\n");
  while(no>0){
    printf("Enter text(or enter exit to quit): "); 
    char message[1024];
    scanf("%1023s",message);
    getchar();
    if(strncmp(message,"exit",4)==0){
      printf("\nBYE\n");
      break;
    }
    int sent = send(s,message,strlen(message),0);
    if(sent<0){
      printf("didnt work");
      close(s);
      break;
    }
    no--;
  }
  close(s);
  return 0;
  
}
