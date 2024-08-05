#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits> // Include for numeric_limits

class Queue {
private:
    std::vector<std::string> queue;
    int max_size;

public:
    Queue(int size) : max_size(size) {}

    bool is_empty() const {
        return queue.empty();
    }

    bool is_full() const {
        return queue.size() == max_size;
    }

    void enqueue(const std::string& name) {
        if (is_full()) {
            std::cout << "Queue is full" << std::endl;
        } else {
            std::cout << "Queue before enqueue: ";
            display();
            queue.push_back(name);
            std::cout << "Enqueued: " << name << std::endl;
            std::cout << "Queue after enqueue: ";
            display();
        }
    }

    void dequeue() {
        if (is_empty()) {
            std::cout << "Queue is empty" << std::endl;
        } else {
            std::cout << "Queue before dequeue: ";
            display();
            std::string name = queue.front();
            queue.erase(queue.begin());
            std::cout << "Dequeued: " << name << std::endl;
            std::cout << "Queue after dequeue: ";
            display();
        }
    }

    std::string peek() const {
        if (is_empty()) {
            std::cout << "Queue is empty" << std::endl;
            return "";
        } else {
            return queue.front();
        }
    }

    void display() const {
        if (is_empty()) {
            std::cout << "Queue is empty" << std::endl;
        } else {
            std::cout << "Queue: ";
            for (const auto& name : queue) {
                std::cout << name << " ";
            }
            std::cout << std::endl;
        }
    }
};

void display_commands() {
    std::cout << "\nQueue Commands:" << std::endl;
    std::cout << "enqueue <name1> <name2> ... <nameN> - Add names to the queue" << std::endl;
    std::cout << "dequeue - Remove a name from the queue" << std::endl;
    std::cout << "peek - Show the front name of the queue" << std::endl;
    std::cout << "empty - Check if the queue is empty" << std::endl;
    std::cout << "full - Check if the queue is full" << std::endl;
    std::cout << "display - Display the queue" << std::endl;
    std::cout << "exit - Exit the program" << std::endl;
}

int main() {
    int max_size;
    std::cout << "Enter the maximum size of the queue: ";
    std::cin >> max_size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
    Queue q(max_size);

    display_commands();

    while (true) {
        std::string command;
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);
        std::istringstream iss(command);
        std::vector<std::string> parts;
        std::string part;
        while (iss >> part) {
            parts.push_back(part);
        }

        if (parts[0] == "enqueue" && parts.size() > 1) {
            for (size_t i = 1; i < parts.size(); ++i) {
                q.enqueue(parts[i]);
            }
        } else if (parts[0] == "dequeue") {
            q.dequeue();
        } else if (parts[0] == "peek") {
            std::string name = q.peek();
            if (!name.empty()) {
                std::cout << "Front name: " << name << std::endl;
            }
        } else if (parts[0] == "empty") {
            if (q.is_empty()) {
                std::cout << "Queue is empty" << std::endl;
            } else {
                std::cout << "Queue is not empty" << std::endl;
            }
        } else if (parts[0] == "full") {
            if (q.is_full()) {
                std::cout << "Queue is full" << std::endl;
            } else {
                std::cout << "Queue is not full" << std::endl;
            }
        } else if (parts[0] == "display") {
            q.display();
        } else if (parts[0] == "exit") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else {
            std::cout << "Invalid command, please try again." << std::endl;
            display_commands();
        }
    }

    return 0;
}
