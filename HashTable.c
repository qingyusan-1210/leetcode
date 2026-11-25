#include <stdlib.h> // malloc、free、abs、NULL
#include <string.h> // memset
#define HashSize 10

typedef struct HashNode{
         int key;
         int value;
         struct HashNode* next;
}HashNode;

HashNode* HashTable[HashSize];

int hash(int key){
    return abs(key)%HashSize;
}

void initHashTable(){
    memset(HashTable,0,sizeof(HashTable));
}

void insert(int key,int value){
    int index=hash(key);
    HashNode* NewNode = malloc(sizeof(HashNode));
    NewNode->key =key;
    NewNode->value = value;
    NewNode->next=HashTable[index];
    HashTable[index] = NewNode;
}

int search(int key){
    int index = hash(key);
    HashNode* node = HashTable[index];
    while(node !=NULL){
         if(node->key==key){
            return node->value;
         }
         node=node->next;
    }
    return -1;
}

void clearHashTable(){
    for(int i=0;i<HashSize;i++){
        HashNode* node = HashTable[i];
        while(node!=NULL){
              HashNode* temp = node;
              node = node->next;
              free(temp);
        }
    }
}