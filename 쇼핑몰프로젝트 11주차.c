#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define FILENAME "product_data.txt"

// 상품 정보 구조체 정의
typedef struct {
    int id;             // 상품 ID (일련번호)
    char name[50];      // 상품명
    int price;          // 상품 가격
    int stock_in;       // 입고량
    int sold;           // 판매량
    int total_sales;    // 총 판매금액
} Product;

// 함수 선언
void displayMenu();
void stockIn(Product *product);
void sell(Product *product);
void displayProductInfo(Product *product);
void displayAllProducts(Product products[]);
void saveProductInfo(Product products[]);
void loadProductInfo(Product products[]);

int main() {
    Product products[MAX_PRODUCTS] = {0};  // 최대 5개 상품
    int choice;

    // 파일에서 상품 정보 불러오기
    loadProductInfo(products);

    while (1) {
        displayMenu();
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // 입고
                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    printf("상품 %d: %s\n", i + 1, products[i].name[0] ? products[i].name : "없음");
                }
                printf("입고할 상품을 선택하세요 (1-5): ");
                int idx;
                scanf("%d", &idx);
                if (idx >= 1 && idx <= MAX_PRODUCTS) {
                    stockIn(&products[idx - 1]);
                } else {
                    printf("잘못된 상품 선택입니다.\n");
                }
                break;
            case 2:
                // 판매
                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    printf("상품 %d: %s\n", i + 1, products[i].name[0] ? products[i].name : "없음");
                }
                printf("판매할 상품을 선택하세요 (1-5): ");
                scanf("%d", &idx);
                if (idx >= 1 && idx <= MAX_PRODUCTS) {
                    sell(&products[idx - 1]);
                } else {
                    printf("잘못된 상품 선택입니다.\n");
                }
                break;
            case 3:
                // 개별 상품 정보 출력
                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    printf("상품 %d: %s\n", i + 1, products[i].name[0] ? products[i].name : "없음");
                }
                printf("정보를 보고 싶은 상품을 선택하세요 (1-5): ");
                scanf("%d", &idx);
                if (idx >= 1 && idx <= MAX_PRODUCTS) {
                    displayProductInfo(&products[idx - 1]);
                } else {
                    printf("잘못된 상품 선택입니다.\n");
                }
                break;
            case 4:
                // 전체 상품 정보 출력
                displayAllProducts(products);
                break;
            case 5:
                // 종료
                saveProductInfo(products);
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
                break;
        }
    }

    return 0;
}

// 메뉴 출력
void displayMenu() {
    printf("\n--- 쇼핑몰 재고 관리 시스템 ---\n");
    printf("1. 입고\n");
    printf("2. 판매\n");
    printf("3. 개별 상품 정보\n");
    printf("4. 전체 상품 정보\n");
    printf("5. 종료\n");
}

// 입고 처리
void stockIn(Product *product) {
    int quantity;
    printf("입고할 수량을 입력하세요: ");
    scanf("%d", &quantity);
    product->stock_in += quantity;
    printf("입고가 완료되었습니다. 현재 입고량: %d\n", product->stock_in);
}

// 판매 처리
void sell(Product *product) {
    int quantity;
    printf("판매할 수량을 입력하세요: ");
    scanf("%d", &quantity);

    if (quantity > product->stock_in) {
        printf("재고가 부족합니다. 현재 재고: %d\n", product->stock_in);
    } else {
        product->stock_in -= quantity;
        product->sold += quantity;
        product->total_sales += product->price * quantity;
        printf("판매가 완료되었습니다. 현재 재고: %d, 판매량: %d, 총 판매금액: %d\n",
               product->stock_in, product->sold, product->total_sales);
    }
}

// 개별 상품 정보 출력
void displayProductInfo(Product *product) {
    printf("\n--- %s ---\n", product->name);
    printf("상품 ID: %d\n", product->id);
    printf("상품 가격: %d원\n", product->price);
    printf("입고량: %d\n", product->stock_in);
    printf("판매량: %d\n", product->sold);
    printf("총 판매금액: %d원\n", product->total_sales);
}

// 전체 상품 정보 출력
void displayAllProducts(Product products[]) {
    printf("\n--- 전체 상품 정보 ---\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("\n%s\n", products[i].name[0] ? products[i].name : "상품 없음");
        printf("상품 ID: %d\n", products[i].id);
        printf("상품 가격: %d원\n", products[i].price);
        printf("입고량: %d\n", products[i].stock_in);
        printf("판매량: %d\n", products[i].sold);
        printf("총 판매금액: %d원\n", products[i].total_sales);
    }
}

// 상품 정보를 파일에 저장
void saveProductInfo(Product products[]) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("파일 저장에 실패했습니다.\n");
        return;
    }

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        fprintf(file, "%d %s %d %d %d %d\n", products[i].id, products[i].name, products[i].price,
                products[i].stock_in, products[i].sold, products[i].total_sales);
    }

    fclose(file);
    printf("상품 정보가 저장되었습니다.\n");
}

// 파일에서 상품 정보를 불러오기
void loadProductInfo(Product products[]) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("저장된 상품 정보가 없습니다. 새로운 상품을 추가하세요.\n");
        return;
    }

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (fscanf(file, "%d %s %d %d %d %d", &products[i].id, products[i].name, &products[i].price,
                   &products[i].stock_in, &products[i].sold, &products[i].total_sales) != 6) {
            break;
        }
    }

    fclose(file);
    printf("상품 정보가 성공적으로 불러와졌습니다.\n");
}
