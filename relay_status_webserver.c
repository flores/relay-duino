#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char status[256];
  char current[10];
  struct sockaddr_in serv_addr, cli_addr;
  int response;
  int trigger;
  int pin;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  portno = atoi(argv[1]);
  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  
  listen(sockfd,5);

  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  
  strcpy(status, "pin: expected_status actual_status\n");
  for (trigger = 8; trigger < 13; trigger++) {
    pin = trigger - 6;
    if ( digitalRead(trigger) == 1 ) {
      strcpy(current, pin);
      strcat(current, ": on ");
      strcat(current, digitalRead(pin));
      strcat(current, "\n");
      strcat(status, current);
    } else {
      strcpy(current, pin);
      strcat(current, ": off ");
      strcat(current, digitalRead(pin));
      strcat(current, "\n");
      strcat(status, current);
    }
  }

  response = strlen(status);
  n = write(newsockfd, status, response);
  
  close(newsockfd);
  close(sockfd);
}

