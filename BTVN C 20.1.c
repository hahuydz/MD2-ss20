#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    double price;
    char category[50];
};

void nhapThongTinSach(struct Book books[], int *numOfBooks);
void hienThiThongTinSach(struct Book books[], int numOfBooks);
void themSach(struct Book books[], int *numOfBooks, int position);
void xoaSach(struct Book books[], int *numOfBooks, int id);
void capNhatThongTinSach(struct Book books[], int numOfBooks, int id);
void sapXepSach(struct Book books[], int numOfBooks, int ascending);
void timKiemSach(struct Book books[], int numOfBooks, char name[]);
int main() {
    struct Book books[100];
    int numOfBooks = 0;
    int choice, position, id;
    char name[50];

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapThongTinSach(books, &numOfBooks);
                break;
            case 2:
                hienThiThongTinSach(books, numOfBooks);
                break;
            case 3:
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                getchar();
                if (position < 0 || position > numOfBooks) {
                    printf("Vi tri them khong hop le.\n");
                } else {
                    themSach(books, &numOfBooks, position);
                }
                break;
            case 4:
                printf("Nhap ma sach can xoa: ");
                scanf("%d", &id);
                getchar();
                xoaSach(books, &numOfBooks, id);
                break;
            case 5:
                printf("Nhap ma sach can cap nhat: ");
                scanf("%d", &id);
                getchar();
                capNhatThongTinSach(books, numOfBooks, id);
                break;
            case 6:
                printf("a. Tang dan theo gia\nb. Giam dan theo gia\n");
                printf("Lua chon cua ban: ");
                char sortChoice;
                scanf(" %c", &sortChoice);
                getchar();
                if (sortChoice == 'a') {
                    sapXepSach(books, numOfBooks, 1);
                } else if (sortChoice == 'b') {
                    sapXepSach(books, numOfBooks, 0);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 7:
                printf("Nhap ten sach can tim: ");
                fgets(name, 50, stdin);
                name[strcspn(name, "\n")] = '\0';
                timKiemSach(books, numOfBooks, name);
                break;
            case 8:
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }

    return 0;
}
void nhapThongTinSach(struct Book books[], int *numOfBooks) {
    printf("Nhap so luong sach: ");
    scanf("%d", numOfBooks);
    getchar();

    for (int i = 0; i < *numOfBooks; i++) {
        books[i].id = i + 1;

        printf("Nhap thong tin sach thu %d:\n", books[i].id);

        printf("Nhap ten sach: ");
        fgets(books[i].name, 50, stdin);
        books[i].name[strcspn(books[i].name, "\n")] = '\0';

        printf("Nhap ten tac gia: ");
        fgets(books[i].author, 50, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = '\0';

        printf("Nhap gia tien: ");
        scanf("%lf", &books[i].price);
        getchar();

        printf("Nhap the loai: ");
        fgets(books[i].category, 50, stdin);
        books[i].category[strcspn(books[i].category, "\n")] = '\0';
    }
}

void hienThiThongTinSach(struct Book books[], int numOfBooks) {
    printf("Thong tin cac sach:\n");
    for (int i = 0; i < numOfBooks; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ma sach: %d\n", books[i].id);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
        printf("\n");
    }
}

void themSach(struct Book books[], int *numOfBooks, int position) {
    struct Book newBook;
    newBook.id = *numOfBooks + 1;

    printf("Nhap thong tin sach moi:\n");

    printf("Nhap ten sach: ");
    fgets(newBook.name, 50, stdin);
    newBook.name[strcspn(newBook.name, "\n")] = '\0';

    printf("Nhap ten tac gia: ");
    fgets(newBook.author, 50, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Nhap gia tien: ");
    scanf("%lf", &newBook.price);
    getchar();

    printf("Nhap the loai: ");
    fgets(newBook.category, 50, stdin);
    newBook.category[strcspn(newBook.category, "\n")] = '\0';

    for (int i = *numOfBooks; i > position; i--) {
        books[i] = books[i - 1];
    }
    books[position] = newBook;
    (*numOfBooks)++;
}

void xoaSach(struct Book books[], int *numOfBooks, int id) {
    int found = 0;
    for (int i = 0; i < *numOfBooks; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < *numOfBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            (*numOfBooks)--;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ma %d\n", id);
    }
}

void capNhatThongTinSach(struct Book books[], int numOfBooks, int id) {
    int found = 0;
    for (int i = 0; i < numOfBooks; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("Nhap thong tin moi cho sach co ma %d:\n", id);

            printf("Nhap ten sach moi: ");
            fgets(books[i].name, 50, stdin);
            books[i].name[strcspn(books[i].name, "\n")] = '\0';

            printf("Nhap ten tac gia moi: ");
            fgets(books[i].author, 50, stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0';

            printf("Nhap gia tien moi: ");
            scanf("%lf", &books[i].price);
            getchar();

            printf("Nhap the loai moi: ");
            fgets(books[i].category, 50, stdin);
            books[i].category[strcspn(books[i].category, "\n")] = '\0';

            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ma %d\n", id);
    }
}

void sapXepSach(struct Book books[], int numOfBooks, int ascending) {
    struct Book temp;
    for (int i = 0; i < numOfBooks - 1; i++) {
        for (int j = i + 1; j < numOfBooks; j++) {
            if ((ascending && books[i].price > books[j].price) || (!ascending && books[i].price < books[j].price)) {
                temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void timKiemSach(struct Book books[], int numOfBooks, char name[]) {
    int found = 0;
    for (int i = 0; i < numOfBooks; i++) {
        if (strcmp(books[i].name, name) == 0) {
            printf("Sach duoc tim thay: Ma sach: %d, Ten sach: %s, Tac gia: %s, Gia tien: %.2f, The loai: %s\n", books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ten %s\n", name);
    }
}

