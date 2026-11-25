/*#define HASH_SIZE 10000
typedef struct HashNode {
    int key;   // 存储数组元素的值
    int value; // 存储数组元素的索引
    struct HashNode* next; // 指向下一个节点，用于链地址法解决冲突
} HashNode;

// 哈希表数组
HashNode* hashTable[HASH_SIZE];

// 哈希函数
int hash(int key) {
    return abs(key) % HASH_SIZE;
}

// 初始化哈希表
void initHashTable() {
    memset(hashTable, 0, sizeof(hashTable));//初始化函数，下面解释
}

// 插入哈希表
void insert(int key, int value) {
    int index = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;//头插法
}

// 查找哈希表
int search(int key) {
    int index = hash(key);
    HashNode* node = hashTable[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value; 
        }
        node = node->next;
    }
    return -1; // 未找到
}

// 清理哈希表
void clearHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    initHashTable(); // 初始化哈希表
    int* result = (int*)malloc(2 * sizeof(int)); // 分配结果数组
    *returnSize = 2; // 设置返回数组的大小为 2

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i]; // 计算目标值与当前元素的差值
        int index = search(complement); // 在哈希表中查找差值
        if (index != -1) {
            result[0] = index; // 找到匹配的索引
            result[1] = i;     // 当前元素的索引
            return result;
        }
        insert(nums[i], i); // 将当前元素插入哈希表
    }

    // 如果没有找到解，释放结果数组并返回 NULL
    *returnSize = 0;
    free(result);
    return NULL;
}*/
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
    int index=key%HashSize;
    HashNode* NewNode = malloc(sizeof(HashNode));
    NewNode->key =key;
    NewNode->value = value;
    NewNode->next=HashTable[index];
    HashTable[index] = NewNode;
}