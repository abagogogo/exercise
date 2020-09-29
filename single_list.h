/*!
 * Define a link list node.
 */
typedef struct _GLIST_ENTRY {
    struct _GLIST_ENTRY *next;
} GLIST_ENTRY, *PGLIST_ENTRY;

/*!
 * Define a link list.
 */
typedef struct _GLIST_HEADER {
    PGLIST_ENTRY head;
    PGLIST_ENTRY tail;
    unsigned int count;
} GLIST_HEADER, *PGLIST_HEADER;

/*!
 * Initialize a link list.
 */
#define GLIST_INITIALIZE(_list) { \
        (_list)->head = (_list)->tail = NULL; \
        (_list)->count = 0; \
    }

/*!
 * Check if the list is empyt.
 */
#define GLIST_IS_EMPTY(_list) \
    ((_list)->head == NULL)

/*!
 * Insert a node to head of the list.
 * @param _list The list to be inserted.
 * @param _entry The node to insert.
 */
#define GLIST_INSERT_HEAD(_list, _entry) { \
        (_entry)->next = (_list)->head; \
        (_list)->head = (_entry); \
        if ((_list)->tail == NULL) (_list)->tail = (_entry); \
        ++(_list)->count; \
    }

/*!
 * Remove one node from the head of the list.
 * @param _list The list to remove its head node.
 * @return The node removed. 
 */
#define GLIST_REMOVE_HEAD(_list) { \
        (_list)->head; \
        if ((_list)->head) { \
            PGLIST_ENTRY _next = (_list)->head->next; \
            (_list)->head = _next; \
            if ((_next) == NULL) (_list)->tail = NULL; \
            --(_list)->count; \
        } \ 
    }

/*!
 * Insert a node to tail of the list.
 * @param _list The list to be inserted.
 * @param _entry The node to insert.
 */
#define GLIST_INSERT_TAIL(_list, _entry) { \
        (_entry)->next = NULL; \
        if ((_list)->tail) (_list)->tail->next = _entry; \
        else (_list)->head = _entry; \
        ((_list)->tail) = _entry; \
        ++(_list)->count; \
    }


/*!
 * Insert a new node after the specified node.
 * @param _list The list to be inserted.
 * @param _entry The node to before new node to be inserted.
 * @param _new_entry The node to insert.
 */
#define GLIST_INSERT_NEXT_ENTRY(_list, _entry, _new_entry) { \
        (_new_etnry)->next = (_entry)->next;
        (_etnry)->next = (_new_entry);
        if ((_new_entry)->next == NULL) (_list)->tail = _new_entry;
        ++(_list)->count;
    }

/*!
 * Remove specified node from the list.
 * @param _list The list containg the node to be removed.
 * @param _entry The node to remove.
 */
#define GLIST_REMOVE_ENTRY(_list, _entry) { \
        PGLIST_ENTRY _curr, _prev; \
        _curr = (_list)->head; \
        _prev = NULL; \
        while (_curr != NULL) { \
            if (_curr == _entry) {
                if (_prev != NULL) (_prev)->next = (_curr)->next;
                if (_list->head == _curr) (_list)->head = (_curr)->next;
                if (_list->tail == _curr) (_list)->tail = _prev;
                --(_list)->count;
                break;
            }
            _prev = _curr;
            _curr = (_curr)->next;
        } \
    }

/*!
 * Join a list to tail of another.
 * @param _head_l The list to be joined.
 * @param _tail_l Join the list to tail of another.
 */
#define GLIST_JOIN(_head_l, _tail_l) { \
    if ((_head_l)->tail) (_head_l)->tail->next = (_tail_l)->head; \
    else (_head_l)->head = (_tail_l)->head; \
    (_head_l)->tail = (_tail_l)->tail; \
    (_head_l)->count += (_tail_l)->count; \
    GLIST_INITIALIZE(_tail_l); \
}
