#include "double_linked_list.h"

#include "tests/base/utils.h"

int test_dll_create_node() {
  dll_node_t nn = dll_create_node();
  if (!nn) {
    DEBUG_MSG("Null node");
    return 1;
  }
  if (nn->prev || nn->next) {
    return 1;
  }
  return 0;
}

int test_dll_create_list() {
  dll_t list = dll_create_list();
  if (!list) {
    DEBUG_MSG("Null list");
    return 1;
  }
  if (list -> front || list->back) {
    return 1;
  }
  return 0;
}
int test_dll_push_t1() {
  /*
  front
  NULL
  back

  push_back(list, n1)
     front, back
  NULL <= [n1] => NULL

  push_front(list, n2)
         front    back
  NULL <= [n2] <=> [n1] => NULL
  */
  dll_t list = dll_create_list();
  dll_node_t n1 = dll_create_node();
  dll_push_back(list, n1);
  if (list->front != n1 || list->back != n1) {
    DEBUG_MSG("push_back empty list");
    return 1;
  }
  dll_node_t n2 = dll_create_node();
  dll_push_front(list, n2);
  if (list->front != n2 || list->back != n1) {
    DEBUG_MSG("push_front 2 node");
    return 1;
  }
  dll_free_list(list);
  list = dll_create_list();
  n1 = dll_create_node();
  dll_push_front(list, n1);
  if (list->front != n1 || list->back != n1) {
    DEBUG_MSG("push_front empty list");
    return 1;
  }
  n2 = dll_create_node();
  dll_push_back(list, n2);
  if (list->front != n1 || list->back != n2) {
    DEBUG_MSG("push back 2 nodes");
    return 1;
  }
  return 0;
}

int main() {
  ASSERT(test_dll_create_node() == 0, "dll_create_node");
  ASSERT(test_dll_create_list() == 0, "dll_create_list");
  ASSERT(test_dll_push_t1() == 0, "dll_push_t1");
  return 0;
}