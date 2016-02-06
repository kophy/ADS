#ifndef __SKIP_LIST_H__
#define __SKIP_LIST_H__

typedef struct SkipListNode {
    int key;
    void *data;
    int level;
    SkipListNode **next_nodes;
} SkipListNode;

class SkipList {
    public:
        SkipList(int max_level);
        ~SkipList(void);
        void insertNode(int key, void *data);
        void deleteNode(int key);
        void *getData(int key);
        void displayList(void);
    private:
        int MAX_LEVEL;
        int RandomLevel(void);
        SkipListNode *head;
        SkipListNode *tail;
};

#endif // __SKIP_LIST_H__
