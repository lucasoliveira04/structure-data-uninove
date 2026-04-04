#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7

typedef struct Node
{
    char *key;
    char *value;
    struct Node *next;
} Node;

// The HashMap is just an array of pointers to Node.
// Each position is "tail" of a Linkedlist

/*
[0] -> NULL
[1] -> Node("ab", "x") -> Node("ba", "y") -> NULL (Colisition)
[2] -> Node("nome", "Lucas") -> NULL
*/
typedef struct {
    Node *buckets[TABLE_SIZE];
} HashMap;

static unsigned int hash_fn(const char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = (unsigned char) *key++)) {
        hash = ((hash << c) + hash) + c;
    }
    return (unsigned int)(hash % TABLE_SIZE);
}

// Init map with all buckets NULLS
HashMap *hm_create(void) {
    HashMap *map = calloc(1, sizeof(HashMap));
    if (!map) {
        perror("calloc");
        exit(1);
    }
    return map;
}

// Insert or update key -> value
void hm_insert(HashMap *map, const char *key, const char *value) {
    unsigned int idx = hash_fn(key);
    Node *curr = map->buckets[idx];

    // Search key existing on bucket
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            // Key exist -> Update value
            free(curr->value);
            curr->value = strdup(value);
            return;
        }

        curr = curr->next;
    }

    // New key -> create Node and insert in init of list
    Node *node = malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = map->buckets[idx]; // Point to old head
    map->buckets[idx] = node; // New head
}

// Search and return value key associate
// Return NULL if not search
/*
    Median case - 0(1) - bucket with 0 or 1 Node
    Bad case - 0(n) - All keys on same bucket
*/
const char *hm_get(HashMap *map,const char *key) {
    unsigned int idx = hash_fn(key);
    Node *curr = map->buckets[idx];

    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }

        curr = curr->next;
    }

    return NULL;
}

void hm_free(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = map->buckets[i];
        while (curr) {
            Node *next = curr->next;
            free(curr->key);
            free(curr->value);
            free(curr);
            curr = next;
        }
    }

    free(map);
}

void hm_print(HashMap *map) {
    printf("\n=== HashMap (TABLE_SIZE=%d) ===\n", TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] ", i);
        Node *curr = map->buckets[i];
        if (!curr) { printf("NULL\n"); continue; }
        while (curr) {
            printf("(\"%s\" → \"%s\")", curr->key, curr->value);
            if (curr->next) printf(" → ");
            curr = curr->next;
        }
        printf("\n");
    }
    printf("===============================\n\n");
}

int main(void) {
    HashMap *map = hm_create();

    printf("-- Insert paris--\n");
    hm_insert(map, "nome",    "Lucas");
    hm_insert(map, "cidade",  "São Paulo");
    hm_insert(map, "linguagem", "C");
    hm_insert(map, "curso",   "estruturas de dados");

    hm_print(map);

    printf("-- Getting --\n");
    const char *keys[] = {"nome", "cidade", "idade"};
    for (int i = 0; i < 3; i++) {
        const char *v = hm_get(map, keys[i]);
        if (v) {
            printf("get(\"%s\") = \"%s\"\n", keys[i], v);
        } else {
            printf("get(\"%s\") = NULL (não encontrado)\n", keys[i]);
        }
    }

    printf("\n");
}