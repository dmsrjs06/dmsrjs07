#include "LinkedList.h"

PointType* getNodeAt(LinkedList* li, int index) {
    if (index <= 0 || index > li->size) return NULL;
    PointType* ptr = li->head;
    for (int i = 0; i < index - 1; i++) {
        ptr = ptr->next;
    }
    return ptr;
}

void printMenu() {
    printf("\n=============================\n");
    printf("   정수 연결 리스트 메뉴\n");
    printf("=============================\n");
    printf(" 1. 맨 앞에 추가\n");
    printf(" 2. 맨 뒤에 추가\n");
    printf(" 3. 특정 위치에 추가\n");
    printf(" 4. 특정 위치 삭제\n");
    printf(" 5. 전체 목록 출력\n");
    printf(" 6. 리스트 크기 확인\n");
    printf(" 0. 종료\n");
    printf("=============================\n");
    printf("선택: ");
}

int main() {
    LinkedList* myList = createLinkedList();
    int choice, value, index;

    while (1) {
        printMenu();
        scanf_s("%d", &choice);

        switch (choice) {

        case 1:
            printf("추가할 정수 입력: ");
            scanf_s("%d", &value);
            insertFirstLinkedList(myList, (PointType) { value, 0, 0 });
            printf("%d을(를) 맨 앞에 추가했습니다.\n", value);
            break;

        case 2:
            printf("추가할 정수 입력: ");
            scanf_s("%d", &value);
            insertLastLinkedList(myList, (PointType) { value, 0, 0 });
            printf("%d을(를) 맨 뒤에 추가했습니다.\n", value);
            break;

        case 3:
            printf("삽입할 위치(index, 0 ~ %d) 입력: ", myList->size);
            scanf_s("%d", &index);
            if (index < 0 || index > myList->size) {
                printf("유효하지 않은 인덱스입니다.\n");
                break;
            }
            printf("추가할 정수 입력: ");
            scanf_s("%d", &value);
            if (index == 0) {
                insertItemLinkedList(myList, NULL, (PointType) { value, 0, 0 });
            }
            else {
                PointType* pre = getNodeAt(myList, index);
                insertItemLinkedList(myList, pre, (PointType) { value, 0, 0 });
            }
            printf("위치 %d에 %d을(를) 추가했습니다.\n", index, value);
            break;

        case 4:
            if (isEmptyLinkedList(myList)) {
                printf("리스트가 비어 있습니다.\n");
                break;
            }
            printf("삭제할 위치(index, 0 ~ %d) 입력: ", myList->size - 1);
            scanf_s("%d", &index);
            deleteAtLinkedList(myList, index);
            break;

        case 5:
            if (isEmptyLinkedList(myList)) {
                printf("리스트가 비어 있습니다.\n");
            }
            else {
                printf("전체 목록: ");
                printLinkedList(myList);
            }
            break;

        case 6:
            printf("현재 리스트 크기: %d\n", sizeLinkedList(myList));
            break;

        case 0:
            printf("프로그램을 종료합니다. 메모리를 해제합니다.\n");
            destroyLinkedList(myList);
            return 0;

        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
    }
}   