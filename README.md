# Brief
Basic implementaion of various data structures and algorithms in C++ and C, done as practice. **WIP**

## Test it!
1. Clone the repository.
```bash
git clone https://github.com/acitate/DSA.git
```
2. Change to root directory.
```bash
cd DSA
```
3. modify `main.cpp`. 
4. Build and run.
```bash
make
./output/main
```


## Todo
- [ ] Implement stack data structure.
  - [X] Define LLStack struct for linked list based implementation.
    - [X] Implement 'stack_ll_create' function.
    - [X] Implement 'stack_ll_push' function.
    - [X] Implement 'stack_ll_peek' function.
    - [X] Implement 'stack_ll_pop' function.
    - [ ] Implement 'stack_ll_is_empty' function.
    - [X] Implement 'stack_ll_size' function.
  
  - [ ] Define ArrayStack struct for array based implementation.
    - [ ] Implement 'stack_arr_create' function.
    - [ ] Implement 'stack_arr_push' function.
    - [ ] Implement 'stack_arr_peek' function.
    - [ ] Implement 'stack_arr_pop' function.
    - [ ] Implement 'stack_arr_is_empty' function.
    - [ ] Implement 'stack_arr_size' function.
  
- [ ] Implement queue data structure
  - [X]  Define LLQueue struct for linked list based implementation.
    - [X]  Implement 'queue_ll_create' function.
    - [X]  Implement 'queue_ll_enqueue' function.
    - [X]  Implement 'queue_ll_dequeue' function.
    - [ ]  Implement 'queue_ll_peek' function.
    - [ ]  Implement 'queue_ll_length' function.

  - [ ] Define ArrayQueue struct for array based implementation.
    - [ ]  Implement 'queue_arr_create' function.
      - [ ]  Implement 'queue_arr_enqueue' function.
      - [ ]  Implement 'queue_arr_dequeue' function.
      - [ ]  Implement 'queue_arr_peek' function.
      - [ ]  Implement 'queue_arr_length' function.


- [X] Define priority queue data structure.
  - [X] Implement 'min_heapify' function.
  - [X] Implement 'max_heapify' function.
  - [ ] Implement 'get_item' function.
  - [X] Implement 'insert_item' function.
  - [X] Implement 'remove_item' function.
  - [ ] Implement 'edit_item' function.
