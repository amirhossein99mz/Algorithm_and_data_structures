Linked List: A linear data structure of nodes where each node stores data and a pointer to the next node.

Visit: Access or read the data of a node (e.g.,printf("%d", q->data);).

Insertion: Add a new node by adjusting pointers (e.g., new->next = q->next; q->next = new;).

Extraction: Remove a node by skipping it (e.g., q->next = q->next->next;).

Sentinel: A dummy node (head/tail) used to simplify list operations.


0 sentinel: head -> 10 -> 20 -> NULL

1 sentinel (head): head(sentinel) -> 10 -> 20 -> NULL

2 sentinels (head & tail): head(sentinel) -> 10 -> 20 -> tail(sentinel)