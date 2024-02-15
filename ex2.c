#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int retval;

    // Tạo một tập tin mô tả cho stdin
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // Thiết lập timeout là 5 giây
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    // Sử dụng hàm select để chờ đợi cho đến khi stdin có sẵn
    retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);
    if (retval == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } else if (retval) {
        printf("Dữ liệu sẵn có để đọc.\n");
        // Xử lý dữ liệu từ stdin ở đây
    } else {
        printf("Hết thời gian chờ đợi, không có dữ liệu sẵn có.\n");
    }

    return 0;
}
