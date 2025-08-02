#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci{

    int ogrenciNo;
    int sinif;
    char isim[30];
    char soyisim[30];
    char bolum[100];

    struct ogrenci* next;
    struct ogrenci* prev;

};

struct ogrenci* head = NULL;

void createList(){

    if(head != NULL) {
        printf("Liste zaten olusturululmus...\n");
        return;

    head = NULL;
    printf("Liste olusturuldu...\n");
    }

}

void destroyList(){
    struct ogrenci* current = head;
    struct ogrenci* next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
    printf("Liste silindi...\n");
}

void addNode(int ogrenciNo, const char* isim, const char* soyisim, const char* bolum, int sinif){

    struct ogrenci* newNode = (struct ogrenci*)malloc(sizeof(struct ogrenci));

    newNode->ogrenciNo = ogrenciNo;
    newNode->sinif = sinif;
    strcpy(newNode->isim, isim);
    strcpy(newNode->soyisim, soyisim);
    strcpy(newNode->bolum, bolum);

    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL){

        head = newNode;

    } else{
        struct ogrenci* current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}



void deleteNode(int ogrenciNo) {
    struct ogrenci* current = head;
    struct ogrenci* prev = NULL;

    while (current != NULL && current->ogrenciNo != ogrenciNo) {
        prev = current;
        current = current->next;
    }

    if(current == NULL){
        printf("%d nolu ogrenci bulunamadi...\n", ogrenciNo);
        return;
    }

    if(prev == NULL){
        head = current->next;
    } else {
        prev->next = current->next;
        if(current->next != NULL){
            current->next->prev = prev;
        }
    }

    free(current);
}


struct ogrenci* searchNode(int ogrenciNo){
    struct ogrenci* current = head;

    while(current != NULL && current->ogrenciNo != ogrenciNo){
        current = current->next;
    }

    return current;
}


void displayList() {
    struct ogrenci* current = head;

    if (current == NULL) {
        printf("Liste bos...\n");
        return;
    }

    printf("Ogrenci Listesi:\n");
    while (current != NULL) {
        printf("Ogrenci No: %d, Isim: %s, Soyisim: %s, Bolum: %s, Sinif: %d\n",
               current->ogrenciNo, current->isim, current->soyisim, current->bolum, current->sinif);
        current = current->next;
    }
}

int main() {
    int k;
    int ogrenciNo, sinif;
    char isim[30], soyisim[30], bolum[100];

    while (1) {
        printf("\n***Menu***\n");
        printf("1-> Create link list\n");
        printf("2-> Destroy linked list\n");
        printf("3-> Add node\n");
        printf("4-> Delete node\n");
        printf("5-> Search node\n");
        printf("6-> Display list\n");
        printf("7-> Exit\n");
        printf("Seciminizi giriniz: ");
        scanf("%d", &k);

        switch (k) {
            case 1:
                createList();
                break;
            case 2:
                destroyList();
                break;
            case 3:
                printf("Ogrenci No: ");
                scanf("%d", &ogrenciNo);
                printf("Isim: ");
                scanf("%s", isim);
                printf("Soyisim: ");
                scanf("%s", soyisim);
                printf("Bolum: ");
                scanf("%s", bolum);
                printf("Sinif: ");
                scanf("%d", &sinif);
                addNode(ogrenciNo, isim, soyisim, bolum, sinif);
                break;
            case 4:
                printf("Silmek istediginiz ogrencinin numarasini giriniz: ");
                scanf("%d", &ogrenciNo);
                deleteNode(ogrenciNo);
                break;
            case 5:
                printf("Bulmak istediginiz ogrencinin numarasini giriniz: ");
                scanf("%d", &ogrenciNo);
                struct ogrenci* foundNode = searchNode(ogrenciNo);
                if (foundNode != NULL) {
                    printf("Isim: %s, Soyisim: %s, Bolum: %s, Sinif: %d\n",
                           foundNode->isim, foundNode->soyisim, foundNode->bolum, foundNode->sinif);
                } else {
                    printf("Ogrenci bulunamadi...\n");
                }
                break;
            case 6:
                displayList();
                break;
            case 7:
                exit(0);
            default:
                printf("Lutfen gecerli bir islem seciniz...\n");
        }
    }

    return 0;
}

