//loader code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

//mycode
Location *parse_url(char *url)
{
    int i = 0,p = 0,sum = 0;
    char *ch = url,*pointer;
    pointer = ch;
    Location *web = calloc(1, sizeof(Location));
    web -> hash = (char *)calloc(500, sizeof(char));
    web -> protocol = (char *)calloc(500, sizeof(char));
    web -> search = (char *)calloc(500, sizeof(char));
    web -> pathname = (char *)calloc(500, sizeof(char));
    web -> host = (char *)calloc(500, sizeof(char));
    while(*ch != ':'){
        *(web -> protocol + i) = *ch;
        i++;
        ch++;
    }
    for(i = 0;i < 3;i++){
        if(*ch == '\n')
            return web;
        ch++;
    }
    i = 0;
    pointer = ch;
    while(*ch != ':' && *ch != '/' && *ch != '?' && *ch != '#' && *ch != '\n'){
        ch++;
        i++;
    }
    for(int j = 0;j < i;j++){
        *(web -> host + j) = *pointer;
        pointer++;
    }
    i = 0;
    while(1){
    	switch(*ch){
            case ':':
                ch++;
                while(*ch != '/' && *ch != '?' && *ch != '#' && *ch != '\n'){
                    sum *= 10;
                    sum += *ch - '0';
                    ch++;
                }
                ch--;
                if(sum)
                    web -> port = sum;
                break;
            case '/':
                ch++;
                while(*ch != '?' && *ch != '#' && *ch != '\n'){
                    *(web -> pathname + i) = *ch;
                    ch++;
                    i++;
                }
                i = 0;
                ch--;
                break;
            case '?':
                ch++;
                while(*ch != '#' && *ch != '\n'){
                    *(web -> search + i) = *ch;
                    ch++;
                    i++;
                }
                i = 0;
                ch--;
                break;
            case '#':
                ch++;
                while(*ch != '\n'){
                    *(web -> hash + i) = *ch;
                    ch++;
                    i++;
                }
                i = 0;
                ch--;
                break;
            case '\n':
                return web;
    	}
        ch++;
    }
}