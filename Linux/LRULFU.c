#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10 // 최대 프레임 수
#define MAX_PAGES 40 // 최대 참조 시퀀스 길이

// LRU 알고리즘
void lru_algorithm(int frames[], int frame_count, int page_sequence[], int sequence_length) {
    int page_faults = 0;
    int *last_used = (int*)malloc(frame_count * sizeof(int));

    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    printf("LRU 알고리즘 결과:\n");
    printf("참조 시퀀스: ");
    for (int i = 0; i < sequence_length; i++) {
        printf("%d ", page_sequence[i]);
    }
    printf("\n\n");

    for (int i = 0; i < sequence_length; i++) {
        int page = page_sequence[i];
        int found = 0;

        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == page) {
                found = 1;
                last_used[j] = i;
                break;
            }
        }

        if (!found) {
            int replace_index = 0;
            for (int j = 1; j < frame_count; j++) {
                if (last_used[j] < last_used[replace_index])
                    replace_index = j;
            }

            frames[replace_index] = page;
            last_used[replace_index] = i;
            page_faults++;

            printf("참조 페이지: %d\tPage Fault 발생!\t페이지 프레임: ", page);
            for (int j = 0; j < frame_count; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("페이지 부재 비율: %d/%d\n\n", page_faults, sequence_length);

    free(last_used);
}

// LFU 알고리즘
void lfu_algorithm(int frames[], int frame_count, int page_sequence[], int sequence_length) {
    int page_faults = 0;
    int *frequency = (int*)malloc(frame_count * sizeof(int));
    int *usage = (int*)malloc(frame_count * sizeof(int));

    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1;
        frequency[i] = 0;
        usage[i] = 0;
    }

    printf("LFU 알고리즘 결과:\n");
    printf("참조 시퀀스: ");
    for (int i = 0; i < sequence_length; i++) {
        printf("%d ", page_sequence[i]);
    }
    printf("\n\n");

    for (int i = 0; i < sequence_length; i++) {
        int page = page_sequence[i];
        int found = 0;
        int min_frequency = frequency[0];
        int min_usage = usage[0];
        int replace_index = 0;

        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == page) {
                found = 1;
                frequency[j]++;
                break;
            }
        }

        if (!found) {
            replace_index = 0;
            min_frequency = frequency[0];
            min_usage = usage[0];

            for (int j = 1; j < frame_count; j++) {
                if (frequency[j] < min_frequency || (frequency[j] == min_frequency && usage[j] < min_usage)) {
                    min_frequency = frequency[j];
                    min_usage = usage[j];
                    replace_index = j;
                }
            }

            frames[replace_index] = page;
            frequency[replace_index] = 1;
            usage[replace_index] = i + 1; // 참조된 순서 업데이트
            page_faults++;

            printf("참조 페이지: %d\tPage Fault 발생!\t페이지 프레임: ", page);
            for (int j = 0; j < frame_count; j++) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("총 Page Faults: %d\n", page_faults);
    printf("페이지 부재 비율: %d/%d\n\n", page_faults, sequence_length);

    free(frequency);
    free(usage);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    int frame_count;
    int page_sequence[MAX_PAGES];
    int sequence_length = 0;

    fscanf(file, "%d", &frame_count);

    while (fscanf(file, "%d", &page_sequence[sequence_length]) != EOF) {
        sequence_length++;
    }

    fclose(file);

    int frames[MAX_FRAMES];

    lru_algorithm(frames, frame_count, page_sequence, sequence_length);
    lfu_algorithm(frames, frame_count, page_sequence, sequence_length);

    return 0;
}
