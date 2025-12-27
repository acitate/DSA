#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP
#include <vector>    

class PriorityQueue {
    private:
        int max_size;
        int size = 0;
        bool status;
        std::vector<double> items;

        void min_heapify(int index);
        void max_heapify(int index);
    public:
        PriorityQueue(int max_size, const std::vector<double>& items = {}, bool status = false);
        double get_item();
        int edit_item(double item, double new_item);
        int insert_item(double value);
        int remove_item();
};

#endif