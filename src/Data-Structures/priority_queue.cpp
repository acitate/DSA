#include <priority_queue.hpp>

using PQ = PriorityQueue;

void PQ::min_heapify(int index) {
    int left = 2*index, right = 2*index + 1;
    int heap_size = PQ::max_size;
    int smallest;

    if (left < heap_size && PQ::items[left] < PQ::items[index])
        smallest = left;
    else
        smallest = index;

    if (right < heap_size && PQ::items[right] < PQ::items[smallest])
        smallest = right;

    if (smallest != index) {
        double temp_item = PQ::items[index];
        PQ::items[index] = PQ::items[smallest];
        PQ::items[smallest] = temp_item;
        min_heapify(smallest);
    }
}

void PQ::max_heapify(int index) {
    int left = 2*index, right = 2*index + 1;
    int heap_size = PQ::max_size;
    int biggest;

    if (left < heap_size && PQ::items[left] > PQ::items[index])
        biggest = left;
    else
        biggest = index;

    if (right < heap_size && PQ::items[right] > PQ::items[biggest])
        biggest = right;

    if (biggest != index) {
        double temp_item = PQ::items[index];
        PQ::items[index] = PQ::items[biggest];
        PQ::items[biggest] = temp_item;
        max_heapify(biggest);
    }
}

PQ::PriorityQueue(int max_size, const std::vector<double> &items, bool status) {
    PQ::max_size = max_size;
    PQ::items.reserve(max_size);
    PQ::status = status;

    for (int i = 0; i < (int)(items.size()) && i < max_size; i++)
        PQ::items.push_back(items[i]);
}

double PQ::get_item() {
    if (PQ::size > 0)
        return PQ::items[0];
}

int PQ::edit_item(double item, double new_item) {
    return 0;
}

int PQ::insert_item(double value) {
    if (PQ::size < PQ::max_size) {
        PQ::items.push_back(value);
        PQ::size++;

        int index = PQ::size - 1;
        int parent = index / 2;
        while (parent >= 0 && (PQ::items[index] < PQ::items[parent] && !PQ::status) 
        || (PQ::items[index] > PQ::items[parent] && PQ::status)) {
            double temp_value = PQ::items[parent];
            PQ::items[parent] = PQ::items[index];
            PQ::items[index] = temp_value;
            index = parent;
            parent /= 2; 
        }
        return 1;
    }
    return 0;
}

int PQ::remove_item() {
    if (PQ::size > 0) {
        double temp_value = PQ::items[PQ::size - 1];
        PQ::items[PQ::size - 1] = PQ::items[0];
        PQ::items[0] = temp_value;
        PQ::size--;
        
        if (!PQ::status)
            min_heapify(0);
        else
            max_heapify(0);
        PQ::items.pop_back();
        
        return 1;
    }
    return 0;
}
