#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct Product
{
    char id[100];
    char name[100];
    float importPrice;
    float sellingPrice;
    int quantity;
};

void createProduct(struct Product product[100],int *size,float revenue);
void displayProduct(struct Product product[100],int *size);
void addProduct(struct Product product[100],struct Product newProduct,int *size,float revenue);
void updateProduct(struct Product product[100],int *size,float revenue);
void sortProduct(struct Product product[100],int *size);
void searchProduct(struct Product product[100],int *size,char item[100]);
void sellProduct(struct Product product[100],int *size,float revenue);

int main(){
    int choice,size = 0;
    float revenue = 0;
    char item[100];
    struct Product product[100];
    struct Product newProduct;
    do
    {
        printf("______________________________________________\n");
        printf("        Menu\n");
        printf("1, Nhap so luong va thong tin san pham\n");
        printf("2, Hien thi danh sach san pham\n");
        printf("3, Nhap san pham\n");
        printf("4, Cap nhat thong tin san pham\n");
        printf("5, Sap xep san pham theo gia\n");
        printf("6, Tim kiem san pham\n");
        printf("7, Ban san pham\n");
        printf("8, Doanh thu hien tai\n");
        printf("9, Thoat\n");
        printf("Nhap lua chon cua ban : ");
        scanf("%d",&choice);
        printf("______________________________________________\n");
        switch (choice)
        {
        case 1:
            printf("Nhap so luong san pham : ");
            scanf("%d",&size);
            createProduct(product,&size,revenue);
            break;
        case 2:
            if (size == 0)
            {
                printf("Chua co san pham nao!\n");
            }
            else{
                displayProduct(product,&size);
            }
            break;
        case 3:
            addProduct(product,newProduct,&size,revenue);
            break;
        case 4:
            if (size == 0)
            {
                printf("Chua co san pham nao!\n");
            }
            else{
                updateProduct(product,&size,revenue);
            }
            break;
        case 5:
            if (size == 0)
            {
                printf("Chua co san pham nao!\n");
            }
            else{
                sortProduct(product,&size);
            }
            break;
        case 6:
            printf("Nhap ma san pham muon tim : ");
            fflush(stdin);
            fgets(item,sizeof(item),stdin);
            item[strcspn(item, "\n")] = '\0';
            searchProduct(product,&size,item);
            break;
        case 7:
            sellProduct(product,&size,revenue);
            break;
        case 8:
            printf("%f\n",revenue);
            break;
        case 9:
            printf("Tam biet!\n");
            break;
        default:
            printf("Khong hop le, Nhap lai!!\n");
            break;
        }
    } while (choice != 9);   
}

void createProduct(struct Product product[100],int *size,float revenue){
    for (int i = 0; i < *size; i++)
    {
        printf("Nhap thong tin san pham thu %d : \n",i+1);
        printf("Ma san pham : ");
        fflush(stdin);
        fgets(product[i].id,sizeof(product[i].id),stdin);
        product[i].id[strcspn(product[i].id, "\n")] = '\0';
        printf("Ten san pham : ");
        fgets(product[i].name,sizeof(product[i].name),stdin);
        product[i].name[strcspn(product[i].name, "\n")] = '\0';
        printf("Gia nhap : ");
        scanf("%f",&product[i].importPrice);
        printf("Gia ban : ");
        scanf("%f",&product[i].sellingPrice);
        printf("So luong : ");
        scanf("%d",&product[i].quantity);
        revenue -= (product[i].quantity * product[i].importPrice);
    }   
}

void displayProduct(struct Product product[100],int *size){
    for (int i = 0; i < *size; i++)
    {
        printf("\nThong tin san pham thu %d :\n",i+1);
        printf("Ma san pham : %s\n",product[i].id);
        printf("Ten san pham : %s\n",product[i].name);
        printf("Gia ban : %.2f\n",product[i].sellingPrice);
        printf("So luong : %d\n",product[i].quantity);
    }
}

void addProduct(struct Product product[100],struct Product newProduct,int *size,float revenue){
    printf("Ma san pham : ");
    fflush(stdin);
    fgets(newProduct.id,sizeof(newProduct.id),stdin);
    newProduct.id[strcspn(newProduct.id, "\n")] = '\0';
    printf("Ten san pham : ");
    fgets(newProduct.name,sizeof(newProduct.name),stdin);
    newProduct.id[strcspn(newProduct.id, "\n")] = '\0';
    printf("Gia nhap : ");
    scanf("%f",&newProduct.importPrice);
    printf("Gia ban : ");
    scanf("%f",&newProduct.sellingPrice);
    printf("So luong : ");
    scanf("%d",&newProduct.quantity);
    revenue -= (newProduct.quantity * newProduct.importPrice);
}

void updateProduct(struct Product product[100],int *size,float revenue){
    int x;
    printf("Cac san pham hien co : \n");
    for (int i = 0; i < *size; i++)
    {
        printf("%d, %s\n",i+1,product[i].name);
    }
    printf("Nhap san pham ban muon sua : ");
    scanf("%d",&x);
    x++;
    if (x < 0 || x > *size)
    {
        printf("San pham khong hop le!\n");
    }
    else{
        printf("Ma san pham : ");
        fflush(stdin);
        fgets(product[x].id,sizeof(product[x].id),stdin);
        product[x].id[strcspn(product[x].id, "\n")] = '\0';
        printf("Ten san pham : ");
        fgets(product[x].name,sizeof(product[x].name),stdin);
        product[x].name[strcspn(product[x].name, "\n")] = '\0';
        printf("Gia nhap : ");
        scanf("%f",&product[x].importPrice);
        printf("Gia ban : ");
        scanf("%f",&product[x].sellingPrice);
        printf("So luong : ");
        scanf("%d",&product[x].quantity);
        revenue -= (product[x].quantity * product[x].importPrice);
    }
}

void sortProduct(struct Product product[100],int *size){
    int x;
    struct Product temp;
    printf("1, Tang dan theo gia\n");
    printf("2, Giam dan theo gia\n");
    printf("Nhap lua chon cua ban : ");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        for (int i = 0; i < *size; i++){
            for (int j = 0; j < *size-1-i; j++)
            {
                if (product[j].sellingPrice > product[j+1].sellingPrice)
                    {
                        temp = product[j];
                        product[j] = product[j+1];
                        product[j+1] = temp;
                    }
            }
        }
        break;
    case 2:
        for (int i = 0; i < *size; i++){
            for (int j = 0; j < *size-1-i; j++)
            {
                if (product[j].sellingPrice < product[j+1].sellingPrice)
                    {
                        temp = product[j];
                        product[j] = product[j+1];
                        product[j+1] = temp;
                    }
            }
        }
        break;
    }
}

void searchProduct(struct Product product[100],int *size,char item[100]){
    char temp[100];
    int found = 0;
    for (int i = 0; i < strlen(item); i++)
    {
        item[i] = toupper(item[i]);
    }
    for (int i = 0; i < *size; i++)
    {
        strcpy(temp,product[i].id);
        for (int i = 0; i < strlen(temp); i++)
        {
            temp[i] = toupper(temp[i]);
        }
        if (strcmp(temp,item)==0)
        {
            printf("Ma san pham : %s\n",product[i].id);
            printf("Ten san pham : %s\n",product[i].name);
            printf("Gia ban : %.2f\n",product[i].sellingPrice);
            printf("So luong : %d\n",product[i].quantity);        
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Khong tim thay san pham!\n");
    }
}

void sellProduct(struct Product product[100],int *size,float revenue){
    int x,value;
    printf("Cac san pham hien co : \n");
    for (int i = 0; i < *size; i++)
    {
        printf("%d, %s\n",i+1,product[i].name);
    }
    printf("Nhap san pham ban muon mua : ");
    scanf("%d",&x);
    x++;
    if (product[x].quantity == 0)
    {
        printf("Da het hang!\n");
    }
    printf("Nhap so luong ban muon mua : ");
    scanf("%d",&value);
    if (product[x].quantity < value)
    {
        printf("Khong con du hang!\n");
    }
    else{
        product[x].quantity -= value;
        revenue += (value * product[x].sellingPrice);
    }
}
