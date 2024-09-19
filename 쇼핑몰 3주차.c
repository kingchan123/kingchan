#include <stdio.h>

void restock(int *inventory, int size) {
    int choice, quantity;
    printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전체 상품의 입고수량을 입력 (공백으로 구분): ");
        for (int i = 0; i < size; i++) {
            scanf("%d", &quantity);
            inventory[i] += quantity;  // 전체 상품 입고
        }
    } else if (choice == 2) {
        int productID;
        printf("상품ID : ");
        scanf("%d", &productID);
        printf("입고수량 : ");
        scanf("%d", &quantity);
        inventory[productID] += quantity;  // 개별 상품 입고
    }
}

void sell(int *inventory, int size) {
    int choice, quantity;
    printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("전체 상품의 판매수량을 입력 (공백으로 구분): ");
        for (int i = 0; i < size; i++) {
            scanf("%d", &quantity);
            inventory[i] -= quantity;  // 전체 상품 판매
        }
    } else if (choice == 2) {
        int productID;
        printf("상품ID : ");
        scanf("%d", &productID);
        printf("판매수량 : ");
        scanf("%d", &quantity);
        inventory[productID] -= quantity;  // 개별 상품 판매
    }
}

void displayInventory(int *inventory, int size) {
    printf("현재 상품 현황:\n");
    for (int i = 0; i < size; i++) {
        printf("상품ID %d: %d개\n", i, inventory[i]);
    }
}

int main() {
    int inventory[5] = {0};  // 초기 재고 수량
    int menu;

    while (1) {
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                restock(inventory, 5);
                break;
            case 2:
                sell(inventory, 5);
                break;
            case 3:
                displayInventory(inventory, 5);
                break;
            case 4:
                return 0;
            default:
                printf("잘못된 입력입니다.\n");
        }
    }
}
