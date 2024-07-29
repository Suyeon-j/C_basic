#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 5000
#define MAX_CLIENTS 4 // 최대 접속 가능한 클라이언트 수 변경 (1 -> 4)
#define MAX_LENNICKNAME 20 // 닉네임의 최대 길이

int connected = 0;
int clientCount = 0; // 현재 접속 중인 클라이언트 수
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // 임계 구역을 위한 뮤텍스

typedef struct {
    int fd;
    char nickname[MAX_LENNICKNAME + 1]; // 클라이언트의 닉네임
} InfoClient;

InfoClient clients[MAX_CLIENTS]; // 클라이언트 정보를 저장하는 배열

void *my_thread(void *arg)
{
    InfoClient *client = (InfoClient *)arg;
    int fd = client->fd;

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < clientCount; i++) {
        if (clients[i].fd != client->fd) {
            char inMsg[256];

            snprintf(inMsg, sizeof(inMsg), "[%s] 님이 접속했습니다. 현재 접속 인원: %d\n", client->nickname, clientCount);
            write(clients[i].fd, inMsg, strlen(inMsg) + 1);
        }
    }
    printf("[%s] 님이 접속했습니다. 현재 접속 인원: %d\n", client -> nickname, clientCount);
    pthread_mutex_unlock(&mutex);

    do {
        char s[256];
        int bytes = read(client->fd, s, sizeof(s) - 1);
        if (bytes <= 0) {
           break; // 클라이언트가 연결을 끊었으므로 스레드를 종료합니다.
        }

        s[bytes] = '\0';

        // 클라이언트가 접속 종료 시 해당 클라이언트 정보 초기화 및 나머지 클라이언트에게 알림
        if (strcmp(s, "quit") == 0) {
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].fd != client->fd) {
                    char outMsg[256];

                    snprintf(outMsg, sizeof(outMsg), "%s님이 나갔습니다. 현재 참가 인원: %d\n", client->nickname, clientCount - 1);
                    write(clients[i].fd, outMsg, strlen(outMsg));
                }
            }
            printf("%s님이 나갔습니다. 현재 참가 인원: %d\n", client->nickname, clientCount - 1);
            for (int i = 0; i < clientCount; i++) {
                if (clients[i].fd == client->fd) {
                    clients[i].fd = -1;
                    memset(clients[i].nickname, 0, MAX_LENNICKNAME + 1);
                }
            }
            clientCount--;
            pthread_mutex_unlock(&mutex);
            break;
        }

        pthread_mutex_lock(&mutex);
        for (int i = 0; i < clientCount; i++) {
            if (clients[i].fd != client->fd) {
                char chatMsg[256];

                snprintf(chatMsg, sizeof(chatMsg), "[%s] %s\n", client->nickname, s);
                write(clients[i].fd, chatMsg, strlen(chatMsg));
                continue;
            }
        }
        printf("[%s] %s\n", client->nickname, s);
        pthread_mutex_unlock(&mutex);
    } while (1);
}

int main()
{
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int serv_fd;
    int cli_fd;
    pthread_t tid;

    // 클라이언트 초기화
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].fd = -1;
        memset(clients[i].nickname, 0, MAX_LENNICKNAME + 1);
    }

    if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("server socket error\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(serv_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("server bind error\n");
        return -1;
    }
    if (listen(serv_fd, 10) < 0) {
        printf("server listen error\n");
        return -1;
    }

    sleep(1);

    while (1) {
        socklen_t len = sizeof(client_addr);
        cli_fd = accept(serv_fd, (struct sockaddr *)&client_addr, &len);
        if (cli_fd < 0) {
            printf("accept failed\n");
            continue;
        }

        // 최대 접속 가능한 클라이언트 수를 초과한 경우
        if (clientCount >= MAX_CLIENTS) {
            const char* msg = "대화상대가 많아 접속할 수 없습니다.\n";
            int msgLen = strlen(msg) + 1; // null 문자를 포함한 문자열의 길이

            printf("%s\n", msg);
            write(cli_fd, msg, msgLen);
            close(cli_fd);
            continue;
        }

        // 닉네임 입력 받기
        pthread_mutex_lock(&mutex);
        char nickname[MAX_LENNICKNAME + 1];
        memset(nickname, 0, sizeof(nickname));
        int nickValid = 0;

        do {
            const char* enterMsg = "사용할 닉네임을 입력하세요 \n > ";
            int msgLen = strlen(enterMsg) + 1; // null 문자를 포함한 문자열의 길이

            write(cli_fd, enterMsg, msgLen);
            
            int bytes = read(cli_fd, nickname, sizeof(nickname) - 1);
            if (bytes <= 0) {
                printf("수신 오류\n");
                close(cli_fd);
                pthread_mutex_unlock(&mutex);
                continue;
            }
            nickname[bytes] = '\0';

            // 닉네임이 중복인지 확인
            nickValid = 1;
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].fd != -1 && strcmp(clients[i].nickname, nickname) == 0) {
                    nickValid = 0;
                    break;
                }
            }

            if (!nickValid) {
                const char* errMsg = "존재하는 닉네임입니다. 다른 닉네임을 입력하세요.\n";
                int msgLen = strlen(errMsg) + 1; // null 문자를 포함한 문자열의 길이

                write(cli_fd, errMsg, msgLen);
            }
        } while (!nickValid);

        // 클라이언트 정보 추가
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].fd == -1) {
                clients[i].fd = cli_fd;
                strncpy(clients[i].nickname, nickname, MAX_LENNICKNAME);
                clients[i].nickname[MAX_LENNICKNAME] = '\0';
                break;
            }
        }
        clientCount++;

        // 클라이언트 정보를 동적 할당하여 스레드로 전달
        InfoClient *newClient = (InfoClient *)malloc(sizeof(InfoClient));
        newClient -> fd = cli_fd;
        strncpy(newClient->nickname, nickname, MAX_LENNICKNAME);
        newClient -> nickname[MAX_LENNICKNAME] = '\0';

        // 새로운 클라이언트를 위한 스레드 생성
        if (pthread_create(&tid, NULL, my_thread, (void *)newClient) != 0) {
            printf("thread create error\n");
            free(newClient);
            continue;
        }
        pthread_detach(tid);
        pthread_mutex_unlock(&mutex);
    }
    close(serv_fd);
    return 0;
}
